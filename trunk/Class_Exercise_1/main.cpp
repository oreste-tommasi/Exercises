// system includes
#include <iostream>
#include <vector>

// global namespace declaration
using namespace std;

// project includes
#include "CPolyLine.h"
#include "CRect.h"
#include "Test.h"

int main ()
{
	//FunctExer2();

	//FunctExer3();
	
	//FunctExerciseX();

	//ReadXml();

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
