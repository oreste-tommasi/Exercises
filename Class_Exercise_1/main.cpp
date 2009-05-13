// system includes
#include <iostream>
#include <vector>
#include <list>
#include <map>



// global namespace declaration
using namespace std;

// project includes
#include "CPolyLine.h"
#include "CRect.h"
#include "Test.h"
#include "NotPolymorphic.h"
#include "Polymorphic.h"

#include "xmlParser.h"



int main ()
{
	//FunctExer2();

	//FunctExer3();
	
	//FunctExerciseX();

	//FunctionNoPolymorphic();

	Poly3();



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

//// unit tests
//bool
//RectIntersectTest()
//{
//	CPoint lt(0,0), rb(10,10);
//	CPoint shift(3,0);
//
//	return true;
//}
