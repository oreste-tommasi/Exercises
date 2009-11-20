// Simple test of the NavServerDll.

// system includes
#include <iostream>

// project includes
#include "NavServer.h"
#include "com_abacogroup_dbmap_wms_tile_NavionicsDriver.h"


// private output functions

using namespace std;

// -------------------------------------------------------------------------------
// MAIN FUNCTION
// -------------------------------------------------------------------------------
int 
main(int argc, char* argv[])
{
	int i;

	cout << "\n NavServer version: " << NAVSERVER_VERSION << "\n\n";

	if ( kNSerErr_NoErr != NServ_Init( ) )
		cout << "Error in NServ_Init\n";

	// prepare image query
	NGeoRect	bounds;
	NImage	image;

	bounds.mWest	= 3213320;
	bounds.mSouth	= 23133210;
	bounds.mNorth	= 32131210;
	bounds.mEast	= 321312310;

	image.mSize.mWidth	= 244;
	image.mSize.mHeight	= 244;
	image.mChannelCount	= 4;
	image.mBuffer			= (unsigned char*	) malloc (image.mSize.mWidth*image.mSize.mHeight*image.mChannelCount);

	if ( kNSerErr_NoErr != NServ_GetImage( bounds, &image ) )
		cout << "Error in NServ_GetImage\n";
	else
	{
		FILE* fd = fopen( "test.raw", "wb+");
		fwrite( image.mBuffer, 1, image.mChannelCount* image.mSize.mWidth * image.mSize.mHeight, fd);
		fclose( fd );
	}

	//bool testJni = true;
	//if ( testJni == true )
	//{
	//	jobject		obj = NULL;
	//	jbyteArray  bArr = Java_com_abacogroup_dbmap_wms_tile_NavionicsDriver_getTile(NULL, obj, 256, 0, 0, 1000, 1000);
	//
	//	FILE* fd = fopen( "test_jni.raw", "wb+");
	//	fwrite( bArr, 1, 4*256*256, fd);
	//	fclose( fd );
	//}

	cout << "\nPress Enter to exit\n";
	cin >> i;
}

