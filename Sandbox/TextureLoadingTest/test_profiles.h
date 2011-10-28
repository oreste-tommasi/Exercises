#ifndef TEST_PROFILES_H
#define TEST_PROFILES_H

#define TEXTURE_BANDWIDTH 1
#define SINGLE_SYNC_NOPBO_NOVBO 2
#define SINGLE_SYNC_NOPBO_VBO 3
#define SINGLE_SYNC_PBO_NOVBO 4
#define SINGLE_SYNC_PBO_VBO 5
#define SINGLE_FREE_NOPBO_NOVBO 6
#define SINGLE_FREE_NOPBO_VBO 7
#define SINGLE_FREE_PBO_NOVBO 8
#define SINGLE_FREE_PBO_VBO 9
#define MULTI_SYNC_NOPBO_NOVBO 10
#define MULTI_SYNC_NOPBO_VBO 11
#define MULTI_SYNC_PBO_NOVBO 12
#define MULTI_SYNC_PBO_VBO 13
#define MULTI_FREE_NOPBO_NOVBO 14
#define MULTI_FREE_NOPBO_VBO 15
#define MULTI_FREE_PBO_NOVBO 16
#define MULTI_FREE_PBO_VBO 17
#define REALDATA_TEXTURE_BANDWIDTH 18
#define REALDATA_SINGLE_SYNC_NOPBO_NOVBO 19
#define REALDATA_SINGLE_SYNC_NOPBO_VBO 20
#define REALDATA_SINGLE_SYNC_PBO_NOVBO 21
#define REALDATA_SINGLE_SYNC_PBO_VBO 22
#define REALDATA_SINGLE_FREE_NOPBO_NOVBO 23
#define REALDATA_SINGLE_FREE_NOPBO_VBO 24
#define REALDATA_SINGLE_FREE_PBO_NOVBO 25
#define REALDATA_SINGLE_FREE_PBO_VBO 26
#define REALDATA_MULTI_SYNC_NOPBO_NOVBO 27
#define REALDATA_MULTI_SYNC_NOPBO_VBO 28
#define REALDATA_MULTI_SYNC_PBO_NOVBO 29
#define REALDATA_MULTI_SYNC_PBO_VBO 30
#define REALDATA_MULTI_FREE_NOPBO_NOVBO 31
#define REALDATA_MULTI_FREE_NOPBO_VBO 32
#define REALDATA_MULTI_FREE_PBO_NOVBO 33
#define REALDATA_MULTI_FREE_PBO_VBO 34


#define TEST_PROFILE REALDATA_TEXTURE_BANDWIDTH

#if TEST_PROFILE == TEXTURE_BANDWIDTH
//#define USE_THREADS //single thread
//#define USE_PBO
#define USE_VBO
//#define FULL_SCREEN
//#define VSYNC
#define BLACK_TEXTURE
#define NO_RENDER
#endif

#if TEST_PROFILE == REALDATA_TEXTURE_BANDWIDTH
//#define USE_THREADS //single thread
#define USE_PBO
#define USE_VBO
//#define FULL_SCREEN
//#define VSYNC
//#define BLACK_TEXTURE //put real texture data in it
#define NO_RENDER
#endif

//////////////////////////////////////////////////////////////////////////
// Single thread stuff
//////////////////////////////////////////////////////////////////////////

#if TEST_PROFILE == SINGLE_SYNC_NOPBO_NOVBO
//#define FULL_SCREEN
#define BLACK_TEXTURE
//#define USE_THREADS
#define VSYNC
//#define USE_PBO
//#define USE_VBO
//#define NO_RENDER
#endif

#if TEST_PROFILE == SINGLE_SYNC_NOPBO_VBO
//#define FULL_SCREEN
#define BLACK_TEXTURE
//#define USE_THREADS
#define VSYNC
//#define USE_PBO
#define USE_VBO
//#define NO_RENDER
#endif

#if TEST_PROFILE == SINGLE_SYNC_PBO_NOVBO
//#define FULL_SCREEN
#define BLACK_TEXTURE
//#define USE_THREADS
#define VSYNC
//#define USE_PBO
#define USE_VBO
//#define NO_RENDER
#endif

#if TEST_PROFILE == SINGLE_SYNC_PBO_VBO
//#define FULL_SCREEN
#define BLACK_TEXTURE
//#define USE_THREADS
#define VSYNC
#define USE_PBO
#define USE_VBO
//#define NO_RENDER
#endif

//////////////////////////////////////////////////////////////////////////

#if TEST_PROFILE == SINGLE_FREE_NOPBO_NOVBO
//#define FULL_SCREEN
#define BLACK_TEXTURE
//#define USE_THREADS
//#define VSYNC
//#define USE_PBO
//#define USE_VBO
//#define NO_RENDER
#endif

#if TEST_PROFILE == SINGLE_FREE_NOPBO_VBO
//#define FULL_SCREEN
#define BLACK_TEXTURE
//#define USE_THREADS
//#define VSYNC
//#define USE_PBO
#define USE_VBO
//#define NO_RENDER
#endif

#if TEST_PROFILE == SINGLE_FREE_PBO_NOVBO
//#define FULL_SCREEN
#define BLACK_TEXTURE
//#define USE_THREADS
//#define VSYNC
//#define USE_PBO
#define USE_VBO
//#define NO_RENDER
#endif

#if TEST_PROFILE == SINGLE_FREE_PBO_VBO
//#define FULL_SCREEN
#define BLACK_TEXTURE
//#define USE_THREADS
//#define VSYNC
#define USE_PBO
#define USE_VBO
//#define NO_RENDER
#endif

//////////////////////////////////////////////////////////////////////////
// Multithread stuff
//////////////////////////////////////////////////////////////////////////

#if TEST_PROFILE == MULTI_SYNC_NOPBO_NOVBO
//#define FULL_SCREEN
#define BLACK_TEXTURE
#define USE_THREADS
#define VSYNC
//#define USE_PBO
//#define USE_VBO
//#define NO_RENDER
#endif

#if TEST_PROFILE == MULTI_SYNC_NOPBO_VBO
//#define FULL_SCREEN
#define BLACK_TEXTURE
#define USE_THREADS
#define VSYNC
//#define USE_PBO
#define USE_VBO
//#define NO_RENDER
#endif

#if TEST_PROFILE == MULTI_SYNC_PBO_NOVBO
//#define FULL_SCREEN
#define BLACK_TEXTURE
#define USE_THREADS
#define VSYNC
//#define USE_PBO
#define USE_VBO
//#define NO_RENDER
#endif

#if TEST_PROFILE == MULTI_SYNC_PBO_VBO
//#define FULL_SCREEN
#define BLACK_TEXTURE
#define USE_THREADS
#define VSYNC
#define USE_PBO
#define USE_VBO
//#define NO_RENDER
#endif

//////////////////////////////////////////////////////////////////////////

#if TEST_PROFILE == MULTI_FREE_NOPBO_NOVBO
//#define FULL_SCREEN
#define BLACK_TEXTURE
#define USE_THREADS
//#define VSYNC
//#define USE_PBO
//#define USE_VBO
//#define NO_RENDER
#endif

#if TEST_PROFILE == MULTI_FREE_NOPBO_VBO
//#define FULL_SCREEN
#define BLACK_TEXTURE
#define USE_THREADS
//#define VSYNC
//#define USE_PBO
#define USE_VBO
//#define NO_RENDER
#endif

#if TEST_PROFILE == MULTI_FREE_PBO_NOVBO
//#define FULL_SCREEN
#define BLACK_TEXTURE
#define USE_THREADS
//#define VSYNC
//#define USE_PBO
#define USE_VBO
//#define NO_RENDER
#endif

#if TEST_PROFILE == MULTI_FREE_PBO_VBO
//#define FULL_SCREEN
#define BLACK_TEXTURE
#define USE_THREADS
//#define VSYNC
#define USE_PBO
#define USE_VBO
//#define NO_RENDER
#endif

//////////////////////////////////////////////////////////////////////////
// Real texture generation
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

#if TEST_PROFILE == REALDATA_SINGLE_FREE_NOPBO_NOVBO
//#define FULL_SCREEN
//#define BLACK_TEXTURE
//#define USE_THREADS
//#define VSYNC
//#define USE_PBO
//#define USE_VBO
//#define NO_RENDER
#endif

#if TEST_PROFILE == REALDATA_SINGLE_FREE_NOPBO_VBO
//#define FULL_SCREEN
//#define BLACK_TEXTURE
//#define USE_THREADS
//#define VSYNC
//#define USE_PBO
#define USE_VBO
//#define NO_RENDER
#endif

#if TEST_PROFILE == REALDATA_SINGLE_FREE_PBO_NOVBO
//#define FULL_SCREEN
//#define BLACK_TEXTURE
//#define USE_THREADS
//#define VSYNC
//#define USE_PBO
#define USE_VBO
//#define NO_RENDER
#endif

#if TEST_PROFILE == REALDATA_SINGLE_FREE_PBO_VBO
//#define FULL_SCREEN
//#define BLACK_TEXTURE
//#define USE_THREADS
//#define VSYNC
#define USE_PBO
#define USE_VBO
//#define NO_RENDER
#endif

//////////////////////////////////////////////////////////////////////////
// Multithread stuff
//////////////////////////////////////////////////////////////////////////

#if TEST_PROFILE == REALDATA_MULTI_SYNC_NOPBO_NOVBO
//#define FULL_SCREEN
//#define BLACK_TEXTURE
#define USE_THREADS
#define VSYNC
//#define USE_PBO
//#define USE_VBO
//#define NO_RENDER
#endif

#if TEST_PROFILE == REALDATA_MULTI_SYNC_NOPBO_VBO
//#define FULL_SCREEN
//#define BLACK_TEXTURE
#define USE_THREADS
#define VSYNC
//#define USE_PBO
#define USE_VBO
//#define NO_RENDER
#endif

#if TEST_PROFILE == REALDATA_MULTI_SYNC_PBO_NOVBO
//#define FULL_SCREEN
//#define BLACK_TEXTURE
#define USE_THREADS
#define VSYNC
//#define USE_PBO
#define USE_VBO
//#define NO_RENDER
#endif

#if TEST_PROFILE == REALDATA_MULTI_SYNC_PBO_VBO
//#define FULL_SCREEN
//#define BLACK_TEXTURE
#define USE_THREADS
#define VSYNC
#define USE_PBO
#define USE_VBO
//#define NO_RENDER
#endif

//////////////////////////////////////////////////////////////////////////

#if TEST_PROFILE == REALDATA_MULTI_FREE_NOPBO_NOVBO
//#define FULL_SCREEN
//#define BLACK_TEXTURE
#define USE_THREADS
//#define VSYNC
//#define USE_PBO
//#define USE_VBO
//#define NO_RENDER
#endif

#if TEST_PROFILE == REALDATA_MULTI_FREE_NOPBO_VBO
//#define FULL_SCREEN
//#define BLACK_TEXTURE
#define USE_THREADS
//#define VSYNC
//#define USE_PBO
#define USE_VBO
//#define NO_RENDER
#endif

#if TEST_PROFILE == REALDATA_MULTI_FREE_PBO_NOVBO
//#define FULL_SCREEN
//#define BLACK_TEXTURE
#define USE_THREADS
//#define VSYNC
//#define USE_PBO
#define USE_VBO
//#define NO_RENDER
#endif

#if TEST_PROFILE == REALDATA_MULTI_FREE_PBO_VBO
//#define FULL_SCREEN
//#define BLACK_TEXTURE
#define USE_THREADS
//#define VSYNC
#define USE_PBO
#define USE_VBO
//#define NO_RENDER
#endif

#ifndef USE_THREADS
#define USE_FASTQUEUE//fastqueue has interface similar to an array. Needed for single thread operations.
#endif

#endif