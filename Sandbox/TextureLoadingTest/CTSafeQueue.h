/****************************************************************************
* Copyright (c) 2008 GeoMind Srl. www.geomind.it
* All rights reserved.
*
*---------------------------------------------------------------------------
* This software is part of the XXX PROJECT by GeoMind Srl; 
* it is not allowed to use, copy, modify, merge, publish, distribute, 
* sublicense, and/or sell copies of software in parts or as a whole, 
* in source and binary forms, without a written permission of GeoMind Srl.
* 
****************************************************************************/ 
 
#ifndef CTSAFEQUEUE_H
#define CTSAFEQUEUE_H 

// System includes
#include <list>
#include <algorithm>

// Project includes
#include "gmcuThread.h"
#include "CSem.h"
//#include "NavSemaphore.h"
//#include "NavScopedLock.h"

// Local includes

//#include "commonExce.h"

// forward declaration



namespace gmcu
{

// --------------------------------------------------------------------------
//	 CTSafeQueue
// --------------------------------------------------------------------------
/**
 * \brief		
**/	
template <class Type,  class Container = std::list<Type> >
class CTSafeQueue 
{
public:
	// types and constants
	typedef Type									value_type;
	typedef typename Container::size_type	size_type;
	typedef Container								container_type;


	// constructor and destructor
	CTSafeQueue();
	~CTSafeQueue();


	size_type											size();

	void													push_back( value_type inVal ); 
	template<class InIterator> void				push_back( InIterator inFirst, InIterator inLast );
	void													push_front( value_type inVal ); 

	value_type											blocking_pop_front();
	template<class OutIterator> void		 		blocking_pop_front( OutIterator inFirst, size_type inCount );
	bool													try_pop_front( value_type* outValue );
	template<class OutIterator> size_type		try_pop_front( OutIterator inFirst, size_type inCount );
	template<class OutContainer> size_type		try_pop_front( OutContainer* outFirst );

	template<class Predicate> bool				remove_if( value_type* outValue, Predicate inPred );
	template<class Predicate> bool				find_same( value_type inValue, Predicate inPred );
	template<class OutContainer, class Predicate> void				extract_if( OutContainer* outCont, Predicate inPred );

	void													clear(); 

	inline bool											remove( value_type seekValue );


protected:
	// types and constants

	// implementation data
	container_type				mContainer;			///<queued value container
	Mutex							mMutex;				///<it assures mutual exclusion
	CSem							mHoldSem;			///<states if the queue could contain some values. 


}; // CTSafeQueue




// INLINES 


// --------------------------------------------------------------------------
//	 CTSafeQueue
// --------------------------------------------------------------------------
/**
*
**/
template <class Type, class Container> inline
CTSafeQueue<Type, Container>::CTSafeQueue()
//: mMutex(NULL)
{
	ThreadMutexInit( &mMutex, NULL );
	mHoldSem.Init( 0 );
}

// --------------------------------------------------------------------------
//	 ~CTSafeQueue
// --------------------------------------------------------------------------
/**
* 
**/
template <class Type, class Container> inline
CTSafeQueue<Type, Container>::~CTSafeQueue()
{
	ThreadMutexDestroy( &mMutex );
//	mMutex = NULL;
	
	mHoldSem.Destroy();
}

// --------------------------------------------------------------------------
//	 size
// --------------------------------------------------------------------------
/**
* retrieves the queue size
*
* \return	the queue size
**/
template <class Type, class Container> 
inline typename CTSafeQueue<Type, Container>::size_type		
CTSafeQueue<Type, Container>::size()
{
	StMutexLock	 lockMutex( &mMutex );

	return mContainer.size();
}

// --------------------------------------------------------------------------
//	 push_back
// --------------------------------------------------------------------------
/**
* add inVal to queue
**/
template <class Type, class Container> inline void		
CTSafeQueue<Type, Container>::push_back( value_type inVal )
{
	StMutexLock	 lockMutex( &mMutex );

	mContainer.push_back( inVal );

	//int	prevValue = mHoldSem.GetValue();

	mHoldSem.Post();

	//int	theValue = mHoldSem.GetValue();

	//gmcu::PrintMessage( "CTSafeQueue::push_back: sem prevValue=%ld afterValue=%ld\r\n", prevValue, theValue );
}

// --------------------------------------------------------------------------
//	 push_back
// --------------------------------------------------------------------------
/**
* add a range of values to the queue
**/
template <class Type, class Container>
template <class InIterator> 
inline void
CTSafeQueue<Type, Container>::push_back( InIterator inFirst, InIterator inLast )
{
	StMutexLock	 lockMutex( &mMutex );

	for( InIterator it= inFirst; it!= inLast; ++it )
	{
		mContainer.push_back( *it );
		mHoldSem.Post();
	}
}

// --------------------------------------------------------------------------
//	 push_front
// --------------------------------------------------------------------------
/**
* add inVal to queue
**/
template <class Type, class Container> inline void		
CTSafeQueue<Type, Container>::push_front( value_type inVal )
{
	StMutexLock	 lockMutex( &mMutex );

	mContainer.push_front( inVal );
	mHoldSem.Post();
}

// --------------------------------------------------------------------------
//	 blocking_pop_front
// --------------------------------------------------------------------------
/**
* it extracts an element from the queue front; the calling thread remains
* blocked until there is no item in the queue
**/
template <class Type, class Container> 
inline typename CTSafeQueue<Type, Container>::value_type
CTSafeQueue<Type, Container>::blocking_pop_front()
{
	mHoldSem.Wait(); 
	
	{
		StMutexLock	 lockMutex( &mMutex );

		value_type retval = mContainer.front();
		mContainer.pop_front();

		//gmcu::PrintMessage( "CTSafeQueue::blocking_pop_front ok\r\n" );
		
		return retval;
	}
}

// --------------------------------------------------------------------------
//	 blocking_pop_front
// --------------------------------------------------------------------------
/**
* extracts exactly inCount elements from the queue front; the calling thread remains
* blocked until inCount elements are retrieved; 
* there must be sufficient space at the destination to hold all the elements being copied.
**/
template <class Type, class Container> 	
template <class OutIterator> 
inline void		
CTSafeQueue<Type, Container>::blocking_pop_front( OutIterator inFirst, size_type inCount )
{
	if( inCount == 0 )
		return;

	for( size_type i= 0; i<inCount; ++i )
		mHoldSem.Wait(); 

	StMutexLock	 lockMutex( &mMutex );

	typename Container::iterator onePastLast = mContainer.begin();
	for( size_type i= 0; i<inCount; ++i )
		*inFirst++ = *onePastLast++;

	mContainer.erase( mContainer.begin(), onePastLast );
}

// --------------------------------------------------------------------------
//	 try_pop_front
// --------------------------------------------------------------------------
/**
* tries to extract an element from the queue front; if there is no element
* in the queue, the calling thread is not blocked, the function exit without retrieving any value
*
* \return true if an element has been retrieved, false otherwise
**/
template <class Type, class Container> inline bool		
CTSafeQueue<Type, Container>::try_pop_front( value_type* outValue )
{
	if( mHoldSem.TryWait() )
	{
		StMutexLock	 lockMutex( &mMutex );

		if( mContainer.size() )
		{
			//gmcu::PrintMessage( "CTSafeQueue::try_pop_front ok\r\n" );

			*outValue = mContainer.front();
			mContainer.pop_front();

			return true;
		}
		else 
			return false;
	}
	else
		return false;
}

// --------------------------------------------------------------------------
//	 try_pop_front
// --------------------------------------------------------------------------
/**
* tries to extract inCount elements from the queue front; if there are not enough elements
* in the queue, the calling thread is not blocked; 
* there must be sufficient space at the destination to hold all the elements being copied.
*
* \return	the number of elements retrieved.
**/
template <class Type, class Container> 
template <class OutIterator> 
inline typename CTSafeQueue<Type, Container>::size_type
CTSafeQueue<Type, Container>::try_pop_front( OutIterator inFirst, size_type inCount )
{
	if( inCount == 0 )
		return 0;

	size_type availCount = 0;

	while( availCount<inCount && mHoldSem.TryWait() )
		availCount++;

	StMutexLock	 lockMutex( &mMutex );

	typename Container::iterator onePastLast = mContainer.begin();
	for( size_type i= 0; i<availCount; ++i )
		*inFirst++ = *onePastLast++;

	mContainer.erase( mContainer.begin(), onePastLast );

	return availCount;
}

// --------------------------------------------------------------------------
//	 try_pop_front
// --------------------------------------------------------------------------
/**
* it extracts every element from the queue and appends them at the 
* end of outContainer; outContainer will be resized to contains all the elements.
**/
template <class Type, class Container> 
template <class OutContainer> 
inline typename CTSafeQueue<Type, Container>::size_type		
CTSafeQueue<Type, Container>::try_pop_front( OutContainer* outContainer )
{
	size_type availCount = 0;

	while( mHoldSem.TryWait() )
		availCount++;

	StMutexLock	 lockMutex( &mMutex );

	typename Container::iterator onePastLast = mContainer.begin();
	for( size_type i= 0; i<availCount; ++i )
		outContainer->push_back( *onePastLast++ );

	mContainer.erase( mContainer.begin(), onePastLast );

	return availCount;
};

// --------------------------------------------------------------------------
//	 remove
// --------------------------------------------------------------------------
/**
* extracts exactly inCount elements from the queue front; the calling thread remains
* blocked until inCount elements are retrieved; 
* there must be sufficient space at the destination to hold all the elements being copied.
**/
template <class Type, class Container> inline bool
CTSafeQueue<Type, Container>::remove( value_type inSeekValue )
{
	StMutexLock	 lockMutex( &mMutex );
	bool			 found = false;
	
	typename Container::iterator theIter;
		
	theIter = find( mContainer.begin(), mContainer.end(), inSeekValue );
	
	if( theIter!=mContainer.end() )
	{
		mContainer.erase( theIter );
		found = true;

		/*if( !*/mHoldSem.TryWait(); /*)
			long b=0;*/ /// there was an error
	}

	return found;
};

// --------------------------------------------------------------------------
//	 clear
// --------------------------------------------------------------------------
/**
* empties the queue
**/
template <class Type, class Container> inline void		
CTSafeQueue<Type, Container>::clear()
{
	size_type availCount = 0;

	while( mHoldSem.TryWait() )
		availCount++;
	
	StMutexLock	 lockMutex( &mMutex );
	
	typename Container::iterator onePastLast = mContainer.begin();
	for( size_type i= 0; i<availCount; ++i )
		onePastLast++;

	mContainer.erase( mContainer.begin(), onePastLast );
}

// --------------------------------------------------------------------------
//	 find_same
// --------------------------------------------------------------------------
/**
* find an element according to a specified condition
*
* \return	true if found.
**/
template <class Type, class Container> 
template<class Predicate> inline bool
CTSafeQueue<Type, Container>::find_same( value_type inValue, Predicate inPred )
{
	StMutexLock	 lockMutex( &mMutex );

	if( mContainer.size() )
	{
		typename Container::iterator it = find_if( mContainer.begin(), mContainer.end(), inPred );

		return it != mContainer.end();
	}
	else
		return false;
}

// --------------------------------------------------------------------------
//	 remove_if
// --------------------------------------------------------------------------
/**
* it extracts an element from the queue according to a specified condition
*
* \return	success value.
**/
template <class Type, class Container> 
template<class Predicate> inline bool
CTSafeQueue<Type, Container>::remove_if( value_type* outValue, Predicate inPred )
{
	StMutexLock	 lockMutex( &mMutex );

	if( mContainer.size() )
	{
		typename Container::iterator it = find_if( mContainer.begin(), mContainer.end(), inPred );

		if( it != mContainer.end() )
		{
			*outValue = *it;
			mContainer.erase( it );

			return true;
		}
		else
		{
			*outValue = 0;
			mHoldSem.Post();

			return false;
		}
	}
	else
		return false;
}

// --------------------------------------------------------------------------
//	 extract_if
// --------------------------------------------------------------------------
/**
* it extracts all the elements satisfying the predicate.
*
* \return	success value.
**/
template <class Type, class Container> 
template<class OutContainer, class Predicate> inline void
CTSafeQueue<Type, Container>::extract_if( OutContainer* outCont, Predicate inPred )
{
	StMutexLock	 lockMutex( &mMutex );

	typename Container::iterator it = mContainer.begin();

	while( it !=  mContainer.end() )
	{
		it = find_if( it, mContainer.end(), inPred );

		if( it != mContainer.end() )
		{
			if( mHoldSem.TryWait() )
			{
				outCont->push_back( *it );
				it = mContainer.erase( it );
			}
			else
				return;
		}
	}
}


} // namespace gmcu

#endif // CTSAFEQUEUE_H




