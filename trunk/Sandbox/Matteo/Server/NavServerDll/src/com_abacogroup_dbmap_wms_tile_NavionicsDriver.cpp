
#include "com_abacogroup_dbmap_wms_tile_NavionicsDriver.h"
#include "NavServer.h"

/*
 * Class:     com_abacogroup_dbmap_wms_tile_NavionicsDriver
 * Method:    init
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_abacogroup_dbmap_wms_tile_NavionicsDriver_init
  (JNIEnv *, jobject, jstring)
{
	NServ_Init();
}

/*
 * Class:     com_abacogroup_dbmap_wms_tile_NavionicsDriver
 * Method:    getTile
 * Signature: (IFFFF)[B
 */
jint JNICALL Java_com_abacogroup_dbmap_wms_tile_NavionicsDriver_getTile
												( JNIEnv *env, jobject, 
												  jint inSide, jfloat inW, 
												  jfloat inS, jfloat inE, 
												  jfloat inN, jbyteArray outBA)
{
	NGeoRect geoRect;
	geoRect.mWest	= inW;
	geoRect.mSouth	= inS;
	geoRect.mEast	= inE;
	geoRect.mNorth	= inN;

	NImage theImage;
	theImage.mSize.mWidth	= inSide;
	theImage.mSize.mHeight	= inSide;
	theImage.mChannelCount	= 4;
	theImage.mBuffer			= 0;

	// buffer
	jint			err;
	jboolean		isVerCopy;
	jbyte*		imageBuffer = env->GetByteArrayElements( outBA, &isVerCopy );

	if ( imageBuffer )
	{
		theImage.mBuffer = (unsigned char*) imageBuffer;
		err = NServ_GetImage( geoRect, &theImage );
	}
	else
		err = kNSerErr_OutOfMemory;

	if ( isVerCopy )
		env->ReleaseByteArrayElements( outBA, imageBuffer, 0 ); 

	return err;
}
