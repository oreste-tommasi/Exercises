// system includes
#include <iostream>
#include <fstream>
#include <string>

#include <sstream>

// project includes
//#include "CRect.h"
#include "CPolyLine.h"

#include "xmlParser.h"

// global namespace declaration
using namespace std;


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
			// aggiungi qui altre geometrie e poi rimuovi questo commento
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
//	 f_es2
// --------------------------------------------------------------------------
bool f_es2 ()
{
	CPoint p(3,4);
	CPoint q(10, 1);
	//CPoint outp(0, 0) , outq(0, 0);
	double x, y;

	CRect rect( q, p );

	cout << "\nPunti iniziali:\n";
	q.Draw();
	p.Draw();
	cout << "\n\n";
	
	
	rect.GetExtremes( p, q );

	cout << "\nPunti LT e RB:\n";
	p.Draw();
	q.Draw();
	cout << "\n\n";

	p.SetCoord( 1, 2 );
	rect.Shift( p );

	cout << "\nPunti LT e RB dopo lo shift di (1,2):\n";
	rect.GetExtremes( p, q );
	p.Draw();
	q.Draw();
	cout << "\n\n";

	cout << "\nInserisci i due punti del secondo rettangolo:\n";
	cin >> x;
	cin >> y;
	p.SetCoord( x, y );
	cin >> x;
	cin >> y;
	q.SetCoord( x, y );
	CRect rectInters( p, q );

	rectInters.GetExtremes( p, q );
	cout << "\nPunti LT e RB del secondo rettangolo:\n";
	p.Draw();
	q.Draw();
	cout << "\n\n";

	bool ris;
	ris= rect.Intersect( rectInters );
	cout << "\nIl risultato dell'intersezione è: " << ris <<"\n\n";

	cout << "\nInserisci il punto da verificare: \n\n";
	cin >> x;
	cin >> y;
	p.SetCoord( x, y );

	ris = rect.Inside( p );
	cout << "\nIl punto è interno? " << ris <<"\n\n";
	
	return true;

}

// --------------------------------------------------------------------------
//	 f_es3
// --------------------------------------------------------------------------
bool 
f_es3()
{
	CPolyLine mPol;
	int myCount, inSize;
	double x, y;
	
	cout << "\nQuanti punti vuoi inserire?\n";
	cin >> inSize;

	CPoint myP( 0,0 );

	for( myCount=1; myCount <= inSize; ++myCount )
	{
		cout << "\nInserisci le coordinate: \n";
		cin >> x;
		cin >> y;
		myP.SetCoord( x, y );
		mPol.AddPoint( myP );	
	}

	mPol.Draw();

	cout << "\nNumero vertici: \t" << 
		    static_cast<int> ( mPol.GetVertexCount() ) << "\n\n";

	CRect myRect( myP, myP );

	myRect=mPol.GetBoundingBox();

	cout << "\nRettangolo:\n";
	myRect.Draw();

	return true;
}

// --------------------------------------------------------------------------
//	 FunctExerciseX
// --------------------------------------------------------------------------
bool 
FunctExerciseX()
{
	ifstream	fileInput( "input.txt" );

	int	readX=9999, readY=9999;

	if ( !(fileInput >> readX) )
		cout << "Errore" << endl;
	else
	{
		fileInput >> readY;

		CPoint	p(readX, readY);

		p.Draw();
	}

	fileInput.close();

	return true;
}

