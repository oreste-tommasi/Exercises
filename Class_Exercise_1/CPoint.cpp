// system includes
#include <iostream>

// project includes
#include "CPoint.h"
#include "xmlParser.h"

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
{}


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
//	 Draw
// --------------------------------------------------------------------------
void
CPoint::Draw()
{
	std::cout << "(" << mX << "," << mY << ")";
}


// --------------------------------------------------------------------------
//	 CreateFromXml
// --------------------------------------------------------------------------
CPoint* 
CPoint::CreateFromXml( XMLNode& currNode )
{
	double x = atof ( currNode.getAttribute( "x" ) );
	double y = atof ( currNode.getAttribute( "y" ) );
	CPoint* p = new CPoint(x,y);
	return p;
	//se faccio la delete mi perdo l'indirizzo!
}
