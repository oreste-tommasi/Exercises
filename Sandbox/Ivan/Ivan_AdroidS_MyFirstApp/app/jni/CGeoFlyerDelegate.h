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

#ifndef	_CGeoFlyerDelegate_H
#define	_CGeoFlyerDelegate_H


// --------------------------------------------------------------------------
//	 CGeoFlyerDelegate
// --------------------------------------------------------------------------
/**
 *
**/

class CGeoFlyerDelegate 
{
	virtual int		GetId() const { return mId; }

protected:
	virtual ~CGeoFlyerDelegate(){};

	int	  mId;
}; // class CGeoFlyerDelegate

typedef void	(*GfDelegateCallback)( CGeoFlyerDelegate* This, void* inData );


#endif  // _CGeoFlyerDelegate_H
