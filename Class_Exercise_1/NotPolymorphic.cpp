// system includes
#include <iostream>
#include <fstream>
#include <string>

#include <sstream>

// project includes
//#include "CRect.h"
#include "CPolyLine.h"
#include "NotPolymorphic.h"

#include "xmlParser.h"

// global namespace declaration
using namespace std;


// --------------------------------------------------------------------------
//	 FunctionNoPolymorphic
// --------------------------------------------------------------------------
bool
FunctionNoPolymorphic()
{
	vector< CPoint* >		outPoints;
	vector< CPolyLine* >	outPolyLines;
	vector< CRect* >		outRects;

	ReadXml2( outPoints, outPolyLines, outRects );

	//Va liberato lo spazio con le delete

	//Disegno i punti e libero la memoria

	vector< CPoint* >::iterator		pointIter;

	cout << "Drawing <Points>" << endl << endl;
	for( pointIter=outPoints.begin() ; pointIter < outPoints.end() ; ++ pointIter)
	{
		(*(pointIter))->Draw();
		cout << "\n\n";
		delete(*(pointIter));
	}

	cout << "\n";
	
	//Disegno le polylines e libero la memoria

	vector< CPolyLine* >::iterator	polyIter;

	cout << "Drawing <PolyLines>" << endl << endl;
	for( polyIter=outPolyLines.begin() ; polyIter < outPolyLines.end() ; ++ polyIter)
	{
		(*(polyIter))->Draw();
		cout << "\n";
		delete(*(polyIter));
	}

	cout << "\n";
	
	//Disegno le polylines e libero la memoria

	vector< CRect* >::iterator		rectIter;

	cout << "Drawing <Rects>" << endl << endl;
	for( rectIter=outRects.begin() ; rectIter < outRects.end() ; ++ rectIter)
	{
		(*(rectIter))->Draw();
		cout << "\n";
		delete(*(rectIter));
	}

	return true;
}


// --------------------------------------------------------------------------
//	 ReadXml2
// --------------------------------------------------------------------------
bool
ReadXml2(	vector< CPoint* >& outPoints, 
			vector< CPolyLine* >& outPolyLines, 
			vector< CRect* >& outRects )
{
	bool					success = false;
	XMLNode					xMainNode = XMLNode::openFileHelper( "input.xml" ); 
	XMLNode					xNode = xMainNode.getChildNode();
	string					theName = xNode.getName();
	

	if ( theName != "Geometries" )
		cout << "Unknown format" << endl;
	else
	{	
		int			count = xNode.nChildNode();
		XMLNode		currNode;

		for ( int i=0; i<count; ++i)
		{
			currNode = xNode.getChildNode(i);
			theName = currNode.getName();

			if ( theName == "Point"  )
			{
				CShape* p = CPoint::CreateFromXml( currNode );
				outPoints.push_back( (CPoint*)p );
				
			}
			else if ( theName ==  "PolyLine" )
			{
				CShape* p= CPolyLine::CreateFromXml( currNode );
				outPolyLines.push_back( (CPolyLine*)p );
			
			}
			else if ( theName == "Rect"  )
			{
				CShape* p = CRect::CreateFromXml( currNode );
				outRects.push_back( (CRect*)p );

			}
			
			else
			{
				cout<< theName << ": unknow geometry type" << endl;
			}

		}
		
		success = true;
	}	

	
	return success;
}




// --------------------------------------------------------------------------
//	 ReadXml
// --------------------------------------------------------------------------
bool 
ReadXml()
{
	bool		success = false;
	XMLNode		xMainNode = XMLNode::openFileHelper( "input.xml" ); 
	XMLNode		xNode = xMainNode.getChildNode();
	string		theName = xNode.getName();

	if ( theName != "Geometries" )
		cout << "Unknown format" << endl;
	else
	{	
		int			count = xNode.nChildNode();
		XMLNode		currNode;

		for ( int i=0; i<count; ++i)
		{
			currNode = xNode.getChildNode(i);
			theName = currNode.getName();

			if ( theName == "Point"  )
			{
				// CPoint* ptr = CPoint::CreateFromXml(currNode);
				cout << "Parsing a <Point>" << endl;
				double x = atof ( currNode.getAttribute( "x" ) );
				double y = atof ( currNode.getAttribute( "y" ) );
				
				CPoint p(x,y);
				cout << "Drawing <Point>" << endl;
				p.Draw();
				cout << endl;

			}
			else if ( theName ==  "PolyLine" )
			{
				cout << "Parsing a <PolyLine>" << endl;

				string			str = currNode.getText();
				double			posX, posY;
				istringstream	strStream;
				CPolyLine		polyLine;

			    strStream.str(str);
				
				while( strStream >> posX )
				{
					if ( strStream >> posY )
					{
						CPoint p(posX, posY);
						polyLine.AddPoint( p );
					}
				}

				cout << "Drawing <PolyLine>" << endl;
				polyLine.Draw();
				cout << endl;
			}
			else if ( theName == "Rect"  )
			{
				
				cout << "Parsing a <Rect>" << endl;
				double ltX = atof ( currNode.getAttribute( "ltx" ) );
				double ltY = atof ( currNode.getAttribute( "lty" ) );
				double rbX = atof ( currNode.getAttribute( "rbx" ) );
				double rbY = atof ( currNode.getAttribute( "rby" ) );

				CRect myRect( CPoint( ltX, ltY), CPoint( rbX, rbY ) );
				cout << "Drawing <Rect>" << endl;
				myRect.Draw();
				cout << endl;

			}
			
			else
			{
				cout<< theName << ": unknow geometry type" << endl;
			}

		}
		
		success = true;
	}	


	return success;
}

