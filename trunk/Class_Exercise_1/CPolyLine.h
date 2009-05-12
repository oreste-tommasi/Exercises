#ifndef CPOLYLINE_H
#define CPOLYLINE_H


// system include
#include <vector>

// project include
#include "CRect.h"

// external include
#include "xmlParser.h"


// forward declarations
using namespace std;


class CPolyLine : public CShape
{
public:
	// interface
	CPolyLine();
	~CPolyLine();

	void				Draw();

	void				AddPoint( const CPoint& inP );
	size_t				GetVertexCount() const
						{ return mVertices.size(); }

	CRect				GetBoundingBox() const
						{ return mBoundRect; }

	static CShape*		CreateFromXml(XMLNode& inNode); 

	virtual void		SaveXml ( XMLNode& inNode );


private: 
	// implementation 
	vector< CPoint >	mVertices;
	CRect				mBoundRect;

	

};


#endif // CPOLYLINE_H
