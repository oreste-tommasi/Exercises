// Simple test of the NavServerDll.

// system includes
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>

// project includes
#include "NavServer.h"

// SmartSDK
#include "NavChart.h"
#include "NavDraw.h"
#include "NavEnums.h"
#include "NavScopedLock.h"
#include "NavPath.h"
using namespace Navionics;


// private output functions

using namespace std;

// Globals   ==================================================================================
Navionics::NavContext*		gNavContext = 0;
Navionics::NavDraw*			gNavDraw = 0;
static const int				sNavSize = 512;
Navionics::NavMutex			gMutex;

void	Convert16To32( unsigned short* srcBuff, NImage* destImg );

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
NServ_Init( const char* configurationFile )
{
#ifdef NSERV_EXAMPLE 
	
	return kNSerErr_NoErr;
#else
	NavScopedLock	waitFor( gMutex ); 
	NavPath			path( configurationFile );
	NavString		dbgPath = path.GetPath();
	dbgPath.append( "dbg_init.txt" );

	ofstream			dbg;
	dbg.open( dbgPath.c_str(), ios_base::out );

	// cleanup
	if ( gNavContext )
		delete gNavContext;
	if ( gNavDraw )
		delete gNavDraw;
	//NavChart::GetInstance()->ReleaseChart();

	gNavContext = new NavContext( sNavSize, sNavSize );
	gNavDraw = new NavDraw( *gNavContext, false, false, 100, NavDraw::NORMAL_ZOOM );

	NavServerError		err = kNSerErr_NoErr;
	ifstream				fin( configurationFile );
	NavString			keyStr, fileName;
	unsigned char		key[33];

	dbg << "* ConfigurationFile  " << configurationFile << endl << endl;

	while( fin >> keyStr )
	{
		fin >> fileName;
		unsigned int len = (keyStr.size()<32)?keyStr.size():32;
		if ( len < 20 )
		{
			int diff = 20-len;
			for ( int i=0; i<20; ++i )
			{
				if ( i<diff )
					key[i] = ' ';
				else
					key[i] = keyStr[i-diff];
			}
			len = 20;
		}
		else
			memcpy( key, keyStr.c_str(), len );

		key[len] = '\0';
		dbg << "Key   :" << key << endl;
		dbg << "File  :" << fileName << endl;
		if ( ! NavChart::GetInstance()->AddKey( key, len ) )
		{
			err += kNSerErr_FileNotFound;
			dbg << "ERR - Could not add key" << endl;
		}
		if ( 0 > NavChart::GetInstance()->AddChart( *gNavContext, fileName ) )
		{
			err += kNSerErr_FileNotFound; 
			dbg << "ERR - Could not add chart" << endl;
		}
	}
		
	dbg.flush();
	return err;

#endif
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
		 outImage->mSize.mWidth  > sNavSize ||
		 outImage->mSize.mHeight > sNavSize )
		return kNSerErr_BadArgs;

	if ( 0 == outImage->mBuffer )
		return kNSerErr_OutOfMemory;
	

#ifdef	NSERV_EXAMPLE // temporary
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
#else

#ifdef _DEBUG
	ofstream			dbg;
	dbg.open( "C:\\NAV\\dbg_getimage.txt", ios_base::out | ios_base::app);

	dbg.precision(2);
	dbg.setf( ios::fixed, ios::floatfield);
	dbg << endl << "Rect  W: " << inRect.mWest << " S: " << inRect.mSouth << endl
		      << "      E: "  << inRect.mEast << " N: " << inRect.mNorth << endl;
#endif

	NavScopedLock	waitFor( gMutex ); 

	int		south = (int)(inRect.mSouth+.5);
	int		east = (int)(inRect.mEast+.5);
	double	scale;

	if ( outImage->mSize.mWidth != sNavSize )
	{
		scale = (inRect.mEast - inRect.mWest)/outImage->mSize.mWidth;
		east = (int)(inRect.mWest + scale*sNavSize + 0.5 );
	}

	if ( outImage->mSize.mHeight != sNavSize )
	{
		scale = (inRect.mNorth - inRect.mSouth)/outImage->mSize.mHeight;
		south = (int)(inRect.mNorth - scale*sNavSize + 0.5 );
	}

	if ( ! gNavDraw->SelectMaps( (int)(inRect.mWest+0.5), south, east, (int)(inRect.mNorth+0.5) ) )
		return kNSerErr_OutBounds;
	
	if ( ! gNavDraw->DrawMaps( NavDraw::EVERYTHING, false, true ) )
		return kNSerErr_Error;

	Convert16To32( gNavDraw->GetImage()->mColorPtr, outImage );
#endif
	

	return kNSerErr_NoErr;
}

#define	RED_565MASK			0xf800
#define	GREEN_565MASK		0x07e0
#define	BLUE_565MASK		0x001f

void	
Convert16To32( unsigned short* srcBuff, NImage* destImg )
{
	unsigned int*		buffer32 = (unsigned int*)destImg->mBuffer; 
	unsigned short*	buffer16 = (unsigned short*)srcBuff; 
	unsigned int		col16, col32;

	for ( unsigned int y=0; y<destImg->mSize.mHeight; ++y )
		for ( unsigned int x=0; x<destImg->mSize.mWidth; ++x )
		{
			col16 =  buffer16[x+y*sNavSize];

			col32 = ((col16 & RED_565MASK)>>(5+3)) |
						((col16 & GREEN_565MASK)<<(3+2)) |
						((col16 & BLUE_565MASK)<<(24-5)) |
						0xff000000;

			buffer32[ x+y*destImg->mSize.mWidth ] = col32;
		}
}


