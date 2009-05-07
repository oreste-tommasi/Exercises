#ifndef CPOLYLINE_H
#define CPOLYLINE_H


// system include
#include <vector>

// project include
#include "CPoint.h"

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

private: 
	// implementation 
	vector< CPoint >	mVertices;
	

};

#endif // CPOLYLINE_H
