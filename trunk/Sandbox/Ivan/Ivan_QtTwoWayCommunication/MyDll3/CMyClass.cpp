// MyDll3.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "CMyClass.h"
#include <stdexcept>
#include <gl/GLU.h>

#include "CInterfaceForDll.h"

using namespace std;


CMyClass* 
CMyClass::CMyClassFactory( CInterfaceForDll* inMainWin )
{
	CMyClass* retval = new CMyClass();
	retval->mMainWin = inMainWin;

	return retval;
}

void		 
CMyClass::DestroyObj( CMyClass* inObj )
{
	delete inObj;
}

const char*	
CMyClass::GetString() const
{
	return "ciao da CMyClass";
}

void		
CMyClass::ShowDialog() const
{
	bool ok = mMainWin->ShowDialog( "messaggio da dll" );

	int gg = 0;
}

void
CMyClass::resizeGL( int w, int h )
{
	gluOrtho2D( -1, 1, -1, 1 );
}

void
CMyClass::paintGL()
{
	static float color = 0.0f;

	color += 0.1f;
	if( color > 1.0f )
		color = 0.0f;

	glClearColor( color, 0, 0, 1.0 );
	glClear( GL_COLOR_BUFFER_BIT );

	glBegin(GL_TRIANGLES);
	glColor3f( 1, 0, 0 );
	glVertex2d( -0.5, -0.5 );
	glColor3f( 0, 1, 0 );
	glVertex2d( -0.5, 0.5 );
	glColor3f( 0, 0, 1 );
	glVertex2d( 0.5, 0.5 );
	glEnd();
}

