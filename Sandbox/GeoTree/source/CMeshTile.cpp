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

#include "CMeshTile.h"


// ---------------------------------------------------------------------------
//	 CMeshTile
// ---------------------------------------------------------------------------
CMeshTile::CMeshTile( CGeoTerrain* inTerrain )
: CGeoTile( inTerrain )
{
	InitCommon();
} 

// ---------------------------------------------------------------------------
//	 InitCommon
// ---------------------------------------------------------------------------
void
CMeshTile::InitCommon()
{

} 

// ---------------------------------------------------------------------------
//	 ~CMeshTile
// ---------------------------------------------------------------------------
/** 
 * \brief	destructor
 *
 *	Tiles are not in charge of destroying terrain models
 *
**/
CMeshTile::~CMeshTile()
{
	
} 


