// system includes
#include <iostream>
#include <sstream>

// project includes
#include "CPolyLine.h"



// --------------------------------------------------------------------------
//	 CPolyLine
// --------------------------------------------------------------------------
CPolyLine::CPolyLine()
: mBoundRect( CPoint(0,0), CPoint(0,0) )
{
}

// --------------------------------------------------------------------------
//	 ~CPolyLine
// --------------------------------------------------------------------------
CPolyLine::~CPolyLine()
{
	;//cout << "distruttore CPolyLine" << endl;
}



// --------------------------------------------------------------------------
//	 AddPoint
// --------------------------------------------------------------------------
void
CPolyLine::AddPoint( const CPoint& inP )
{
	mVertices.push_back( inP );
	if ( GetVertexCount() == 1)
		mBoundRect.SetExtremes( inP, inP );
	else
	{
		if  ( !( mBoundRect.Inside( inP )) )
		{
			CPoint mP( 	min ( mBoundRect.GetLT().GetX(), inP.GetX() ),
						min ( mBoundRect.GetLT().GetY(), inP.GetY() ) );
					
			CPoint mQ( 	max ( mBoundRect.GetRB().GetX(), inP.GetX() ),
						max ( mBoundRect.GetRB().GetY(), inP.GetY() ) );
						
			mBoundRect.SetExtremes( mP, mQ ) ;
		}
	
	}
}

// --------------------------------------------------------------------------
//	 Draw
// --------------------------------------------------------------------------
void
CPolyLine::Draw() const
{
	vector< CPoint >::const_iterator  myIter;
	//double x, y;

	for ( myIter=mVertices.begin(); myIter<(mVertices.end()-1); ++myIter)
	{
		myIter->Draw();
		cout << "-";
	}

	myIter->Draw();
	cout << "\n";
}

// --------------------------------------------------------------------------
//	 CreateFromXml
// --------------------------------------------------------------------------
CShape* 
CPolyLine::CreateFromXml( XMLNode& currNode )
{
	string			str = currNode.getText();
	double			posX, posY;
	istringstream	strStream;
	
	strStream.str(str);

	CPolyLine* myPL = new CPolyLine();
				
	while( strStream >> posX )
	{
		if ( strStream >> posY )
		{
			CPoint p(posX, posY);
			myPL->AddPoint( p );
		}
	}
	return myPL;
}


// --------------------------------------------------------------------------
//	 CreateFromXml [virtual]
// --------------------------------------------------------------------------
void
CPolyLine::SaveXml ( XMLNode& inNode )
{
	XMLNode io = inNode.addChild( "PolyLine" );
	ostringstream 	strStream;
	vector< CPoint >::iterator myIt;

	for( myIt=this->mVertices.begin(); myIt != mVertices.end() ; ++ myIt )
	{
		strStream << myIt->GetX() << " " << myIt->GetY() << " ";
	}

	io.addText( strStream.str().c_str() );
		
	return;
}