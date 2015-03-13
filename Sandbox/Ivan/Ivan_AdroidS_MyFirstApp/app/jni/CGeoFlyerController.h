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

#ifndef	_CGeoFlyerController_H
#define	_CGeoFlyerController_H

#include "CGeoFlyerDelegate.h"
#include <vector>
#include <string>
#include <jni.h>


// --------------------------------------------------------------------------
//	 CGeoFlyerController
// --------------------------------------------------------------------------
/**
 *
**/
class CGeoFlyerController 
{
	
public:
				CGeoFlyerController( void* inJinEnv, void* inViewController );
	virtual	~CGeoFlyerController();
	
	void		MessageBox( const char* inTitle, const char* inMessage,
							   const std::vector< std::string >& inButtons,
							   CGeoFlyerDelegate* inDelegate, GfDelegateCallback inCallback ); // from 3D to view-controller
	
	void		OnMessageBoxResult( int inChoice ); // from view-controller to this (GeoFlyerCOntroller will call the inCallback of the inDelegate)	

private: 
	JavaVM*					mJvm;
	JNIEnv*					mJniEnv;
	jobject					mViewController;	//
	
	GfDelegateCallback	mDelegateCallback;
	CGeoFlyerDelegate*	mDelegate;  ///< passing delegate, varying from call to call,
												///< to be reset after the callback

	JNIEnv* GetJniEnv() { return mJniEnv; }
	JNIEnv* GetJniEnvThreadSafe();
	jobject GetViewController() { return mViewController; }

}; // class CGeoFlyerController


#endif  // _CGeoFlyerController_H
