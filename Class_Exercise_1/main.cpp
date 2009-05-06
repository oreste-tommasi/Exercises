// system includes
#include <iostream>

// global namespace declaration
using namespace std;

#include "CPoint.h"
#include "CShape.h"


int main ()
{
	CPoint p(3,4);
	double x, y;

	p.SetCoord( 10, 20);
	p.GetCoord( x, y);
	cout << x << y << "\n";

	CShape	pp;

	return 0;
}