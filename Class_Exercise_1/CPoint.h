#ifndef CPOINT_H
#define CPOINT_H
#include "xmlParser.h"

class CPoint 
{
public:
	CPoint( double inX, double inY );
	~CPoint();

	void			SetCoord( double inX, double inY );
	void			GetCoord( double& outX, double& outY ) const;
	//void			GetCoord2( double outX, double outY ); // errata
	double			GetX() const { return mX; } 
	double			GetY() const { return mY; }
	static CPoint*	CreateFromXml( XMLNode& currNode );//aggiunto
	void			Draw();

	//static CPoint* CreateFromXml(XMLNode inNode); 

private: 
	double	mX;
	double	mY;
};


#endif // CPOINT_H

