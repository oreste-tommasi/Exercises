#ifndef CRECT_H
#define CRECT_H


// project includes
#include "CPoint.h"

// external include
#include "xmlParser.h"

class CRect : public CShape
{
public:
	CRect( const CPoint& inP1, const CPoint& inP2 );
	~CRect();

	void			SetExtremes( const CPoint& inP1, const CPoint& inP2 );
	void			GetExtremes( CPoint& outLT, CPoint& outRB );
	void			Shift( const CPoint& inPShift );
	bool 			Intersect( const CRect& inRect );
	bool 			Inside( const CPoint& inP );
	bool 			Inside( const CRect& inRect );
	CPoint			GetLT() const { return mLT; };
	CPoint			GetRB() const { return mRB; };
	void			Draw();
	static CShape*	CreateFromXml( XMLNode& inNode ); 

	virtual void	SaveXml ( XMLNode& inNode );


private: 
	CPoint mLT;
	CPoint mRB;
	
};


#endif // CRECT_H
