#ifndef CPOINT_H
#define CPOINT_H


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

	void			Draw();

private: 
	double	mX;
	double	mY;
};


#endif // CPOINT_H

