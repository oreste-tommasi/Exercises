#ifndef CMYCLASS_H
#define CMYCLASS_H


#ifdef MYDLL3_EXPORTS
#define MYDLL3_API __declspec(dllexport) 
#else
#define MYDLL3_API __declspec(dllimport) 
#endif




class CInterfaceForDll;


class CMyClass
{
public:
	static  MYDLL3_API CMyClass*	CMyClassFactory( CInterfaceForDll* inMainWin );
	static  MYDLL3_API void			DestroyObj( CMyClass* inObj );

	MYDLL3_API const char*			GetString() const;

	MYDLL3_API void					ShowDialog() const;

	MYDLL3_API void	resizeGL( int w, int h );
	MYDLL3_API void	paintGL();

	CInterfaceForDll* mMainWin;
};


#endif // CMYCLASS_H