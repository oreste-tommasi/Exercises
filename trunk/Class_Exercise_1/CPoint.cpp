// system includes
#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>

// project includes
#include "CPoint.h"
#include "xmlParser.h"

// global namespace declaration
using namespace std;

int	CShape::gTotalShapes = 0;


// --------------------------------------------------------------------------
//	 CPoint
// --------------------------------------------------------------------------
CPoint::CPoint( double inX, double inY )
: mX(inX)
, mY(inY)
{

}

// --------------------------------------------------------------------------
//	 ~CPoint
// --------------------------------------------------------------------------
CPoint::~CPoint()
{
	;
}


// --------------------------------------------------------------------------
//	 SetCoord
// --------------------------------------------------------------------------
void
CPoint::SetCoord( double inX, double inY )
{
	mX = inX;
	mY = inY;
}

// --------------------------------------------------------------------------
//	 GetCoord
// --------------------------------------------------------------------------
void
CPoint::GetCoord( double& outX, double& outY ) const
{
	outX = mX;
	outY = mY;
}

// --------------------------------------------------------------------------
//	 Draw [virtual]
// --------------------------------------------------------------------------
void
CPoint::Draw() const
{
	std::cout << "(" << mX << "," << mY << ")";
}


// --------------------------------------------------------------------------
//	 CreateFromXml
// --------------------------------------------------------------------------
CShape* 
CPoint::CreateFromXml( XMLNode& currNode )
{
	double x = atof ( currNode.getAttribute( "x" ) );
	double y = atof ( currNode.getAttribute( "y" ) );
	CPoint* p = new CPoint(x,y);
	return p;
	
}

// --------------------------------------------------------------------------
//	 CreateFromXml [virtual]
// --------------------------------------------------------------------------
void
CPoint::SaveXml ( XMLNode& inNode )
{

	XMLNode io = inNode.addChild( "Point" );
	ostringstream 	strStreamX, strStreamY;
	
	strStreamX << mX;
	io.addAttribute( "x", strStreamX.str().c_str() );

	//strStream.str().resize( 0 );

	strStreamY << mY;
	io.addAttribute( "y", strStreamY.str().c_str() );

	

	return;
}
