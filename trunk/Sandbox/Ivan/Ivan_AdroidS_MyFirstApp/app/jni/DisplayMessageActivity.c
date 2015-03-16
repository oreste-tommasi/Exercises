/* DO NOT EDIT THIS FILE - it is machine generated */
#include "it_geomind_myfirstapp_DisplayMessageActivity.h"

/*
 * Class:     it_geomind_myfirstapp_DisplayMessageActivity
 * Method:    callNative
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_it_geomind_myfirstapp_DisplayMessageActivity_callNative
  (JNIEnv * env, jobject obj)
  {
    return (*env) -> NewStringUTF( env, "NDK Sample Test !" );
  }

/*
 * Class:     it_geomind_myfirstapp_DisplayMessageActivity
 * Method:    callNativeWithTextView
 * Signature: (Landroid/widget/TextView;)Ljava/lang/String;
 */
JNIEXPORT void JNICALL Java_it_geomind_myfirstapp_DisplayMessageActivity_callNativeWithTextView
( JNIEnv * env, jobject inDisplayMessageActivity, jobject inTextView )
{
	jclass cls = (*env)->GetObjectClass( env, inTextView );

	jmethodID mid = (*env)->GetMethodID( env, cls, "setText", "(Ljava/lang/CharSequence;)V" );
	if( mid == 0 )
		return;

	jstring str = (*env)->NewStringUTF( env, "AAABA!" );

	(*env)->CallVoidMethod( env, inTextView, mid, str );

	////////////////////////////////////////////////////////////////////

	jclass cls2 = (*env)->GetObjectClass( env, inDisplayMessageActivity );
	jmethodID mid2 = (*env)->GetMethodID( env, cls2, "showAlertDialog", "(Ljava/lang/String;Ljava/lang/String;)V" );

	jstring alertTitle = (*env)->NewStringUTF( env, "alert title" );
	jstring alertMsg = (*env)->NewStringUTF( env, "alert msg" );

	(*env)->CallVoidMethod( env, inDisplayMessageActivity, mid2, alertTitle, alertMsg );

	int gg = 0;
}