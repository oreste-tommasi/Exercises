#ifndef CPOINT_H
#define CPOINT_H

// external include
#include "xmlParser.h"

// project include
#include "CShape.h"

class CPoint : public CShape 
{
public:
	CPoint( double inX, double inY );
	~CPoint();

	void			SetCoord( double inX, double inY );
	void			GetCoord( double& outX, double& outY ) const;
	//void			GetCoord2( double outX, double outY ); // errata
	double			GetX() const { return mX; } 
	double			GetY() const { return mY; }
	static CShape*	CreateFromXml( XMLNode& currNode );//aggiunto
	
	virtual void	Draw() const;
	virtual void	SaveXml ( XMLNode& inNode );
	//static CPoint* CreateFromXml(XMLNode inNode); 

private: 
	double	mX;
	double	mY;
};


#endif // CPOINT_H

