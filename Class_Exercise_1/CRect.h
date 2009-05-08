#ifndef CRECT_H
#define CRECT_H


// project includes
#include "CPoint.h"

class CRect
{
public:
	CRect( const CPoint& inP1, const CPoint& inP2 );
	~CRect();

	void	SetExtremes( const CPoint& inP1, const CPoint& inP2 );
	void	GetExtremes( CPoint& outLT, CPoint& outRB );
	void	Shift( const CPoint& inPShift );
	bool 	Intersect( const CRect& inRect );
	bool 	Inside( const CPoint& inP );
	CPoint	GetLT() const { return mLT; };
	CPoint	GetRB() const { return mRB; };

private: 
	CPoint mLT;
	CPoint mRB;
	
};


#endif // CRECT_H
