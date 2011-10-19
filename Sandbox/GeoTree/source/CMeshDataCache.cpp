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

#include "CMeshDataCache.h"
#include "CPixmap.h"


// ---------------------------------------------------------------------------
//	 CMeshDataCache
// ---------------------------------------------------------------------------
CMeshDataCache::CMeshDataCache( unsigned int inMaxUnusedSize )
: mMaxUnusedClusterSize(inMaxUnusedSize)
, mUnusedClusterSize(0)
{
	ThreadMutexInit( &mMutex, NULL );
} 


// ---------------------------------------------------------------------------
//	 ~CMeshDataCache
// ---------------------------------------------------------------------------
/** 
 * \brief	destructor
 *
 *	Tiles are not in charge of destroying terrain models
 *
**/
CMeshDataCache::~CMeshDataCache()
{
	MeshTileCluster*	cluster;

	while( mUnusedClusters.PopFront( NULL, &cluster ) )
		delete cluster;

	ThreadMutexDestroy( &mMutex );
} 

// ---------------------------------------------------------------------------
//	 GetCluster
// ---------------------------------------------------------------------------
MeshTileCluster* 
CMeshDataCache::GetCluster( MeshTileCluster::TileClusterId inId )
{
	MeshTileCluster*	outCluster=NULL;

	gmcu::StMutexLock mutexLocker( &mMutex );

	if( mUsedClusters.Size() && mUsedClusters.Find( inId, &outCluster ) )
		outCluster->refCount++;
	else if( mUnusedClusters.Size() && mUnusedClusters.Fetch( inId, &outCluster ) )
	{
		mUsedClusters.PushBack( outCluster->clusterId, outCluster );
		mUnusedClusterSize -= outCluster->GetSize();
		outCluster->refCount++;
	}
	else
	{
		outCluster = new MeshTileCluster( inId );
		outCluster->refCount = 1;
		mUsedClusters.PushBack( outCluster->clusterId, outCluster );
	}

	return outCluster;
}

// ---------------------------------------------------------------------------
//	 RestoreCluster
// ---------------------------------------------------------------------------
void
CMeshDataCache::RestoreCluster( MeshTileCluster* inCluster )
{
	gmcu::StMutexLock mutexLocker( &mMutex );

	inCluster->refCount--;

	if( inCluster->refCount==0 )
	{
		mUsedClusters.Remove( inCluster->clusterId );
		mUnusedClusters.PushBack( inCluster->clusterId, inCluster );
		mUnusedClusterSize = inCluster->GetSize();

		if( mUnusedClusterSize>mMaxUnusedClusterSize )
			FreeEccessClusters();
	}
}

// ***** PRIVATE *************************************************************

// ---------------------------------------------------------------------------
//	 FreeEccessClusters
// ---------------------------------------------------------------------------
// not mutex protected
void 
CMeshDataCache::FreeEccessClusters()
{
	while( mUnusedClusterSize>mMaxUnusedClusterSize )
	{
		MeshTileCluster*	cluster;
		
		if( mUnusedClusters.PopFront( NULL, &cluster ) )
		{
			mUnusedClusterSize -= cluster->GetSize();
			delete cluster;
		}
	}
}

// ***************************************************************************

// ---------------------------------------------------------------------------
//	 MeshTileCluster
// ---------------------------------------------------------------------------
MeshTileCluster::MeshTileCluster( const TileClusterId& inId )
{
	memset( this, 0, sizeof(MeshTileCluster) );
	clusterId = inId;
}

// ---------------------------------------------------------------------------
//	 ~MeshTileCluster
// ---------------------------------------------------------------------------
MeshTileCluster::~MeshTileCluster()
{
	delete meshImg;
}

// ---------------------------------------------------------------------------
//	 GetSize
// ---------------------------------------------------------------------------
unsigned int
MeshTileCluster::GetSize()
{
	return meshImg ?	meshImg->GetImageSize() : 0;
}