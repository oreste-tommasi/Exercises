#pragma once
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

#ifndef	GMCU_THREAD_H
#define	GMCU_THREAD_H

// System includes
extern "C"
{
#include "pthread.h"
#include "semaphore.h"
#include "signal.h"
}
// Project includes

// Local includes
//#include "CSem.h"

// Forward References

// Extern definitions



namespace gmcu
{

/****************************************************************************
  TYPEDEF
 ****************************************************************************/

typedef	pthread_t				Thread;

typedef	pthread_mutex_t		Mutex;
	
typedef	sem_t						Sem;



/****************************************************************************
  Defines
 ****************************************************************************/



/****************************************************************************
  FUNCTIONS
 ****************************************************************************/

// mutex
#define	ThreadMutexInit( inMutexPtr, inVal)		pthread_mutex_init( inMutexPtr, inVal )
#define	ThreadMutexDestroy( inMutexPtr )			pthread_mutex_destroy( inMutexPtr )

// init Recursive mutex
static inline int ThreadMutexInitRecursive( Mutex* ioMutexPtr )
{
	pthread_mutexattr_t a;
	pthread_mutexattr_init( &a );
	pthread_mutexattr_settype( &a, PTHREAD_MUTEX_RECURSIVE );
	int ret = pthread_mutex_init( ioMutexPtr, &a );
	pthread_mutexattr_destroy(&a);

	return ret;
}
#define ThreadMutexTryLock( inMutexPtr )				pthread_mutex_trylock( inMutexPtr )/*returns 0 if SUCCESFUL*/
#define ThreadMutexLock( inMutexPtr )				pthread_mutex_lock( inMutexPtr )
#define	ThreadMutexUnlock( inMutexPtr )			pthread_mutex_unlock( inMutexPtr )

/* Place holder for thread synchronization lock */
class StMutexLock
{   public:
        StMutexLock( Mutex* m ) : mutex(m) 
											{ 
												if( mutex )
													ThreadMutexLock(mutex); 
											};

        ~StMutexLock() 
			{ 
				if(mutex) 
					ThreadMutexUnlock(mutex); 
			};

    private:
        Mutex* mutex;
};

// semaphores
#define	SemInit( inSemPtr, inShared, inVal)			sem_init( inSemPtr, inShared, inVal )
//#define	SemInit( inSemPtr, inShared, inVal)		inSemPtr = sem_open(NULL, O_CREAT)//( inSemPtr, inShared, inVal )
#define	SemDestroy( inSemPtr )						sem_destroy( inSemPtr )

#define	SemPost( inSemPtr )							sem_post( inSemPtr )
#define	SemWait( inSemPtr )							sem_wait( inSemPtr )
#define	SemTryWait( inSemPtr )						sem_trywait( inSemPtr )


// threads
#define	ThreadCreate( inThreadPtr, inAttr, inStartFunc, inArg )		pthread_create( inThreadPtr, inAttr, inStartFunc, inArg )

#define	ThreadKill( inThreadPtr, inSignal )		pthread_kill( inThreadPtr, inSignal )
#define	ThreadJoin( inThreadPtr, outValPtr )	pthread_join( inThreadPtr, outValPtr )
#define	ThreadSelf(  )									pthread_self(  )


int		ThreadSetPriority( Thread inThread, int inPolicy, int inPriority );


// sleep
#ifndef WIN32
#define	Sleep( inMilliSec )							usleep( inMilliSec * 1000 )
#endif




} // namespace gmcu


#endif // GMCU_THREAD_H





