// system includes
#include <iostream>
#include <fstream>
#include <string>
#include <vector>



// project includes
#include "CImage.h"
#include "mymath.h"
//#include "CRect.h"

// global namespace declaration
using namespace std;

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
//	 CImage
// --------------------------------------------------------------------------

CImage::CImage ( const char* inFileName )
: mOrigin( "LT" )
, mBpp(1)
, mNChannel(3)
, mCModel( "rgb" )
{	ifstream fileInput ( inFileName, ios_base::binary );
	
	//data reading from file
	string headInutile;
	fileInput >> headInutile;

	fileInput >> mWidth >> mHeight;
	
	int inutile2;
	fileInput >> inutile2;

	char ch;
	fileInput.get(ch);

    //Image dimensions check

	int currPos = fileInput.tellg();
	fileInput.seekg( 0, ios_base::end );
	int endPos = fileInput.tellg();
	fileInput.seekg( currPos, ios_base::beg ); 



	mISize = mWidth*mHeight*mBpp*mNChannel;

	if ( endPos - currPos != mISize )
	{
		cout << "Image dimension error!" << endl;	

	}
	else
	{		
		mPtr= new unsigned char[mISize];
		fileInput.read( reinterpret_cast< char* >(mPtr), mISize );
	}
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

		//setting-up image from data

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
//	 GetPix
// --------------------------------------------------------------------------

bool
CImage::GetPix( unsigned int inX, unsigned int inY, vector< unsigned char >& inVec  ) const
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
//	 SaveToFile
// --------------------------------------------------------------------------

bool	
CImage::SaveToFile( const char* inFileName )
{
	ofstream	imgOutput( inFileName, ios_base::binary );

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
CImage::CopyImg( CImage& outImg, const CRect inRecSrc, const CRect inRecDst) const
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
				GetPix ( round_Int((( rWidthRatio-1 )/ 2 + ( x-inRecDst.GetLT().GetX())*rWidthRatio ) + inRecSrc.GetLT().GetX() ), 
							round_Int((( rHeightRatio-1 )/ 2 + ( y-inRecDst.GetLT().GetY())*rHeightRatio ) + inRecSrc.GetLT().GetY()  ), 
							myVec );
				outImg.SetPix( x, y , myVec );
			}
		}
		return true;
	}
	else
	{
		cout << "\nNessuna copia effettuata,\nalmeno un rettangolo è esterno\n\n";
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

// --------------------------------------------------------------------------
//	Clipping()
// --------------------------------------------------------------------------

void
CImage::Clipping( CImage& inImgDst, const CRect& inRecSrc, const CRect& inRecDst )
{	
	CRect myDstInters( CPoint(0,0), CPoint(0,0) );
	myDstInters = inRecDst.RClipping( inImgDst.ImgBoundRect() );
	vector<CPoint> myInPoints;
	vector<CPoint> myOutPoints;

	myInPoints.push_back( myDstInters.GetLT() );
	myInPoints.push_back( myDstInters.GetRB() );

	inRecDst.MapPoints( inRecSrc, myInPoints, myOutPoints );

	CRect mySrcRect( myOutPoints[0], myOutPoints[1] );
	
	mySrcRect = mySrcRect.RClipping( this->ImgBoundRect() ); //questo è il rect buono per la copia

	//myInPoints.resize(0); // vuole un costruttore di default
	myInPoints.pop_back();
	myInPoints.pop_back();
	myOutPoints.clear(); 
	//myOutPoints.pop_back();
	//myOutPoints.pop_back();

	myInPoints.push_back( mySrcRect.GetLT() );
	myInPoints.push_back( mySrcRect.GetRB() );

	inRecSrc.MapPoints( inRecDst, myInPoints, myOutPoints );

	this->CopyImg( inImgDst, mySrcRect, CRect( myOutPoints[0], myOutPoints[1] ) );

	return;
}


	

