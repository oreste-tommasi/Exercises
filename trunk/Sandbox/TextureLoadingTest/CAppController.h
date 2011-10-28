#ifndef CAppController_H
#define CAppController_H

#include "OpenGl_Ext/gl/glew.h"
#include "OpenGl_Ext/gl/wglew.h"

#include "gmcuThread.h"
#include "CSem.h"
#include "test_profiles.h"

#define TEXTURE_SIDE 1024

#ifndef TEST_PROFILE
#define USE_FASTQUEUE
//#define USE_THREADS
#define USE_PBO
#define USE_VBO
#define FULL_SCREEN
#define VSYNC
#define BLACK_TEXTURE
#define NO_RENDER
#endif

#ifdef USE_PBO
#define PBO_ONLY(...) __VA_ARGS__ 
#define DPTR_ONLY(...)
#else
#define PBO_ONLY(...)
#define DPTR_ONLY(...) __VA_ARGS__ 
#endif

#ifdef USE_VBO
#define VBO_ONLY(...) __VA_ARGS__ 
#else
#define VBO_ONLY(...)
#endif


#ifdef USE_THREADS
#define MT_ONLY(...) __VA_ARGS__ 
#define ST_ONLY(...) 
#else
#define MT_ONLY(...)
#define ST_ONLY(...) __VA_ARGS__ 
#endif

#ifdef USE_FASTQUEUE
#define FQ_ONLY(...) __VA_ARGS__ 
#define SQ_ONLY(...) 
#include "CFastQueue.h"
#else
#define FQ_ONLY(...)
#define SQ_ONLY(...) __VA_ARGS__ 
#include "CTSafeQueue.h"
#endif


class CAppController
{
	CAppController();
	~CAppController();
	static void Display_Glut() { GetInstance().Display();}
	static void Idle_Glut();

	void	PrintFramerate();
	void	Display();
	void	SetupScene();
	void	Init();
 
	PBO_ONLY(GLuint	mBuffer;) //PBO
	VBO_ONLY(GLuint   mVbo;)

	ST_ONLY(int	mCurrentTextureNumber;)
	SQ_ONLY(GLuint mCurrentTexture);
	unsigned long int	mTextureCount;
	unsigned long int mFrameCount;

	//shared data between threads
	static const int kTextureQueueSize = 16;//max number of textures loaded per frame = kTextureQueueSize-1 since 1 is always kept locked by rendering thread;
	gmcu::Thread mLoadingThread;

	FQ_ONLY(CFastQueue<GLuint,kTextureQueueSize>	mTextures;)
	SQ_ONLY(gmcu::CTSafeQueue<GLuint>	mTextures;)
	SQ_ONLY(gmcu::CTSafeQueue<GLuint>	mUsedTextures;)

	PBO_ONLY(int* mData;)
	DPTR_ONLY(int mData[TEXTURE_SIDE*TEXTURE_SIDE];)
	//loading thread data
	int		mNextFreeSlotIdx;//< working thread updates this value to allow 
	static void* ThreadFunc(void* inThis) { return reinterpret_cast<CAppController*>(inThis)->LoadLoop(); }
	void MakeTexture(GLubyte* outBuffer);
	void* LoadLoop();
	HGLRC mLoadingGlContext;
	HDC	mDeviceContext;
public:
	int Run(int argc, char** argv);
	static CAppController& GetInstance(); 
};

#endif
