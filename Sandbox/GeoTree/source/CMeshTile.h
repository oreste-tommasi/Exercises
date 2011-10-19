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

#ifndef	CMeshTile_h
#define	CMeshTile_h


#include "CGeoTile.h"

// ==========================================================================
//	 CMeshTile
// ==========================================================================
/**
 * \brief	unitary terrain mesh object
 *
 * \internal
 **/


// forward declaration


class CMeshTile : public CGeoTile
{


public:
//	bool original;

	// constructor and destructor
							CMeshTile( CGeoTerrain* inTerrain );
	virtual				~CMeshTile();

	// initialization


protected:
	// implementation data
	
	



private:
	void					InitCommon();

}; // class CMeshTile



#endif  // CMeshTile_h
