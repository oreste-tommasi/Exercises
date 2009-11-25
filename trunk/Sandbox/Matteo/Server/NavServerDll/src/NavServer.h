/****************************************************************************
* Copyright (c) 2007 GeoMind Srl.
* All rights reserved.
*
*---------------------------------------------------------------------------
* This software is part of the 3D Data Session library by GeoMind Srl; 
* it is not allowed to use, copy, modify, merge, publish, distribute, 
* sublicense, and/or sell copies of software including the DAM library, 
* in parts or as a whole, in source and binary forms,
* without a written permission of GeoMind Srl.
****************************************************************************/ 


// ==========================================================================
//	NavServer.h
// ==========================================================================
//

#ifndef	NAVSERVER_H
#define	NAVSERVER_H

// System includes

// Project includes

// Local includes

// Forward References

// extern "C"
#ifdef __cplusplus
extern "C"
{
#endif

// dll export section
#ifdef NSERV_EXPORTS
	#define NSERV_API __declspec(dllexport)
#else
	#ifndef __linux__
		#define NSERV_API __declspec(dllimport)
	#else
		#define NSERV_API 
	#endif
#endif

// Forward declarations
namespace Navionics 
{
	class NavContext;
	class NavDraw;
}

// Defines ====================================================================================
#define		NAVSERVER_VERSION						"NSERV000r0" 

// Error codes																		
#define kNSerErr_NoErr						0
#define kNSerErr_Error						-1
#define kNSerErr_OutOfMemory				-2
#define kNSerErr_BadArgs					-3
#define kNSerErr_OutBounds					-4
#define kNSerErr_FileNotFound				-5


// Typedefs ===================================================================================
typedef	long				NavServerError;	///< error code

typedef struct _NSize
{
	unsigned int	mWidth;
	unsigned int	mHeight;
} NSize;

typedef struct _NGeoRect
{
	double	mWest;
	double	mSouth;
	double	mEast;
	double	mNorth;
} NGeoRect;

typedef struct _NImage
{
	NSize				mSize;
	unsigned int	mChannelCount;
	unsigned char*	mBuffer;
} NImage;




// Functions ==================================================================================

// initialization 
NSERV_API NavServerError	NServ_Init( const char* configurationFile );

// image functions
NSERV_API NavServerError	NServ_GetImage( NGeoRect inRect, NImage* outImage );


#ifdef __cplusplus
}
#endif
// extern "C"

#endif // NAVSERVER_H
