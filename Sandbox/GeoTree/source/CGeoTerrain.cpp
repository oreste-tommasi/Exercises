/****************************************************************************
* Copyright (c) 2011 GeoMind Srl. www.geomind.it
* All rights reserved.
*
*---------------------------------------------------------------------------
* This software is part of the GeoTree library by GeoMind Srl; 
* it is not allowed to use, copy, modify, merge, publish, distribute, 
* sublicense, and/or sell copies of software in parts or as a whole, 
* in source and binary forms, without a written permission of GeoMind Srl.
* 
****************************************************************************/ 

// System includes
#include "precompiled.h"


#include "CGeoTerrain.h"
#include "CRequestServer.h"
#include "CMeshTile.h"

int	CGeoTerrain::sGeoTerrainCounter = 0;

// ---------------------------------------------------------------------------
//	 CGeoTerrain
// ---------------------------------------------------------------------------
CGeoTerrain::CGeoTerrain()
{
	mTerrainId = sGeoTerrainCounter; // actually not mutex protected yet
	sGeoTerrainCounter++;
} 

// ---------------------------------------------------------------------------
//	 ~CGeoTerrain
// ---------------------------------------------------------------------------
CGeoTerrain::~CGeoTerrain()
{
	delete mBaseTiles;
} 

// ---------------------------------------------------------------------------
//	 CreateTileMap
// ---------------------------------------------------------------------------
CGeoTerrain::EErrorCode 
CGeoTerrain::CreateTileMap( int w, int h )
{
	delete mBaseTiles;

	mBaseTiles = new CTileMap( w, h );

	return mBaseTiles ? eNoError : eOutOfMemErr;
}

// ---------------------------------------------------------------------------
//	 SetupValidBaseTile
// ---------------------------------------------------------------------------
/**
 * Initializes a base tile assigning coord position, bounds, 
 * and posting the loading request
 *
 * \param x horizontal tile coord
 * \param y vertical tile coord
 *
 * \return error code
 **/
CGeoTerrain::EErrorCode  
CGeoTerrain::SetupValidBaseTile( int x, int y )
{
	if( !mBaseTiles || mBounds.Area()==0 || mBaseTiles->GetTile( x, y ) || !mDataServer )
		return eInitializationErr;

	if( x<0 || x>=mBaseTiles->Width() || y<0 || y>=mBaseTiles->Height() )
		return eBadInitParamErr;

	if( mBaseTiles->GetTile( x, y ) )
		return eConflictErr;

	CGeoTile*	newTile = new CMeshTile( this );

	GeoRect	r;
	GetBaseTileRect( x, y, r );
	
	newTile->SetupTile( 0, x, y, r );
	mBaseTiles->SetTile( newTile, x, y );

	return eNoError;
}


// ***** PRIVATE **************************************************************

// ---------------------------------------------------------------------------
//	 InitCommon
// ---------------------------------------------------------------------------
void CGeoTerrain::InitCommon()
{
	mBaseTiles = NULL;
	mDataServer = NULL;
}

// ---------------------------------------------------------------------------
//	 GetBaseTileRect
// ---------------------------------------------------------------------------
CGeoTerrain::EErrorCode 	
CGeoTerrain::GetBaseTileRect( int x, int y, GeoRect& outR )
{
	if( !mBaseTiles || mBounds.Area()==0 )
		return eInitializationErr;

	outR.left = mBounds.left + x * mBounds.Width() / mBaseTiles->Width();
	outR.right = mBounds.left + (x+1) * mBounds.Width() / mBaseTiles->Width();

	outR.SetNorth( mBounds.North() - y * mBounds.Height() / mBaseTiles->Height() );
	outR.SetNorth( mBounds.North() - (y+1) * mBounds.Height() / mBaseTiles->Height() );

	return eNoError;
}


// ***************************************************************************

// ---------------------------------------------------------------------------
//	 CTileMap
// ---------------------------------------------------------------------------
/** 
 * \brief	constructor
 *
 * creates a tile map with allocated buffer (everything set to NULL) * 
 * 
**/
CGeoTerrain::CTileMap::CTileMap( int w, int h )
: mWidth(0)
, mHeight(0)
{
	mMapPtr = NULL;

	Resize( w, h );
} 

// ---------------------------------------------------------------------------
//	 ~CTileMap
// ---------------------------------------------------------------------------
/** 
 * \brief	destructor
 *
**/
CGeoTerrain::CTileMap::~CTileMap()
{
	if( mMapPtr )
		delete [] mMapPtr;
} 

// ---------------------------------------------------------------------------
//	 CopyCreate
// ---------------------------------------------------------------------------
/** 
 * \brief	creates a blank copy with same size
 * 
**/
CGeoTerrain::CTileMap*
CGeoTerrain::CTileMap::CopyCreate()
{
	CTileMap	*outMap=NULL;

	try
	{
		outMap = new CTileMap( mWidth, mHeight );
	}
	catch(...)
	{
		outMap = NULL;
	}
	
	return outMap;
} 

// ---------------------------------------------------------------------------
//	 Resize
// ---------------------------------------------------------------------------
/** 
 * \brief	set tile map size
 *
 * resize (if needed) and reset (always) the tile map 
 * 
**/
void
CGeoTerrain::CTileMap::Resize( int w, int h )
{
	if( w!=mWidth || h!=mHeight )
	{
		if( mMapPtr )
			delete [] mMapPtr;

		mWidth = w;
		mHeight = h;

		mMapPtr = new CGeoTile*[w*h];
	}

	memset( mMapPtr, NULL, mWidth*mHeight*sizeof(CGeoTile*) );
} 

// ---------------------------------------------------------------------------
//	 GetTileVector
// ---------------------------------------------------------------------------
/** 
 * \brief	returns the tiles as a vector; only valid are considered
 *
 * outTiles:	output vector
 * 
**/
void
CGeoTerrain::CTileMap::GetTileVector( std::vector<CGeoTile*>& outTiles )
{
	int		totCount = mWidth*mHeight;
	CGeoTile**	ptr;
	CGeoTile**	endPtr = mMapPtr + totCount;

	outTiles.resize(0);
	outTiles.reserve( totCount );

	for( ptr = mMapPtr; ptr<endPtr; ptr++ )
	{
		if( (*ptr) )
			outTiles.push_back( (*ptr) );
	}
}
