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
#include "Test.h"
#include "CImage.h"
//#include "NotPolymorphic.h"
//#include "Polymorphic.h"

//#include "xmlParser.h"


void PrintVector(const vector< unsigned char >& );

int main ()
{ 

	//FunctExer2();

	//FunctExer3();
	
	//FunctExerciseX();

	//FunctionNoPolymorphic();

	//Poly3();

	CImage* imgPtr = CImage::CreateFromFile();

	ScaleCopy(imgPtr);


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

	return 0;

}

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
