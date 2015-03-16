#pragma once

/****************************************************************************
 * Copyright (c) 2013 GeoMind Srl. www.geomind.it
 * All rights reserved.
 *
 *---------------------------------------------------------------------------
 * This software is part of the GeoFlyerPro PROJECT by GeoMind Srl;
 * it is not allowed to use, copy, modify, merge, publish, distribute,
 * sublicense, and/or sell copies of software in parts or as a whole,
 * in source and binary forms, without a written permission of GeoMind Srl.
 *
 ****************************************************************************/

#ifndef	_CFuffaDelegate_H
#define	_CFuffaDelegate_H

#include "CGeoFlyerDelegate.h"


// --------------------------------------------------------------------------
//	 CFuffaDelegate
// --------------------------------------------------------------------------
/**
 *
**/

class CFuffaDelegate : public CGeoFlyerDelegate
{
public:
	static void callback( CGeoFlyerDelegate* This, void* inData )
	{
		int gg = 0;
	}

}; 


#endif  // _CFuffaDelegate_H
