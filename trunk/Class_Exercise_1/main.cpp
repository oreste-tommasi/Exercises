// system includes
#include <iostream>
#include <vector>
//#include <list>
//#include <map>



// global namespace declaration
using namespace std;

// project includes
//#include "CPolyLine.h"
//#include "CRect.h"
//#include "Test.h"
//#include "NotPolymorphic.h"
//#include "Polymorphic.h"
#include "CImage.h"
//#include "xmlParser.h"


void PrintVector(const vector< unsigned char >& );

int main ()
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

	//myColour.resize( 0 );

	/*myImgA.GetPix( 1, 1, myColour );
	cout << "\nPosizione A(1,1)\n" ;
	PrintVector( myColour );

	myImgA.GetPix( 3, 3, myColour );
	cout << "\nPosizione A(3,3)\n" ;
	PrintVector( myColour );
	
	myImgB.GetPix( 3, 8, myColour );
	cout << "\nPosizione (3,8)\n" ;
	PrintVector( myColour );

	myImgB.GetPix( 4, 7, myColour );
	cout << "\nPosizione (4,7)\n" ;
	PrintVector( myColour );

	myImgB.GetPix( 4, 9, myColour );
	cout << "\nPosizione (4,9)\n" ;
	PrintVector( myColour );

	myImgB.GetPix( 4, 8, myColour );
	cout << "\nPosizione (4,8)\n" ;
	PrintVector( myColour );*/


	//FunctExer2();

	//FunctExer3();
	
	//FunctExerciseX();

	//FunctionNoPolymorphic();

	//Poly3();

	CImage* imgPtr = CImage::CreateFromFile();

	imgPtr->SaveToFile();


	//typedef	 void(*MyFunType)(int) ;	

	//map< char,  int >				myMap; 
	//map< char,  int >::iterator		myIter;

	//map< const char*, MyFunType >	createMap;

	//myMap[ 'a' ] = 5;
	////int a = myMap[ 'a' ]; // sbagliato

	//myIter = myMap.find( 'a' );
	//if ( myIter != myMap.end() )
	//	int a = myIter->second;
	

	cout << endl << endl;
	system("pause");

	delete imgPtr;

	return 0;

}

//// unit tests
//bool
//RectIntersectTest()
//{
//	CPoint lt(0,0), rb(10,10);
//	CPoint shift(3,0);
//
//	return true;
//}
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
