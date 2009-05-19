// system includes
#include <iostream>
#include <fstream>
#include <string>

#include <sstream>

// project includes
//#include "CRect.h"
#include "CPolyLine.h"
#include "CImage.h"

// global namespace declaration
using namespace std;


// --------------------------------------------------------------------------
//	 PrintVector
// --------------------------------------------------------------------------
void
PrintVector(const vector< unsigned char >& inVec)
{
	cout << "[ " ;
	vector< unsigned char >::const_iterator myIter;
	for ( myIter = inVec.begin(); myIter != inVec.end(); ++myIter )
		cout << *myIter << " ";
	cout << "]\n";
	return;
}

// --------------------------------------------------------------------------
//	 FunctExer2
// --------------------------------------------------------------------------
bool FunctExer2 ()
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
//	 FunctExer3
// --------------------------------------------------------------------------
bool 
FunctExer3()
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


// --------------------------------------------------------------------------
//	 FunctExerCopyImgandSave
// --------------------------------------------------------------------------
bool
FunctExerCopyImgandSave()
{
	CImage myImgA ( 10, 6, "LT", 1, "rgb" );
	CImage myImgB ( 10, 6, "LT", 1, "rgb" );

	vector< unsigned char > myColour;
	
	myColour.push_back( 12 );
	//myColour.push_back( 12 );
	//myColour.push_back( 12 );

	myImgA.Fill( myColour );

    myColour.resize( 0 );
	myColour.push_back( 50 );
	//myColour.push_back( 20 );
	//myColour.push_back( 20 );
	myImgA.SetPix( 2, 3, myColour ); //metto un pixel diverso nel rettangolo che copio

	myColour.resize( 0 );
	myColour.push_back( 55 );
	//myColour.push_back( 5 );
	//myColour.push_back( 5 );
	myImgB.Fill( myColour );

	myImgA.Draw();
	
	myImgB.Draw();
	

	myImgA.CopyImg( myImgB, CRect ( CPoint (3,1),  CPoint(10,6) ), 
							CRect ( CPoint (3,1),  CPoint(10,6) ) );


	myImgB.Draw();

		CImage* imgPtr = CImage::CreateFromFile();

	imgPtr->SaveToFile( "Test4.ppm" );
	delete imgPtr;

	return true;
}
// --------------------------------------------------------------------------
//	 ImageCopy
// --------------------------------------------------------------------------
bool 
ImageCopy()
{
	CImage myImgA ( 10, 6, "LT", 1, "rgb" );
	CImage myImgB ( 10, 6, "LT", 1, "rgb" );

	vector< unsigned char > myColour;
	
	myColour.push_back( 12 );

	myImgA.Fill( myColour );

	myColour.resize( 0 );
	myColour.push_back( 50 );
	
	myImgA.SetPix( 2, 3, myColour ); //metto un pixel diverso nel rettangolo che copio

	myColour.resize( 0 );
	myColour.push_back( 55 );
	
	myImgB.Fill( myColour );

	myImgA.Draw();
	
	myImgB.Draw();
	

	myImgA.CopyImg( myImgB, CRect ( CPoint (2,3), CPoint(10,6) ), 
							CRect ( CPoint (2,0), CPoint(10,6) ) );


	myImgB.Draw();

	return true;
}

// --------------------------------------------------------------------------
//	 ScaleCopy
// --------------------------------------------------------------------------
bool 
ScaleCopy( CImage* inPtr)
{
	CImage myImg( 400, 200 , "LT", 3, "rgb" );

	inPtr->CopyImg( myImg, CRect ( CPoint (350,50), CPoint(500,75) ), 
							CRect ( CPoint (-200,50), CPoint(10,75) ) );

	myImg.SaveToFile( "TestScale.ppm" );
	
	return true;
}

// --------------------------------------------------------------------------
//	 ClippingTest
// --------------------------------------------------------------------------
bool 
ClippingTest( CImage* inPtr)
{
	CImage myImg( 400, 200 , "LT", 3, "rgb" );

	inPtr->Clipping( myImg, CRect ( CPoint (50,50), CPoint(400,275) ),  
							CRect ( CPoint (50,25), CPoint(400,175) ) );

	myImg.SaveToFile( "TestClipping.ppm" );
	
	return true;
}


