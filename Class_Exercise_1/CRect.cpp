// system includes
#include <iostream>
#include <string>
#include <sstream>


// project includes
#include "CRect.h"

// global namespace declaration
using namespace std;

// --------------------------------------------------------------------------
//	 CRect
// --------------------------------------------------------------------------
CRect::CRect( const CPoint& inP1, const CPoint& inP2 )
: mLT(0,0)
, mRB(0,0)
{
	mLT.SetCoord( min( inP1.GetX(), inP2.GetX() ), min( inP1.GetY(), inP2.GetY() ) );
	mRB.SetCoord( max( inP1.GetX(), inP2.GetX() ), max( inP1.GetY(), inP2.GetY() ) );
	
}

// --------------------------------------------------------------------------
//	 ~CRect
// --------------------------------------------------------------------------
CRect::~CRect()
{}




// --------------------------------------------------------------------------
//	 SetExtremes
// --------------------------------------------------------------------------
void
CRect::SetExtremes( const CPoint& inP1, const CPoint& inP2 )
{
	mLT.SetCoord ( min( inP1.GetX(), inP2.GetX()), min( inP1.GetY(), inP2.GetY()) );
	mRB.SetCoord ( max( inP1.GetX(), inP2.GetX()), max( inP1.GetY(), inP2.GetY()) );
}

// --------------------------------------------------------------------------
//	 GetExtremes
// --------------------------------------------------------------------------
void
CRect::GetExtremes( CPoint& outLT, CPoint& outRB )
{
	outLT = mLT;
	outRB = mRB;
}

// --------------------------------------------------------------------------
//	 Shift
// --------------------------------------------------------------------------
void
CRect::Shift( const CPoint& inPShift )
{
	
	mLT.SetCoord ( (mLT.GetX() + inPShift.GetX()), (mLT.GetY() + inPShift.GetY()) );
	mRB.SetCoord ( (mRB.GetX() + inPShift.GetX()), (mRB.GetY() + inPShift.GetY()) );
}

// --------------------------------------------------------------------------
//	 Intersect  
// --------------------------------------------------------------------------
bool 
CRect::Intersect( const CRect& inRect )
{
	bool outBool;
	outBool =	( mLT.GetX() < inRect.GetRB().GetX() ) &&
				( mLT.GetY() < inRect.GetRB().GetY() ) &&
				( mRB.GetX() > inRect.GetLT().GetX() ) &&
				( mRB.GetY() > inRect.GetLT().GetY() );
	return outBool;
}

// --------------------------------------------------------------------------
//	 Inside
// --------------------------------------------------------------------------
bool
CRect::Inside( const CPoint& inP )
{
	bool outBool ;
	outBool =	( mLT.GetX() <= inP.GetX() ) &&
				( mLT.GetY() <= inP.GetY() ) &&
				( mRB.GetX() > inP.GetX() )  &&
				( mRB.GetY() > inP.GetY() ); 	
	return outBool;
}


// --------------------------------------------------------------------------
//	 Inside
// --------------------------------------------------------------------------
bool
CRect::Inside( const CRect& inRect )
{
	return	Inside( inRect.GetLT())&& 
			Inside( CPoint( inRect.GetRB().GetX()-1,inRect.GetRB().GetY()-1 ) );
}

// --------------------------------------------------------------------------
//	 Draw
// --------------------------------------------------------------------------
void
CRect::Draw()
{
	mLT.Draw();
	cout << "R";
	

	mRB.Draw();
	cout << "\n";
}

// --------------------------------------------------------------------------
//	 CreateFromXml
// --------------------------------------------------------------------------
CShape* 
CRect::CreateFromXml( XMLNode& currNode )
{
	double ltX = atof ( currNode.getAttribute( "ltx" ) );
	double ltY = atof ( currNode.getAttribute( "lty" ) );
	double rbX = atof ( currNode.getAttribute( "rbx" ) );
	double rbY = atof ( currNode.getAttribute( "rby" ) );

	CRect* myRect = new CRect( CPoint( ltX, ltY), CPoint( rbX, rbY ) );
	return myRect;
}


// --------------------------------------------------------------------------
//	 CreateFromXml [virtual]
// --------------------------------------------------------------------------
void
CRect::SaveXml ( XMLNode& inNode )
{
	XMLNode io = inNode.addChild( "Rect" );
	ostringstream 	strStreamLTX, strStreamLTY, strStreamRBX, strStreamRBY;

	strStreamLTX << mLT.GetX();
	io.addAttribute( "ltx", strStreamLTX.str().c_str() );

	strStreamLTY << mLT.GetY();
	io.addAttribute( "lty", strStreamLTY.str().c_str() );

	strStreamRBX << mRB.GetX();
	io.addAttribute( "rbx", strStreamRBX.str().c_str() );

	strStreamRBY << mRB.GetY();
	io.addAttribute( "rby", strStreamRBY.str().c_str() );

	return;
}

// --------------------------------------------------------------------------
//	 RClipping 
// --------------------------------------------------------------------------
CRect
CRect::RClipping( const CRect& inRect )
{

	if (!(this->Intersect( inRect )))
	{
		cout << "\nNon c'è intersezione\n";
		return inRect;
	}
	
	//if ( this->Inside( inRect ) )
	//	return inRect;

	CPoint outLT (	max ( mLT.GetX(), inRect.GetLT().GetX() ), 
					max ( mLT.GetY(), inRect.GetLT().GetY() ) );
	CPoint outRB (	min ( mRB.GetX(), inRect.GetRB().GetX() ), 
					min ( mRB.GetY(), inRect.GetRB().GetY() ) );

	CRect outRect( outLT, outRB );
	return outRect;

	

}
