#ifndef CIMAGE_H
#define CIMAGE_H

// system includes
#include <string>
#include <vector>

// project includes

using namespace std;

class CImage
{
public:
		
	CImage ( unsigned int inW, unsigned int inH, 
				const string& inOrig, int inNChan, 
				const string& inCMod ) ;

	

	virtual ~CImage() { delete[] mPtr; } 

	unsigned int	GetWidth() const { return mWidth; } 
	unsigned int	GetHeight() const { return mHeight; }
	string			GetOrigin() const { return mOrigin; }
	int				GetNChannel() const { return mNChannel; } 
	
	int				GetBpp() const { return mBpp; } 
	string			GetCModel() const { return mCModel; } 
	

	bool			GetPix( unsigned int inRow, unsigned int inCol, vector< unsigned char >& inVec ); 
	bool			SetPix( unsigned int inRow, unsigned int inCol, vector< unsigned char >& inVec  );


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