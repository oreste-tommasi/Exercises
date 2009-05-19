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


int main ()
{ 

	//FunctExer2();

	//FunctExer3();
	
	//FunctExerciseX();

	//FunctionNoPolymorphic();

	//Poly3();

	//CImage* imgPtr = CImage::CreateFromFile();

	CImage myImg( "Scritta.ppm");
	
	ClippingTest( &myImg );

	cout << endl << endl;
	system("pause");


	return 0;

}

