// system includes
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


#include <sstream>

// project includes
#include "Polymorphic.h"
#include "CRect.h"
#include "CPolyLine.h"

#include "xmlParser.h"

// global namespace declaration
using namespace std;

CShape::CreationMapType	CShape::gCreateFromXmlMap;


// --------------------------------------------------------------------------
//	 ReadXml_
// --------------------------------------------------------------------------
list< CShape* >	
ReadXml_()
{
	bool			success = false;
	XMLNode			xMainNode = XMLNode::openFileHelper( "input.xml" ); 
	XMLNode			xNode = xMainNode.getChildNode();
	string			theName = xNode.getName();
	list< CShape* >	outShapes;
	
	CShape::gCreateFromXmlMap[ "Point" ] = CPoint::CreateFromXml;
	CShape::gCreateFromXmlMap[ "PolyLine" ] = CPolyLine::CreateFromXml;
	CShape::gCreateFromXmlMap[ "Rect" ] = CRect::CreateFromXml;

	if ( theName != "Geometries" )
		cout << "Unknown format" << endl;
	else
	{	
		int						count = xNode.nChildNode();
		XMLNode					currNode;
		CShape::CreationMapIter	myIter;

		for ( int i=0; i<count; ++i)
		{
			currNode = xNode.getChildNode(i);
			theName = currNode.getName();
			
			myIter = CShape::gCreateFromXmlMap.find( theName.c_str() );

			if ( myIter !=  CShape::gCreateFromXmlMap.end() )
			{
				CreateFromXmlType currFunction = myIter->second;
				CShape* ptr = currFunction( currNode );
				outShapes.push_back( ptr );
			}
			else
				cout << theName << ": unknow geometry type" << endl;
		}
	}
		
	return outShapes;
}


// --------------------------------------------------------------------------
//	 Poly2
// --------------------------------------------------------------------------
bool
Poly2()
{
	list< CShape* >	outShapes;

	ReadXml( outShapes );

	list< CShape* >::iterator	shapeIter;
	
	CPoint* p = new CPoint(9,29);
	
	shapeIter=outShapes.begin();
	if ( outShapes.size() > 1 )
	{
		++shapeIter;
		outShapes.insert( shapeIter, p );
	}
	
	XMLNode node = XMLNode::createXMLTopNode( "Geometries" );
	
	cout << "Drawing <Shapes>" << endl << endl;
	for( shapeIter=outShapes.begin() ; shapeIter != outShapes.end() ; ++ shapeIter)
	{
		(*(shapeIter))->Draw();
		(*(shapeIter))->SaveXml( node );
		cout << "\n";

		delete(*(shapeIter));
	}
	node.writeToFile( "pippo.xml" );

	return true;
}


// --------------------------------------------------------------------------
//	 Poly1
// --------------------------------------------------------------------------
//bool
//Poly1()
//{
//	CPoint* ptrPoint = new CPoint(8,8);
//	CRect*	ptrRect = new CRect( CPoint(0,1), CPoint(19,20) );
//	
//	ptrPoint->Draw();
//
//	cout << "\n\nrect" << endl;
//	ptrRect->Draw();
//
//	// polyline
//	CPolyLine*	ptrPoly = new CPolyLine();
//	ptrPoly->AddPoint( CPoint(0,1) ); 
//	ptrPoly->AddPoint( CPoint(19,20) ); 
//
//	cout << "\n\nPoly" << endl;
//	ptrPoly->Draw();
//
//	// shapes
//	vector< CShape* >		shpVec; 
//
//	shpVec.push_back( ptrPoint );
//	shpVec.push_back( ptrRect );
//	shpVec.push_back( ptrPoly );
//
//	cout << "\n\nDraw shapes" << endl;
//
//	for ( size_t i=0; i<shpVec.size(); ++i)
//	{
//		shpVec[i]->Draw();
//		cout << "\n";
//	}
//
//	cout << "\nCreatedShapes: " << CShape::CreatedShapes() << endl;
//
//
//	ReadXml che restituisce un vector di shape
//
//	XMLNode node = createXMLTopNode( "Geometries" );
//	.. shpVec[i]->SaveXml(node);
//
//	CPoint::SaveXml( XMLNode parent )
//	{
//		XMLNode io = parent->addChild( "Point" );
//		io->addAttribute( "x", converto in stringa(mX) );
//		io->addAttribute( "y", converto in stringa(mY) );
//	}
//
//
//	node.writeToFile( "pippo.xml" );
//
//
//	for ( size_t i=0; i<shpVec.size(); ++i)
//		delete shpVec[i];
//
//	return true;
//}
// --------------------------------------------------------------------------
//	 ReadXmlPolymorphic
// --------------------------------------------------------------------------
bool 
ReadXml (	list< CShape* >& outShapes ) 
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
				CShape* p= CPoint::CreateFromXml( currNode );
				outShapes.push_back( p );
				
			}
			else if ( theName ==  "PolyLine" )
			{
				CShape* myPL = CPolyLine::CreateFromXml( currNode );
				outShapes.push_back( myPL );
			
			}
			else if ( theName == "Rect"  )
			{
				CShape* myRect = CRect::CreateFromXml( currNode );
				outShapes.push_back( myRect );

			}
			
			else
			{
				cout << theName << ": unknow geometry type" << endl;
			}

		}
		
		success = true;
	}	

	
	return success;
}


// --------------------------------------------------------------------------
//	 Poly3
// --------------------------------------------------------------------------
bool
Poly3()
{
	list< CShape* >	outShapes;

	outShapes = ReadXml_();

	list< CShape* >::iterator	shapeIter;
	
	//CPoint* p = new CPoint(9,29);
	
	//shapeIter=outShapes.begin();
	//if ( outShapes.size() > 1 )
	//{
	//	++shapeIter;
	//	outShapes.insert( shapeIter, p );
	//}
	//
	XMLNode node = XMLNode::createXMLTopNode( "Geometries" );
	
	cout << "Drawing <Shapes>" << endl << endl;
	for( shapeIter=outShapes.begin() ; shapeIter != outShapes.end() ; ++ shapeIter)
	{
		(*(shapeIter))->Draw();
		(*(shapeIter))->SaveXml( node );
		cout << "\n";

		delete(*(shapeIter));
	}
	node.writeToFile( "pluto.xml" );

	return true;
}
