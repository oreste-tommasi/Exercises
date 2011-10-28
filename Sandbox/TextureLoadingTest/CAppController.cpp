#include "CAppController.h"
#include "glut.h"
#include "Timer.h"
#include <stdio.h>

// --------------------------------------------------------------------------
//	 CAppController []
// --------------------------------------------------------------------------
/**
* \brief
**/

CAppController::CAppController()
:mFrameCount(0)
,mTextureCount(0)
ST_ONLY(,mCurrentTextureNumber(0))
{
	PBO_ONLY(mData = NULL;)
}

// --------------------------------------------------------------------------
//	 CAppController []
// --------------------------------------------------------------------------
/**
* \brief
**/

CAppController::~CAppController()
{

}
// --------------------------------------------------------------------------
//	 GetInstance [static ]
// --------------------------------------------------------------------------
/**
* \brief
* \returns CAppController&
**/
CAppController&
CAppController::GetInstance()
{
	static CAppController staticObj;
	return staticObj;
}

// --------------------------------------------------------------------------
//	 Run []
// --------------------------------------------------------------------------
/**
* \brief
* \returns int
**/
int
CAppController::Run( int argc, char** argv )
{
	glutInit(&argc,argv);
	glutInitDisplayMode( /*GLUT_DEPTH |*/
#ifdef VSYNC
		GLUT_DOUBLE|
#endif
		GLUT_RGB | GLUT_ALPHA );
#ifdef FULL_SCREEN
	glutGameModeString( "1440x900:32@75" );
	glutEnterGameMode();
#else
	glutInitWindowSize(800, 600);
	glutInitWindowPosition( 0, 0);
	glutCreateWindow( "Texture loading Test" );
#endif

	glewInit();
	mDeviceContext = wglGetCurrentDC();
	mLoadingGlContext =  wglCreateContext(mDeviceContext);

	wglShareLists(wglGetCurrentContext(),mLoadingGlContext);
	
	glutDisplayFunc(CAppController::Display_Glut);
	glutIdleFunc(CAppController::Idle_Glut);

	Init();

	glutMainLoop();
	return 0;
}

// --------------------------------------------------------------------------
//	 Idle_Glut [static ]
// --------------------------------------------------------------------------
/**
* \brief
* \returns void
**/
void
CAppController::Idle_Glut()
{
/*	static bool render;
	render = !render;
	if (!render)
	{
	}*/
	GetInstance().SetupScene();
	glutPostRedisplay();
	//Sleep(100);
}



// --------------------------------------------------------------------------
//	 Display []
// --------------------------------------------------------------------------
/**
* \brief
* \returns void
**/
void
CAppController::Display()
{
#ifdef NO_RENDER
	PrintFramerate();
	return;
#endif
	/*static bool render;
	render = !render;
	if (render)
	{
		glutSwapBuffers();
		return;
	}*/
	
	const GLfloat square[4][3] = {
		{ 0,0,0 },
		{ 1,0,0 },
		{ 0,1,0 },
		{ 1,1,0 }
	};

	const GLfloat coord[4][2] = {
		{ 0,0 },
		{ 1,0 },
		{ 0,1 },
		{ 1,1 }
	};
#ifdef USE_VBO
	if (!mVbo)
	{
		glGenBuffers(1,&mVbo);
		glBindBuffer(GL_ARRAY_BUFFER,mVbo);
		glEnableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		glClientActiveTexture(GL_TEXTURE0);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);  
		int quarantotto = sizeof(square);
		glBufferData(GL_ARRAY_BUFFER,quarantotto,&square[0][0],GL_STATIC_DRAW);
	}
#endif

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-0.25,1.25,-0.25,1.25);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

#ifdef USE_VBO
	glVertexPointer(3,GL_FLOAT,0,0);
	glTexCoordPointer(2,GL_FLOAT,12,0);
#else
	glVertexPointer(3,GL_FLOAT,0,&square[0][0]);
	glTexCoordPointer(2,GL_FLOAT,12,&square[0][0]);
	//glTexCoordPointer(2,GL_FLOAT,0,&coord[0][0]);
#endif
/*glBegin(GL_TRIANGLE_STRIP);
	glTexCoord2fv(coord[0]);
	glVertex3fv(square[0]);
	glTexCoord2fv(coord[1]);
	glVertex3fv(square[1]);
	glTexCoord2fv(coord[2]);
	glVertex3fv(square[2]);
	glTexCoord2fv(coord[3]);
	glVertex3fv(square[3]);
glEnd();*/
	glDrawArrays(GL_TRIANGLE_STRIP,0,4);

	//glFinish();
	glutSwapBuffers();
	PrintFramerate();
	//voglio fare una sleep perche' non sono malato di mente
#if !defined(VSYNC) && defined(USE_THREADS)
	Sleep(5);
#endif

}


// --------------------------------------------------------------------------
//	 PrintFramerate []
// --------------------------------------------------------------------------
/**
* \brief
* \returns void
**/
void
CAppController::PrintFramerate()
{
	static Timer mTimer;
	if (!mFrameCount)
	{
		mTimer.start();
	}

#ifdef NO_RENDER
#define kMeanOver 1000
#elif defined(VSYNC)
#define kMeanOver 100
#else
#define kMeanOver 500
#endif
	if (!(++mFrameCount % kMeanOver) )
	{
		mTimer.stop();
		double totalRenderTime = mTimer.getElapsedTimeInMilliSec();
		double renderingTime = totalRenderTime/(1.0 *kMeanOver);
		double textureLoadingTime = totalRenderTime/(1.0 * mTextureCount);
		printf("Frame %lu, mean time: %.2lf msec framerate: %.1lf" " textures loaded:%lu, texture bandwidth:%.2lf Mb/s" "\n"
			, mFrameCount
			,renderingTime,1000./renderingTime 
			,mTextureCount
			,mTextureCount*TEXTURE_SIDE * TEXTURE_SIDE * 4.0 / (1048576.0 *textureLoadingTime) 
			);
		mTextureCount = 0;
		mTimer.start();
	}
}


// --------------------------------------------------------------------------
//	 SetupScene []
// --------------------------------------------------------------------------
/**
* \brief
* \returns void
**/
void
CAppController::SetupScene()
{

	MT_ONLY(GLuint texture = 0; )//texture index to be loaded next frame

#ifdef USE_THREADS
	//check for new textures.
#ifdef NO_RENDER
mTextures.
		FQ_ONLY(BeginPop(0))
		SQ_ONLY(blocking_pop_front(&texture,1));
#else
	while( mTextures.
		FQ_ONLY(BeginPop(1))
		SQ_ONLY(try_pop_front(&texture)) )
#endif
	{
		FQ_ONLY(texture = mTextures.PopItem();)
		glBindTexture(GL_TEXTURE_2D,texture);
		mTextureCount++;//for statistics
		SQ_ONLY( mUsedTextures.push_back(texture);)
		FQ_ONLY( mTextures.EndPop();)
	}

#else
	///load image in current texture
#ifdef USE_PBO
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER,mBuffer);
	glBufferData(GL_PIXEL_UNPACK_BUFFER,TEXTURE_SIDE*TEXTURE_SIDE*4,0,GL_STREAM_DRAW);///< discards old buffer
	mData = (int*)glMapBuffer(GL_PIXEL_UNPACK_BUFFER,GL_WRITE_ONLY);
#endif
	this->MakeTexture( (GLubyte*)mData);
	PBO_ONLY(glUnmapBuffer(GL_PIXEL_UNPACK_BUFFER);)
	PBO_ONLY(mData = NULL;)
	glTexSubImage2D(GL_TEXTURE_2D,0,0,0,TEXTURE_SIDE,TEXTURE_SIDE,GL_BGRA,GL_UNSIGNED_BYTE,mData);
	PBO_ONLY(glBindBuffer(GL_PIXEL_UNPACK_BUFFER,0);)
	//and show the other one
	mCurrentTextureNumber = 1-mCurrentTextureNumber;

	glBindTexture(GL_TEXTURE_2D,mTextures[mCurrentTextureNumber]);
	mTextureCount++;
#endif


}

// --------------------------------------------------------------------------
//	 MakeTexture []
// --------------------------------------------------------------------------
/**
* \brief
* \returns void
**/
void
CAppController::MakeTexture( GLubyte* outBuffer )
{
#ifdef BLACK_TEXTURE
	return;
#endif
	unsigned int *rgbadata = reinterpret_cast<unsigned int*>(outBuffer);
	static unsigned long long int sSeed = 1;
	static unsigned long long int sSeed2 = 1;

	unsigned int seed = sSeed;
	unsigned int seed2 = sSeed2;
// 	memset(outBuffer,sSeed++%0xff,TEXTURE_SIDE*TEXTURE_SIDE*4);
// 	return;
	for (int i = 0; i<TEXTURE_SIDE;i++)
	{
	for (int j = 0; j<TEXTURE_SIDE;j++)
		{
// 			seed+=4398050705407;
// 			seed+=523347633027360537213687137;
// 			seed+=0x11A05561;
// 			seed+=0x8E02B2911A05561;
// 			*(rgbadata++) = 0xff0000ff;
			//seed = 18000 * (seed & 0xffff) + (seed >> 16);
// 			unsigned int blue = (seed & 0xf) * 0x11;
// 			unsigned int green  = (seed & 0xf0) * 0x110;
// 			unsigned int red = (seed & 0xf00) * 0x1100;
// 			unsigned int alpha = 0;
//  			*(rgbadata++) = alpha + red + green + blue;
			*(rgbadata++) = seed++;
			/*int tmp = seed;
			seed = seed2;
			seed2 = seed2 + tmp;*/
		}
	}
	sSeed = seed;
	sSeed2 = seed2;
}

// --------------------------------------------------------------------------
//	 LoadLoop []
// --------------------------------------------------------------------------
/**
* \brief
* \returns NULL
**/
void *
CAppController::LoadLoop()
{
	wglMakeCurrent(mDeviceContext,mLoadingGlContext);
	GLsync mSyncObj = NULL;
	GLuint texture = 0;
	while (1)
	{
		PBO_ONLY(glBindBuffer(GL_PIXEL_UNPACK_BUFFER,mBuffer);)
		PBO_ONLY(glBufferData(GL_PIXEL_UNPACK_BUFFER,TEXTURE_SIDE*TEXTURE_SIDE*4,0,GL_STREAM_DRAW);)///< discards old buffer
		PBO_ONLY(mData = (int*)glMapBuffer(GL_PIXEL_UNPACK_BUFFER,GL_WRITE_ONLY);)
		MakeTexture((GLubyte*)mData);//writes texture data on buffer
		PBO_ONLY(glUnmapBuffer(GL_PIXEL_UNPACK_BUFFER);)
		PBO_ONLY(mData = 0;)
#ifdef USE_FASTQUEUE
		mTextures.BeginPush();
		texture = mTextures.PushItem();
#else
		texture = mUsedTextures.blocking_pop_front();
#endif
		glBindTexture(GL_TEXTURE_2D,texture);
		glTexSubImage2D(GL_TEXTURE_2D,0,0,0,TEXTURE_SIDE,TEXTURE_SIDE,GL_BGRA,GL_UNSIGNED_BYTE,mData);
		glBindTexture(GL_TEXTURE_2D,0);
		PBO_ONLY(glBindBuffer(GL_PIXEL_UNPACK_BUFFER,0);)
		if(GLEW_ARB_sync)
		{
			if (mSyncObj)
			{
				//glFlush();//ensures flushing of fence \todo: check if it's better to flush later, or to flush just after fence is sent to hardware. It is necessary to flush?
				while( GL_TIMEOUT_EXPIRED  == glClientWaitSync(mSyncObj,GL_SYNC_FLUSH_COMMANDS_BIT, 100e6))//wait for glTexSubImage2d to complete
				{
					//yay!;
				}
				glDeleteSync(mSyncObj);
#ifdef USE_FASTQUEUE
				mTextures.EndPush();//
#else
				mTextures.push_back(texture);
#endif
			}
			mSyncObj = glFenceSync(GL_SYNC_GPU_COMMANDS_COMPLETE,0);//pushes another fence
		}
		else
		{
			glFinish();
#ifdef USE_FASTQUEUE
			mTextures.EndPush();//
#else
			mTextures.push_back(texture);
#endif
		}
	}
	wglMakeCurrent(NULL,NULL);
	return NULL;
}
// --------------------------------------------------------------------------
//	 Init []
// --------------------------------------------------------------------------
/**
* \brief
* \returns void
**/
void
CAppController::Init()
{
	GLuint texture;

	glEnableClientState( GL_TEXTURE_COORD_ARRAY );
	glEnableClientState( GL_VERTEX_ARRAY );

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glEnable(GL_TEXTURE_2D);

	glColor4f(0,1,1,1);
	glClearColor(0.4,0.6,0.7,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

#ifdef USE_PBO
	glGenBuffers(1,&mBuffer);
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER,mBuffer);
	glBufferData(GL_PIXEL_UNPACK_BUFFER, TEXTURE_SIDE*TEXTURE_SIDE*4, 0, GL_STREAM_DRAW);
	mData = (int*)glMapBuffer(GL_PIXEL_UNPACK_BUFFER,GL_WRITE_ONLY);
#endif

	this->MakeTexture((GLubyte*)mData);
#ifdef USE_PBO
	glUnmapBuffer(GL_PIXEL_UNPACK_BUFFER);
	mData = NULL;
	glBindBuffer(GL_PIXEL_UNPACK_BUFFER,0);
#endif

	FQ_ONLY(glGenTextures(kTextureQueueSize,&mTextures[0]); )

	for (int i = 0;i<kTextureQueueSize;i++)
	{

		FQ_ONLY(texture = mTextures[i];)
		SQ_ONLY(glGenTextures(1,&texture);)
		SQ_ONLY(mUsedTextures.push_back(texture);)
		glBindTexture(GL_TEXTURE_2D,texture);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,TEXTURE_SIDE,TEXTURE_SIDE,0,GL_RGBA,GL_UNSIGNED_BYTE,0);
	}

	//start loading thread. Wait for first texture to be ready
#ifdef USE_THREADS
	pthread_create(&mLoadingThread,0,CAppController::ThreadFunc,this);
		gmcu::ThreadSetPriority(mLoadingThread,SCHED_OTHER,sched_get_priority_min(SCHED_OTHER));
		gmcu::ThreadSetPriority(pthread_self(),SCHED_OTHER,sched_get_priority_max(SCHED_OTHER));
	FQ_ONLY(mTextures.BeginPop();)
	FQ_ONLY(texture = mTextures.PopItem();)
	SQ_ONLY(mCurrentTexture = texture = mTextures.blocking_pop_front());
	glBindTexture(GL_TEXTURE_2D,texture);
#endif

}