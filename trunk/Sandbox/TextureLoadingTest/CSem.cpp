/****************************************************************************
 * Copyright (c) 2006 GeoMind Srl. www.geomind.it
 * All rights reserved.
 *
 *---------------------------------------------------------------------------
 * This software is part of the GMCommonUtility PROJECT by GeoMind Srl; 
 * it is not allowed to use, copy, modify, merge, publish, distribute, 
 * sublicense, and/or sell copies of software in parts or as a whole, 
 * in source and binary forms, without a written permission of GeoMind Srl.
 * 
 ****************************************************************************/ 

// System includes
//#include "precompiled.h"
// #ifdef _WIN32
// #include <Windows.h>
// #endif

#include "pthread.h"
#include <stdio.h>
#include <errno.h>

// Project includes

// Local includes
#include "CSem.h"

// Forward References

// Extern definitions



namespace gmcu
{


#if defined( __APPLE__ )
	pthread_mutex_t		CSem::sNameMutex;
	int						CSem::sNameMutexInitRetval = pthread_mutex_init(&sNameMutex, 0);
	unsigned					CSem::sNameCount = 0;
#endif


// --------------------------------------------------------------------------
//	 CSem
// --------------------------------------------------------------------------
/**
 * \brief	Constructor
**/
CSem::CSem()
: mMySem( 0 )
{
}

// --------------------------------------------------------------------------
//	 ~CSem
// --------------------------------------------------------------------------
/**
 * \brief	Destructor
**/
CSem::~CSem()
{
	Destroy();
}

// --------------------------------------------------------------------------
//	 Init
// --------------------------------------------------------------------------
/**
 * \brief	Create and initialize the semaphore
**/
int	
CSem::Init( unsigned int inValue /*, const std::string& inName = ""*/ )
{
#if defined( WIN32 ) || defined( __linux__ )

	mMySem = new sem_t;
	int retval = sem_init( mMySem, 0, inValue ); 

	if( retval != 0 )
	{
		delete mMySem;
		mMySem = 0;
	}

	return retval;

#elif defined( __APPLE__ )

//#	undef max
	static const int kMaxAttempt = 5;
	for( int i =0; i< kMaxAttempt; ++i )
	{
		std::string semName = GenSemName();
		if( semName == "" )
			return -1;

		mMySem = sem_open( semName.c_str(), O_CREAT | O_EXCL, 0, inValue );	// \todo to be verified: permission can be 0. try 0006
				
		if( mMySem != SEM_FAILED )
		{
			if( 0 != sem_unlink(semName.c_str()) )
			{
				mMySem = 0;
				return -1;
			}
			else
				return 0;
		}
		else if( errno != EEXIST )
		{
			mMySem = 0;
			//return -1;
		}
	}

	return -1;

#endif
}

// --------------------------------------------------------------------------
//	 Destroy
// --------------------------------------------------------------------------
/**
 * \brief	
**/
int	
CSem::Destroy()
{
int retval = -1;

	errno = EINVAL;
#if defined( WIN32 ) || defined( __linux__ )
		if( mMySem )
	{
		retval = sem_destroy( mMySem );
		delete mMySem;
	}
#elif defined( __APPLE__ )

	if( mMySem )
		retval = sem_close( mMySem );
#endif
	mMySem = 0;
	return retval;
}

// --------------------------------------------------------------------------
//	 Wait
// --------------------------------------------------------------------------
/**
 * \brief	
**/
bool	
CSem::Wait( unsigned int inTimeWait/*=0*/ )
{
	if( !mMySem )
		return false;

	if( 0==inTimeWait )
		return 0==sem_wait( mMySem );
	else
#ifdef __APPLE__
		return false;
#else
	{
		timespec		theTime;
		
		theTime.tv_sec = (long) time( NULL ) + inTimeWait /1000;
		theTime.tv_nsec = ( inTimeWait % 1000 ) *1000000;

		return 0==sem_timedwait( mMySem, &theTime );
	}
#endif
}

// --------------------------------------------------------------------------
//	 TryWait
// --------------------------------------------------------------------------
/**
 * \brief	
**/
bool	
CSem::TryWait()
{
	if( mMySem )
		return 0==sem_trywait( mMySem );
	else
		return false;
}

// --------------------------------------------------------------------------
//	 Post
// --------------------------------------------------------------------------
/**
 * \brief	
**/
bool	
CSem::Post()
{
	if( mMySem )
		return 0==sem_post( mMySem );
	else
		return false;
}

// --------------------------------------------------------------------------
//	 GetValue
// --------------------------------------------------------------------------
/**
* \brief	
**/
int	
CSem::GetValue()
{
	int	outVal=-1;

	if( mMySem )
		outVal = sem_getvalue( mMySem, &outVal );

	return outVal;
}

// --------------------------------------------------------------------------
//	 GenSemName
// --------------------------------------------------------------------------
/**
 * \brief	
**/
#if defined( __APPLE__ )

std::string		
CSem::GenSemName()
{
	if( sNameMutexInitRetval != 0 )	
		return "";			

	if( 0 != pthread_mutex_lock( &sNameMutex ) )
		return "";			

	// try tmpnam
	static const int kNameSize = std::max( L_tmpnam, 1024 );
	char fileName[kNameSize];

	char* tmpnamRetval = tmpnam(fileName);

	if( tmpnamRetval )
	{
		pthread_mutex_unlock( &sNameMutex );
		return fileName;
	}

	// try thread id plus counter
	sprintf( fileName, "gmcu_sem_%d_%d", int(getpid()), sNameCount );
	++sNameCount;
	
	pthread_mutex_unlock( &sNameMutex );
	return fileName;
}

#endif
	


} // namespace gmcu
