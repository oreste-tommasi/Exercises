#pragma once
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

#ifndef	CGeoTerrain_h
#define	CGeoTerrain_h

#include "CPoints3d.h"

// ==========================================================================
//	 CGeoTerrain
// ==========================================================================
/**
 * \brief	terrain object
 *
 * \internal
 **/


// forward declaration
class CGeoTile;


class CGeoTerrain
{
public:
	enum EErrorCode
	{
		eNoError=0,
		eInitializationErr,	///< not all structures have been set or created
		eOutOfMemErr,
		eBadInitParamErr		///< incompatibility with some init param
	};

							CGeoTerrain();
	virtual				~CGeoTerrain();

	// --- initialization
	void					SetBounds( const GeoRect& inR ){ mBounds=inR; }
	EErrorCode			CreateTileMap( int w, int h );
	EErrorCode			SetValidBaseTile( int x, int y );


protected:
	GeoRect				mBounds;	///< in world geographic coords

	// ---------------------------------------------------------------------------
	//	 CTileMap internal class
	// ---------------------------------------------------------------------------
	class CTileMap
	{
	public:
								CTileMap( int w, int h );
								~CTileMap();

		CTileMap*			CopyCreate();

		inline CGeoTile*	GetTile( int x, int y );
		void					SetTile( CGeoTile* inTile, int x, int y ){ mMapPtr[x + y*mWidth]=inTile; };

		void					Resize( int w, int h );

		int					Width(){ return mWidth; };
		int					Height(){ return mHeight; };

		void					GetTileVector( std::vector<CGeoTile*>& outTiles );

	protected:
		int					mWidth, mHeight;
		CGeoTile**			mMapPtr;
	};

	CTileMap*			mBaseTiles;

	EErrorCode			GetBaseTileRect( int x, int y, GeoRect& outR );

private:
	void					InitCommon();

}; // class CGeoTerrain

// ---------------------------------------------------------------------------
//	 GetTileBoundsDataset
// ---------------------------------------------------------------------------
/**
 * \brief	retrieves the tile bounds in dataset coords
 *
**/


#endif  // CGeoTerrain_h
