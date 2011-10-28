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

#ifndef	GMCU_CSem_H
#define	GMCU_CSem_H

// System includes
#include <semaphore.h>
#include <string>

// Project includes

// Local includes

// Forward References

// Extern definitions



namespace gmcu
{


// --------------------------------------------------------------------------
//	 CSem
// --------------------------------------------------------------------------
/**
* \brief	
**/
class CSem 
{
public:
	// constructors
	CSem();
	~CSem();

	int	Init( unsigned int inValue /*, const std::string& inName = ""*/ );
	int	Destroy();
	
	bool	Wait( unsigned int inTimeWait=0 );	  ///< time is in ms; 0 means no timeout; returns true if successfull
	bool	TryWait(); ///< returns true if found something
	bool	Post();	  ///< returns true if successfull
	int	GetValue();	  

private:
	sem_t*		mMySem;

#if defined( __APPLE__ )
	static pthread_mutex_t	sNameMutex;
	static int					sNameMutexInitRetval;
	static unsigned			sNameCount;

	static std::string		GenSemName();
#endif

	
}; // class CSem 





// Inlines




} // namespace gmcu

#endif  // GMCU_CSem_H

