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
//#include "precompiled.h"


#include "gmcuThread.h"


namespace gmcu
{


/* to be redefined if not using pthread.h */
int		
ThreadSetPriority( Thread inThread, int inPolicy, int inPriority )
{
	struct sched_param	sParam;
	int						threadPolicy;
	int						err = 0;

	err = pthread_getschedparam( inThread, &threadPolicy, &sParam);
	if ( err )
		return err;
#ifndef WIN32
	inPriority = sched_get_priority_min(inPolicy) + ( sched_get_priority_max(inPolicy) - sched_get_priority_min(inPolicy) ) * (inPriority + 2) / 4;
#endif	
	sParam.sched_priority = inPriority;

	err = pthread_setschedparam( inThread, inPolicy, &sParam);
	if ( err )
		return err;

	return err;
}


} // namespace gmcu
