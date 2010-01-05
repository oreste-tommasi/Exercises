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

	//if ( kNSerErr_NoErr != NServ_Init( "conf.txt" ) )
	if ( kNSerErr_NoErr != NServ_Init( "X:\\NAV\\conf_x.txt" ) )
		//"E:\\Devel\\G7C_3D\\QtGeocore\\Sandbox\\Matteo\\Server\\exe\\conf.txt" ) )
	{
		cout << "Error in NServ_Init\n";
		return -1;
	}

	// prepare image query
	NGeoRect	bounds;
	NImage	image;

	bounds.mWest	= 1112864;
	bounds.mSouth	= 5417168;
	bounds.mEast	= 1132864;
	bounds.mNorth	= 5437168;

	image.mSize.mWidth	= 512; 
	image.mSize.mHeight	= 512;
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

	cout << "\nPress Enter to exit\n";
	cin >> i;
}

