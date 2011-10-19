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

#ifndef	CMeshDataCache_h
#define	CMeshDataCache_h

#include "gmcuThread.h"
#include "CTCache.h"


// forward declaration
namespace gmi{
	class CPixmap;
}

// ==========================================================================
//	 MeshTileCluster
// ==========================================================================
struct MeshTileCluster
{
	enum EClusterStatus
	{
		eClusterEmpty=0,
		eClusterReady,
		eClusterDecoding
	};

	struct TileClusterId
	{
		unsigned int	sourceId;	///< this should be a unique identifier for the source (terrain)
		unsigned int	level;
		IPoint			mapId;

		bool		operator <(const TileClusterId& b) const
		{
			return !(sourceId>=b.sourceId && level>=b.level && mapId.x>=b.mapId.x && mapId.y>=b.mapId.y); 
		};
	};
	
	TileClusterId	clusterId;

	unsigned	int	refCount;
	gmi::CPixmap*	meshImg;
	EClusterStatus	status;

	MeshTileCluster( const TileClusterId& inId );
	~MeshTileCluster();

	void				Reset();
	unsigned int	GetSize();

};

// ==========================================================================
//	 CMeshDataCache
// ==========================================================================
class CMeshDataCache
{


public:
//	bool original;

	// constructor and destructor
							CMeshDataCache( unsigned int inMaxUnusedSize );
	virtual				~CMeshDataCache();

	// initialization
	MeshTileCluster*	GetCluster( MeshTileCluster::TileClusterId inId ); ///< add ref count
	void					RestoreCluster( MeshTileCluster* inCluster ); ///< release ref count
	

protected:
	// implementation data


	gmcu::CTCache<MeshTileCluster::TileClusterId, MeshTileCluster*>	mUsedClusters;
	gmcu::CTCache<MeshTileCluster::TileClusterId, MeshTileCluster*>	mUnusedClusters;
	
	unsigned int		mMaxUnusedClusterSize; // in bytes
	unsigned int		mUnusedClusterSize; // in bytes

	gmcu::Mutex			mMutex;				///< it assures mutual exclusion

	void				FreeEccessClusters(); ///< not mutex protected


private:

}; // class CMeshDataCache



#endif  // CMeshDataCache_h
