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
CImage::GetPix( unsigned int inX, unsigned int inY, vector< unsigned char >& inVec  )
{
	inVec.resize(0);
	if ( (inX >= mWidth) || (inY >= mHeight) )
		return false;		
		
	unsigned char*	tempPtr= mPtr + ( inY*mWidth + inX )*mNChannel*mBpp;
	for (int i=0; i != mNChannel*mBpp; ++i)
		inVec.push_back(*(tempPtr+i));
					
	return true;

}

// --------------------------------------------------------------------------
//	 SetPix
// --------------------------------------------------------------------------

bool
CImage::SetPix( unsigned int inX, unsigned int inY, vector< unsigned char >& inVec  )
{
	if ( (inX >= mWidth) || (inY >= mHeight) || inVec.size()!= mNChannel )
		return false;		
		
	unsigned char* tempPtr= mPtr + ( inY*mWidth + inX )*mNChannel*mBpp;
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
	
	for ( int i=0; i != mWidth*mHeight; ++i )
	{
        for ( int k=0; k != mNChannel; ++k )
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
	ifstream	imgInput( "prova.ppm", ios_base::binary );

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
	{
		cout << "Image dimension error!" << endl;
		return NULL;
	}
	else
	{	
		cout << "Image dimensions are correct" << endl;

		char* myBuffer= new char[streamSizeNum];
		imgInput.read( myBuffer, streamSizeNum );

		//stting-up image from data

		CImage* myImg= new CImage( imgWidth, imgHeight, "TL", imgNChan, "rgb" );

		vector< unsigned char > pixVec;

		for (unsigned int y=0; y < myImg->GetHeight() ; ++y)
		{
			for (unsigned int x=0; x < myImg->GetWidth() ; ++x)
			{
				pixVec.resize(0);
				for (int k=0; k!= imgNChan; ++k)
				{
					pixVec.push_back( *(myBuffer+( y *myImg->GetWidth() 
										+ x )*myImg->GetNChannel()*imgBpp+k ));
				}
				myImg->SetPix( x, y, pixVec);
			}
		}

		delete[] myBuffer;
	
		return myImg;
	}
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

// --------------------------------------------------------------------------
//	 CopyImg
// --------------------------------------------------------------------------

bool
CImage::CopyImg( CImage& outImg, const CRect inRecSrc, const CRect inRecDst)
{
	CRect recInImg ( CPoint(0,0), CPoint( mWidth, mHeight ) );
	CRect recOutImg( CPoint(0,0), CPoint( outImg.GetWidth(), outImg.GetHeight()) );

	double rWidthRatio (inRecSrc.GetWidth()/inRecDst.GetWidth());
	double rHeightRatio (inRecSrc.GetHeight()/inRecDst.GetHeight());

	bool checkInside1=  recInImg.Inside(inRecSrc) && 
						recInImg.Inside(inRecSrc);

	bool checkInside2=  recOutImg.Inside(inRecDst) && 
						recOutImg.Inside(inRecDst);

	//bool checkDimRects=
	//( (inRecSrc.GetRB().GetX()-inRecSrc.GetLT().GetX()) ==
	//  (inRecDst.GetRB().GetX()-inRecDst.GetLT().GetX()) ) &&
	//( (inRecSrc.GetRB().GetY()-inRecSrc.GetLT().GetY()) ==
	//  (inRecDst.GetRB().GetY()-inRecDst.GetLT().GetY()) );

	if ( checkInside1 && checkInside2 )
	{
		vector< unsigned char >  myVec;
		for (int	x = static_cast< int > ( inRecDst.GetLT().GetX() ); 
					x <  inRecDst.GetRB().GetX() ; ++x )
		{
			for (int	y = static_cast< int > (inRecDst.GetLT().GetY() ); 
						y <  inRecDst.GetRB().GetY() ; ++y )
			{
				GetPix ( static_cast< int > ((( rWidthRatio-1 )/ 2 + ( x-inRecDst.GetLT().GetX())*rWidthRatio ) + inRecSrc.GetLT().GetX() + 0.5 ), 
							static_cast< int > ((( rHeightRatio-1 )/ 2 + ( y-inRecDst.GetLT().GetY())*rHeightRatio ) + inRecSrc.GetLT().GetY() + 0.5 ), 
							myVec );
				outImg.SetPix( x, y , myVec );
			}
		}
		return true;
	}
	else
	{
		cout << "\nPARAMETRI NON CORRETTI\n\n";
		return false;
	}
}


// --------------------------------------------------------------------------
//	Draw()
// --------------------------------------------------------------------------
void
CImage::Draw()
{
	vector< unsigned char > myVec;
	
	for( int myY=0; myY < mHeight; ++myY )
	{
		for ( int myX=0; myX < mWidth; ++myX )
		{
			this->GetPix( myX, myY, myVec );		
			vector< unsigned char >::const_iterator myIter;
			//cout << "[";
			for ( myIter = myVec.begin(); myIter != myVec.end(); ++myIter )
				cout << *myIter << " ";
			cout << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
	return;
}

