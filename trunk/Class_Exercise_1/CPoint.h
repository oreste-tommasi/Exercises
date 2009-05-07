#ifndef CPOINT_H
#define CPOINT_H


class CPoint 
{
public:
	CPoint( double inX, double inY );
	~CPoint();

	void		SetCoord( double inX, double inY );
	void		GetCoord( double& outX, double& outY );
	//void		GetCoord2( double outX, double outY ); // errata

	void		Draw();

private: 
	double	mX;
	double	mY;
};


#endif // CPOINT_H

