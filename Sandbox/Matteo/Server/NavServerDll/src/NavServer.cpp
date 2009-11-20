// Simple test of the NavServerDll.

// system includes
#include <iostream>
#include <cmath>
#include <cstring>

// project includes
#include "NavServer.h"


// private output functions

using namespace std;


// ---------------------------------------------------------------------------
//	NServ_GetImage
// ---------------------------------------------------------------------------
/**
* \brief NavServer initialization
*
* This function performs the ....
*
* \return	Error code : 
*				kNSerErr_NoErr		if successful;
*
**/
NavServerError	
NServ_Init( )
{

	return kNSerErr_NoErr;
}


// ---------------------------------------------------------------------------
//	NServ_GetImage
// ---------------------------------------------------------------------------
/**
* \brief Draw Navionics chart
*
* This function performs the ....
*
* \param		inRect	is the geographic bounds to draw.
* \param		outImage	is the returned image.
*
* \return	Error code : 
*				kNSerErr_NoErr			if successful;
*				kNSerErr_OutOfMemory	if there is no memory to allocate a session;	
*				kNSerErr_BadArgs		if input args are wrong;
*
**/
NavServerError	
NServ_GetImage( NGeoRect inRect, NImage* outImage )
{
	// check errors
	if( outImage->mChannelCount != 4   ||
		 outImage->mSize.mWidth  > 1024 ||
		 outImage->mSize.mHeight > 1024 )
		return kNSerErr_BadArgs;

	if ( 0 == outImage->mBuffer )
		return kNSerErr_OutOfMemory;
	

#ifndef	NSERV_EXAMPLE // temporary
	unsigned int	col = ( (int)(( inRect.mEast + inRect.mSouth )/2) ) | 0xff000000;
	unsigned			x, y;
	unsigned int*	buffer = (unsigned int*)outImage->mBuffer; 

	for ( y=0; y<outImage->mSize.mHeight; ++y)
	{
		if ( 0==(y%32) )
			col = (~col | 0xff000000 );

		for ( x=0; x<outImage->mSize.mWidth; ++x )
		{
			if ( 0==(x%32) )
				col = (~col | 0xff000000 );
			buffer[x+y*outImage->mSize.mWidth] = col;
		}
	}

#endif

	return kNSerErr_NoErr;
}

