// system includes


// project includes
#include "CImage.h"

// global namespace declaration


// --------------------------------------------------------------------------
//	 CImage
// --------------------------------------------------------------------------

CImage::CImage (unsigned int inW, unsigned int inH, 
				const string& inOrig, int inNChan, 
				const string& inCMod ) 
: 	mWidth(inW)
,	mHeight(inH)
,	mOrigin(inOrig)
,	mNChannel(inNChan)
,	mBpp(1)
,	mCModel(inCMod)
,   mPtr(0) 
,	mISize(inW*inH*inNChan*mBpp ) 
{
	mPtr= new unsigned char[mISize];
}

// --------------------------------------------------------------------------
//	 GetPix
// --------------------------------------------------------------------------
bool
CImage::GetPix( unsigned int inRow, unsigned int inCol, vector< unsigned char >& inVec  )
{
	inVec.resize(0);
	if ( (inCol > mWidth) || (inRow > mHeight) )
		return false;		
		
	unsigned char*	tempPtr= mPtr + ((inRow-1)*mWidth + (inCol-1))*mNChannel*mBpp;
	for (int i=0; i != mNChannel*mBpp; ++i)
		inVec.push_back(*(tempPtr+i));
					
	return true;

}

// --------------------------------------------------------------------------
//	 SetPix
// --------------------------------------------------------------------------

bool
CImage::SetPix( unsigned int inRow, unsigned int inCol, vector< unsigned char >& inVec  )
{
	if ( (inCol > mWidth) || (inRow > mHeight) || inVec.size()!= mNChannel )
		return false;		
		
	unsigned char* tempPtr= mPtr + ((inRow-1)*mWidth + (inCol-1))*mNChannel*mBpp;
	vector< unsigned char >::iterator myIter=inVec.begin();
	
	for (int i=0; i != mNChannel*mBpp; ++i, ++myIter)
	{
		(*(tempPtr+i))=*(myIter);
	}
	return true;

}

// --------------------------------------------------------------------------
//	 Fill
// --------------------------------------------------------------------------

bool
CImage::Fill( vector< unsigned char >& inColour )
{
	if ( inColour.size()!= mNChannel )
		return false;		
	
	for (int i=0; i != mWidth*mHeight; ++i )
	{
		for (int k=0; k != mNChannel; ++k)
			(*(mPtr+i*mNChannel+k))=inColour[k];
	}
	return true;
}

// --------------------------------------------------------------------------
//	 CreateFromFile
// --------------------------------------------------------------------------

CImage*	
CImage::CreateFromFile( )
{
	ifstream	fileInput( "image.ppm" );
	string header;
	int theWidth, theHeight, theColour;
	string data;

	// insert controls

	fileInput >> theWidth;
	fileInput >> theHeight;
	fileInput >> theColour;
	fileInput >> data;

	//translate data in CImage sense
	return true;
}