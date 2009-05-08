#ifndef CPOLYLINE_H
#define CPOLYLINE_H


// system include
#include <vector>

// project include
#include "CRect.h"

// forward declarations
using namespace std;


class CPolyLine 
{
public:
	// interface
	CPolyLine();
	~CPolyLine();

	void		Draw();

	void		AddPoint( const CPoint& inP );
	size_t		GetVertexCount() const
				{ return mVertices.size(); }

	CRect		GetBoundingBox() const
				{ return mBoundRect; }

private: 
	// implementation 
	vector< CPoint >	mVertices;
	CRect				mBoundRect;

	

};

#endif // CPOLYLINE_H
