// system includes
#include< vector >

// project includes
#include "CRect.h"
#include "CPolyLine.h"

bool FunctionNoPolymorphic();

bool ReadXml();

bool ReadXml2(	vector< CPoint* >& outPoints, 
				vector< CPolyLine* >& outPolyLines, 
				vector< CRect* >& outRects );
