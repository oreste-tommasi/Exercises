#include <string.h>
#include <jni.h>
#include <stdio.h>

int s_ButtonPressCounter = 0;

jstring
Java_com_geomind_geoflyer_sampleapp_FullscreenActivity_stringFromJNI(JNIEnv* env, jobject thiz)
{
    char szBuf[512];
    sprintf(szBuf, "%d", s_ButtonPressCounter++);

    jstring str = (*env)->NewStringUTF(env, szBuf);
    return str;
}