// system includes
#include <iostream>
#include <fstream>


// project includes
#include "CImage.h"


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
	ifstream	imgInput( "Test.ppm", ios_base::binary );

	//data reading from file

	string headInutile;
	imgInput >> headInutile;

	unsigned int imgWidth, imgHeight;
	imgInput >> imgWidth >> imgHeight;
	
	int inutile2;
	imgInput >> inutile2;

	char ch;
	imgInput.get(ch);

	//Image dimensions check

	int currPos = imgInput.tellg();
	imgInput.seekg( 0, ios_base::end );
	int endPos = imgInput.tellg();
   imgInput.seekg( currPos, ios_base::beg ); 

	int	imgBpp(1); 
	int	imgNChan(3); 
	int	streamSizeNum = imgWidth*imgHeight*imgBpp*imgNChan;

	if ( endPos - currPos != streamSizeNum )
		cout << "Image dimension error!" << endl;
	else
		cout << "Image dimensions are correct" << endl;

	char* myBuffer= new char[streamSizeNum];
	imgInput.read( myBuffer, streamSizeNum );

	//stting-up image from data

	CImage* myImg= new CImage( imgWidth, imgHeight, "TL", imgNChan, "rgb" );

	vector< unsigned char > pixVec;

	for (int row=1; row != myImg->GetHeight()+1 ; ++row)
	{
		for (int col=1; col != myImg->GetWidth()+1 ; ++col)
		{
			pixVec.resize(0);
			for (int k=0; k!= imgNChan; ++k)
			{
				pixVec.push_back( *(myBuffer+(( row-1 )*myImg->GetWidth() 
									+( col-1 ))*myImg->GetNChannel()*imgBpp+k ));
			}
			myImg->SetPix( row, col, pixVec);
		}
	}

	delete[] myBuffer;

	return myImg;
}

// --------------------------------------------------------------------------
//	 SaveToFile
// --------------------------------------------------------------------------

bool	
CImage::SaveToFile()
{
	ofstream	imgOutput( "Test2.ppm", ios_base::binary );

	//data writing to file

	imgOutput << "P6";
	imgOutput << '\n';

	imgOutput << mWidth << " " << mHeight;
	imgOutput << '\n';

	imgOutput << "255";
	imgOutput << '\n';
	
	imgOutput.write( reinterpret_cast< char* > ( mPtr ), mISize );

	return true;
}

