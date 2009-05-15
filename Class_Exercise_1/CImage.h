#ifndef CIMAGE_H
#define CIMAGE_H

// system includes
#include <string>
#include <vector>
#include <iostream>
// project includes
#include "CRect.h"

// global namespace declaration
using namespace std;


class CImage
{
public:
		
	CImage (	unsigned int inW, unsigned int inH, 
				const string& inOrig, int inNChan, 
				const string& inCMod ) ;

	
	CImage (	const char* inFileName	);




	virtual ~CImage() { delete[] mPtr; } 

	unsigned int		GetWidth() const { return mWidth; } 
	unsigned int		GetHeight() const { return mHeight; }
	string				GetOrigin() const { return mOrigin; }
	int					GetNChannel() const { return mNChannel; } 

	int					GetBpp() const { return mBpp; } 
	string				GetCModel() const { return mCModel; } 


	bool				GetPix( unsigned int inX, unsigned int inY, vector< unsigned char >& inVec ); 
	bool				SetPix( unsigned int inX, unsigned int inY, vector< unsigned char >& inVec  );
	bool				CopyImg( CImage& outImg, const CRect inRecSrc, const CRect inRecDst);
	CRect				ImgBoundRect(){ return CRect ( CPoint(0,0), CPoint( mWidth, mHeight ) ); }

	bool				Fill( vector< unsigned char >& inColour );
	static CImage*		CreateFromFile( );
	bool				SaveToFile();

	void				Draw();

	void				Clipping( const CRect& inRecSrc, const CImage& inImgDst, const CRect inRecDst );				

	

private: 
	unsigned int	mWidth;
	unsigned int	mHeight;
	string			mOrigin;
	int				mNChannel;
	int				mBpp; //Bytes per pixel
	string			mCModel;
	unsigned char*	mPtr;
	int				mISize;
	//int			mAlign;

};



#endif // CIMAGE_H