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

#ifndef	CGeoTile_h
#define	CGeoTile_h


#include "CPoints3d.h"

// ==========================================================================
//	 CGeoTile
// ==========================================================================
/**
 * \brief	unitary terrain object
 *
 * \internal
 **/


// forward declaration
class CGeoTerrain;


class CGeoTile
{


public:
//	bool original;

	// constructor and destructor
							CGeoTile( CGeoTerrain* inTerrain );
	virtual				~CGeoTile();

	// initialization
	void					SetupTile( int inLevel, int posX, int posY, const GeoRect& inR );
	void					SetTileRect( const GeoRect& inR ){ mBounds=inR; };

	int					GetLevel() const { return mLevel; };
	const IPoint&		GetPosId() const { return mPosId; };

	CGeoTerrain*		GetTerrain() const { return mTerrain; };
	int					GetTerrainId() const;

protected:
	// implementation data
	CGeoTerrain*	mTerrain;			///< owner terrain

	CGeoTile*		mParent;				///< ptr to parent tile, if any
	int				mLevel;				///< tile level, with 0=root
	IPoint			mPosId;				///< tile position, in its level; [0,0] is left top

	enum ESubTileFlag
	{
		eSubtileLeft=0,
		eSubtileTop=0,
		eSubtileRight=1,
		eSubtileBottom=2
	};  ///< bit flags whose combination indicates sub-tile position

	enum ESubTileId
	{
		eSubtileIdLT=eSubtileLeft | eSubtileTop,
		eSubtileIdRT=eSubtileRight | eSubtileTop,
		eSubtileIdLB=eSubtileLeft | eSubtileBottom,
		eSubtileIdRB=eSubtileRight | eSubtileBottom
	}; ///< identifier of sub-tile position

	ESubTileId		mSubTileId;			///< sub-tile position in parent tile

	// --- sub-tiles config
	enum ESubTileConfigFlag
	{
		eSubTileNone = 0,
		eSubTileLT = (1 >> eSubtileIdLT),
		eSubTileRT = (1 >> eSubtileIdRT),
		eSubTileLB = (1 >> eSubtileIdLB),
		eSubTileRB = (1 >> eSubtileIdRB),
		eSubTileAll = eSubTileLT | eSubTileRT | eSubTileLB | eSubTileRB
	}; ///< used to specify if a tile exists

	ESubTileConfigFlag	mSubTilesFlags;	///< 4 bits flags indicating where there can be sub-tiles; each bit corresponds to the sub-tile position
	int						mMaxSubTileCount;	///< how many sub-tiles it can have; this must be in synch with mSubTileFlags

	// --- sub-tiles running prop
	CGeoTile*				mSubTiles[4];		///< sub-tiles pointers
	int						mSubTileCount;		///< how many sub-tiles there are currently

	// --- geo-refs
	GeoRect					mBounds;				///< in absolute world coords
	double					mMinZ, mMaxZ;
	FPoint3d					mCenter;				///< center of the tile in 3D absolute coords
	double					mRadius;				///< radius of the sphere enclosing the tile

	double					mDistance;			///< it is the distance from the tile bounding sphere to the closest camera
														///< (radius is taken into account)
	bool						mIsInViewFrustum; ///< current tile visibility 
	double					mScreenPixSize;	///< this is the size of a screen pixel on the ground tile (closest part)

	bool						mIsInWorld;			///< states if the tile is rendered

	// ----- subtiles ----------
	inline void				GetSubTileBounds( ESubTileId inSubId, GeoRect* outRect );	///< retrieves the sub-tile rect in terrain coords

	//// --- loading stuffs
	//list<CGeoTile*>	mLoadingSubTiles; ///< sub-tiles currently under loading
	//CGeoTileLoader*	mLoaderObj;			///< loader obj in charge of loading this

	//bool				mDoLoadMesh;		///< to be used in loader, to know if only texture update
	//											///< is needed or if the mesh too needs to be loaded
	//int				mTxtRes;				///< current texture resolution
	//int				mTargetRes;			///< resolution to be loaded
	//int				mThemeIdx;			///< current theme
	//int				mTargetThemeIdx;	///< theme to be loaded

	//string			mMeshUrl[2];
	//string			mTxtUrl[2];
	//int				mCacheIdx;

	//unsigned	int	mClusterId;		///< id of the cluster to be loaded
	//TileCluster*	mClusterObj;
	//gmi::CPixmap*	mTxtImage;
	//IRect				mTxtBaseRect;	///< rect of tile in the base texture image

	//// --- mesh model
	//gg3d::CModel*	mModel;			///< ptr to terrain mesh model; texture is stored here

	//CGeoTileContext*	mTileContext;

	//// --- vector textures
	//CTxtTile*			mTxtTile;
	//CTxtTile*			mLoadingTxtTile;

	//// --- buildings
	//CBldTile*			mBldTile;
	//void					UpdateBuildings( gg3d::CCamera* inCamera, bool inCategoryChange );
	//bool					TileHasBuildings();


	public:
// ==========================================================================
//	 GeoTileSort
// ==========================================================================
	class GeoTileSort
	{
	public:
		inline bool	operator()( const CGeoTile *t1, const CGeoTile *t2 ) const
											{ return t1->mDistance < t2->mDistance; };
	};

private:
	void					InitCommon();

}; // class CGeoTile



#endif  // CGeoTile_h
