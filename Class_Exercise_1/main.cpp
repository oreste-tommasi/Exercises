// system includes
#include <iostream>

// global namespace declaration
using namespace std;


#include "CPoint.h"
#include "CPolyLine.h"
#include "CShape.h"


int main ()
{
	CPoint p(3,4);
	double x, y;

	p.SetCoord( 10, 20);
	p.GetCoord( x, y);

	CPolyLine polyLine;
	polyLine.AddPoint( p );

	p.SetCoord( 20, 40 );
	polyLine.AddPoint( p );

	polyLine.Draw();

	system("pause");

	return 0;


}