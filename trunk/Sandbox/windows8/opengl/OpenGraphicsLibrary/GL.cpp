#include "pch.h"
#include "GL.h"
#include "Kernel.h"
#include "GDI.h"
#include "User.h"

PFAccum glAccum = nullptr;
PFAlphaFunc glAlphaFunc = nullptr;
PFAreTexturesResident glAreTexturesResident = nullptr;
PFArrayElement glArrayElement = nullptr;
PFBegin glBegin = nullptr;
PFBindTexture glBindTexture = nullptr;
PFBitmap glBitmap = nullptr;
PFBlendFunc glBlendFunc = nullptr;
PFCallList glCallList = nullptr;
PFCallLists glCallLists = nullptr;
PFClear glClear = nullptr;
PFClearAccum glClearAccum = nullptr;
PFClearColor glClearColor = nullptr;
PFClearDepth glClearDepth = nullptr;
PFClearIndex glClearIndex = nullptr;
PFClearStencil glClearStencil = nullptr;
PFClipPlane glClipPlane = nullptr;
PFColor3b glColor3b = nullptr;
PFColor3bv glColor3bv = nullptr;
PFColor3d glColor3d = nullptr;
PFColor3dv glColor3dv = nullptr;
PFColor3f glColor3f = nullptr;
PFColor3fv glColor3fv = nullptr;
PFColor3i glColor3i = nullptr;
PFColor3iv glColor3iv = nullptr;
PFColor3s glColor3s = nullptr;
PFColor3sv glColor3sv = nullptr;
PFColor3ub glColor3ub = nullptr;
PFColor3ubv glColor3ubv = nullptr;
PFColor3ui glColor3ui = nullptr;
PFColor3uiv glColor3uiv = nullptr;
PFColor3us glColor3us = nullptr;
PFColor3usv glColor3usv = nullptr;
PFColor4b glColor4b = nullptr;
PFColor4bv glColor4bv = nullptr;
PFColor4d glColor4d = nullptr;
PFColor4dv glColor4dv = nullptr;
PFColor4f glColor4f = nullptr;
PFColor4fv glColor4fv = nullptr;
PFColor4i glColor4i = nullptr;
PFColor4iv glColor4iv = nullptr;
PFColor4s glColor4s = nullptr;
PFColor4sv glColor4sv = nullptr;
PFColor4ub glColor4ub = nullptr;
PFColor4ubv glColor4ubv = nullptr;
PFColor4ui glColor4ui = nullptr;
PFColor4uiv glColor4uiv = nullptr;
PFColor4us glColor4us = nullptr;
PFColor4usv glColor4usv = nullptr;
PFColorMask glColorMask = nullptr;
PFColorMaterial glColorMaterial = nullptr;
PFColorPointer glColorPointer = nullptr;
PFCopyPixels glCopyPixels = nullptr;
PFCopyTexImage1D glCopyTexImage1D = nullptr;
PFCopyTexImage2D glCopyTexImage2D = nullptr;
PFCopyTexSubImage1D glCopyTexSubImage1D = nullptr;
PFCopyTexSubImage2D glCopyTexSubImage2D = nullptr;
PFCullFace glCullFace = nullptr;
PFDeleteLists glDeleteLists = nullptr;
PFDeleteTextures glDeleteTextures = nullptr;
PFDepthFunc glDepthFunc = nullptr;
PFDepthMask glDepthMask = nullptr;
PFDepthRange glDepthRange = nullptr;
PFDisable glDisable = nullptr;
PFDisableClientState glDisableClientState = nullptr;
PFDrawArrays glDrawArrays = nullptr;
PFDrawBuffer glDrawBuffer = nullptr;
PFDrawElements glDrawElements = nullptr;
PFDrawPixels glDrawPixels = nullptr;
PFEdgeFlag glEdgeFlag = nullptr;
PFEdgeFlagPointer glEdgeFlagPointer = nullptr;
PFEdgeFlagv glEdgeFlagv = nullptr;
PFEnable glEnable = nullptr;
PFEnableClientState glEnableClientState = nullptr;
PFEnd glEnd = nullptr;
PFEndList glEndList = nullptr;
PFEvalCoord1d glEvalCoord1d = nullptr;
PFEvalCoord1dv glEvalCoord1dv = nullptr;
PFEvalCoord1f glEvalCoord1f = nullptr;
PFEvalCoord1fv glEvalCoord1fv = nullptr;
PFEvalCoord2d glEvalCoord2d = nullptr;
PFEvalCoord2dv glEvalCoord2dv = nullptr;
PFEvalCoord2f glEvalCoord2f = nullptr;
PFEvalCoord2fv glEvalCoord2fv = nullptr;
PFEvalMesh1 glEvalMesh1 = nullptr;
PFEvalMesh2 glEvalMesh2 = nullptr;
PFEvalPoint1 glEvalPoint1 = nullptr;
PFEvalPoint2 glEvalPoint2 = nullptr;
PFFeedbackBuffer glFeedbackBuffer = nullptr;
PFFinish glFinish = nullptr;
PFFlush glFlush = nullptr;
PFFogf glFogf = nullptr;
PFFogfv glFogfv = nullptr;
PFFogi glFogi = nullptr;
PFFogiv glFogiv = nullptr;
PFFrontFace glFrontFace = nullptr;
PFFrustum glFrustum = nullptr;
PFGenLists glGenLists = nullptr;
PFGenTextures glGenTextures = nullptr;
PFGetBooleanv glGetBooleanv = nullptr;
PFGetClipPlane glGetClipPlane = nullptr;
PFGetDoublev glGetDoublev = nullptr;
PFGetError glGetError = nullptr;
PFGetFloatv glGetFloatv = nullptr;
PFGetIntegerv glGetIntegerv = nullptr;
PFGetLightfv glGetLightfv = nullptr;
PFGetLightiv glGetLightiv = nullptr;
PFGetMapdv glGetMapdv = nullptr;
PFGetMapfv glGetMapfv = nullptr;
PFGetMapiv glGetMapiv = nullptr;
PFGetMaterialfv glGetMaterialfv = nullptr;
PFGetMaterialiv glGetMaterialiv = nullptr;
PFGetPixelMapfv glGetPixelMapfv = nullptr;
PFGetPixelMapuiv glGetPixelMapuiv = nullptr;
PFGetPixelMapusv glGetPixelMapusv = nullptr;
PFGetPointerv glGetPointerv = nullptr;
PFGetPolygonStipple glGetPolygonStipple = nullptr;
PFGetString glGetString = nullptr;
PFGetTexEnvfv glGetTexEnvfv = nullptr;
PFGetTexEnviv glGetTexEnviv = nullptr;
PFGetTexGendv glGetTexGendv = nullptr;
PFGetTexGenfv glGetTexGenfv = nullptr;
PFGetTexGeniv glGetTexGeniv = nullptr;
PFGetTexImage glGetTexImage = nullptr;
PFGetTexLevelParameterfv glGetTexLevelParameterfv = nullptr;
PFGetTexLevelParameteriv glGetTexLevelParameteriv = nullptr;
PFGetTexParameterfv glGetTexParameterfv = nullptr;
PFGetTexParameteriv glGetTexParameteriv = nullptr;
PFHint glHint = nullptr;
PFIndexMask glIndexMask = nullptr;
PFIndexPointer glIndexPointer = nullptr;
PFIndexd glIndexd = nullptr;
PFIndexdv glIndexdv = nullptr;
PFIndexf glIndexf = nullptr;
PFIndexfv glIndexfv = nullptr;
PFIndexi glIndexi = nullptr;
PFIndexiv glIndexiv = nullptr;
PFIndexs glIndexs = nullptr;
PFIndexsv glIndexsv = nullptr;
PFIndexub glIndexub = nullptr;
PFIndexubv glIndexubv = nullptr;
PFInitNames glInitNames = nullptr;
PFInterleavedArrays glInterleavedArrays = nullptr;
PFIsEnabled glIsEnabled = nullptr;
PFIsList glIsList = nullptr;
PFIsTexture glIsTexture = nullptr;
PFLightModelf glLightModelf = nullptr;
PFLightModelfv glLightModelfv = nullptr;
PFLightModeli glLightModeli = nullptr;
PFLightModeliv glLightModeliv = nullptr;
PFLightf glLightf = nullptr;
PFLightfv glLightfv = nullptr;
PFLighti glLighti = nullptr;
PFLightiv glLightiv = nullptr;
PFLineStipple glLineStipple = nullptr;
PFLineWidth glLineWidth = nullptr;
PFListBase glListBase = nullptr;
PFLoadIdentity glLoadIdentity = nullptr;
PFLoadMatrixd glLoadMatrixd = nullptr;
PFLoadMatrixf glLoadMatrixf = nullptr;
PFLoadName glLoadName = nullptr;
PFLogicOp glLogicOp = nullptr;
PFMap1d glMap1d = nullptr;
PFMap1f glMap1f = nullptr;
PFMap2d glMap2d = nullptr;
PFMap2f glMap2f = nullptr;
PFMapGrid1d glMapGrid1d = nullptr;
PFMapGrid1f glMapGrid1f = nullptr;
PFMapGrid2d glMapGrid2d = nullptr;
PFMapGrid2f glMapGrid2f = nullptr;
PFMaterialf glMaterialf = nullptr;
PFMaterialfv glMaterialfv = nullptr;
PFMateriali glMateriali = nullptr;
PFMaterialiv glMaterialiv = nullptr;
PFMatrixMode glMatrixMode = nullptr;
PFMultMatrixd glMultMatrixd = nullptr;
PFMultMatrixf glMultMatrixf = nullptr;
PFNewList glNewList = nullptr;
PFNormal3b glNormal3b = nullptr;
PFNormal3bv glNormal3bv = nullptr;
PFNormal3d glNormal3d = nullptr;
PFNormal3dv glNormal3dv = nullptr;
PFNormal3f glNormal3f = nullptr;
PFNormal3fv glNormal3fv = nullptr;
PFNormal3i glNormal3i = nullptr;
PFNormal3iv glNormal3iv = nullptr;
PFNormal3s glNormal3s = nullptr;
PFNormal3sv glNormal3sv = nullptr;
PFNormalPointer glNormalPointer = nullptr;
PFOrtho glOrtho = nullptr;
PFPassThrough glPassThrough = nullptr;
PFPixelMapfv glPixelMapfv = nullptr;
PFPixelMapuiv glPixelMapuiv = nullptr;
PFPixelMapusv glPixelMapusv = nullptr;
PFPixelStoref glPixelStoref = nullptr;
PFPixelStorei glPixelStorei = nullptr;
PFPixelTransferf glPixelTransferf = nullptr;
PFPixelTransferi glPixelTransferi = nullptr;
PFPixelZoom glPixelZoom = nullptr;
PFPointSize glPointSize = nullptr;
PFPolygonMode glPolygonMode = nullptr;
PFPolygonOffset glPolygonOffset = nullptr;
PFPolygonStipple glPolygonStipple = nullptr;
PFPopAttrib glPopAttrib = nullptr;
PFPopClientAttrib glPopClientAttrib = nullptr;
PFPopMatrix glPopMatrix = nullptr;
PFPopName glPopName = nullptr;
PFPrioritizeTextures glPrioritizeTextures = nullptr;
PFPushAttrib glPushAttrib = nullptr;
PFPushClientAttrib glPushClientAttrib = nullptr;
PFPushMatrix glPushMatrix = nullptr;
PFPushName glPushName = nullptr;
PFRasterPos2d glRasterPos2d = nullptr;
PFRasterPos2dv glRasterPos2dv = nullptr;
PFRasterPos2f glRasterPos2f = nullptr;
PFRasterPos2fv glRasterPos2fv = nullptr;
PFRasterPos2i glRasterPos2i = nullptr;
PFRasterPos2iv glRasterPos2iv = nullptr;
PFRasterPos2s glRasterPos2s = nullptr;
PFRasterPos2sv glRasterPos2sv = nullptr;
PFRasterPos3d glRasterPos3d = nullptr;
PFRasterPos3dv glRasterPos3dv = nullptr;
PFRasterPos3f glRasterPos3f = nullptr;
PFRasterPos3fv glRasterPos3fv = nullptr;
PFRasterPos3i glRasterPos3i = nullptr;
PFRasterPos3iv glRasterPos3iv = nullptr;
PFRasterPos3s glRasterPos3s = nullptr;
PFRasterPos3sv glRasterPos3sv = nullptr;
PFRasterPos4d glRasterPos4d = nullptr;
PFRasterPos4dv glRasterPos4dv = nullptr;
PFRasterPos4f glRasterPos4f = nullptr;
PFRasterPos4fv glRasterPos4fv = nullptr;
PFRasterPos4i glRasterPos4i = nullptr;
PFRasterPos4iv glRasterPos4iv = nullptr;
PFRasterPos4s glRasterPos4s = nullptr;
PFRasterPos4sv glRasterPos4sv = nullptr;
PFReadBuffer glReadBuffer = nullptr;
PFReadPixels glReadPixels = nullptr;
PFRectd glRectd = nullptr;
PFRectdv glRectdv = nullptr;
PFRectf glRectf = nullptr;
PFRectfv glRectfv = nullptr;
PFRecti glRecti = nullptr;
PFRectiv glRectiv = nullptr;
PFRects glRects = nullptr;
PFRectsv glRectsv = nullptr;
PFRenderMode glRenderMode = nullptr;
PFRotated glRotated = nullptr;
PFRotatef glRotatef = nullptr;
PFScaled glScaled = nullptr;
PFScalef glScalef = nullptr;
PFScissor glScissor = nullptr;
PFSelectBuffer glSelectBuffer = nullptr;
PFShadeModel glShadeModel = nullptr;
PFStencilFunc glStencilFunc = nullptr;
PFStencilMask glStencilMask = nullptr;
PFStencilOp glStencilOp = nullptr;
PFTexCoord1d glTexCoord1d = nullptr;
PFTexCoord1dv glTexCoord1dv = nullptr;
PFTexCoord1f glTexCoord1f = nullptr;
PFTexCoord1fv glTexCoord1fv = nullptr;
PFTexCoord1i glTexCoord1i = nullptr;
PFTexCoord1iv glTexCoord1iv = nullptr;
PFTexCoord1s glTexCoord1s = nullptr;
PFTexCoord1sv glTexCoord1sv = nullptr;
PFTexCoord2d glTexCoord2d = nullptr;
PFTexCoord2dv glTexCoord2dv = nullptr;
PFTexCoord2f glTexCoord2f = nullptr;
PFTexCoord2fv glTexCoord2fv = nullptr;
PFTexCoord2i glTexCoord2i = nullptr;
PFTexCoord2iv glTexCoord2iv = nullptr;
PFTexCoord2s glTexCoord2s = nullptr;
PFTexCoord2sv glTexCoord2sv = nullptr;
PFTexCoord3d glTexCoord3d = nullptr;
PFTexCoord3dv glTexCoord3dv = nullptr;
PFTexCoord3f glTexCoord3f = nullptr;
PFTexCoord3fv glTexCoord3fv = nullptr;
PFTexCoord3i glTexCoord3i = nullptr;
PFTexCoord3iv glTexCoord3iv = nullptr;
PFTexCoord3s glTexCoord3s = nullptr;
PFTexCoord3sv glTexCoord3sv = nullptr;
PFTexCoord4d glTexCoord4d = nullptr;
PFTexCoord4dv glTexCoord4dv = nullptr;
PFTexCoord4f glTexCoord4f = nullptr;
PFTexCoord4fv gTexCoord4fv = nullptr;
PFTexCoord4i glTexCoord4i = nullptr;
PFTexCoord4iv glTexCoord4iv = nullptr;
PFTexCoord4s glTexCoord4s = nullptr;
PFTexCoord4sv glTexCoord4sv = nullptr;
PFTexCoordPointer glTexCoordPointer = nullptr;
PFTexEnvf glTexEnvf = nullptr;
PFTexEnvfv glTexEnvfv = nullptr;
PFTexEnvi glTexEnvi = nullptr;
PFTexEnviv glTexEnviv = nullptr;
PFTexGend glTexGend = nullptr;
PFTexGendv glTexGendv = nullptr;
PFTexGenf glTexGenf = nullptr;
PFTexGenfv glTexGenfv = nullptr;
PFTexGeni glTexGeni = nullptr;
PFTexGeniv glTexGeniv = nullptr;
PFTexImage1D glTexImage1D = nullptr;
PFTexImage2D glTexImage2D = nullptr;
PFTexParameterf glTexParameterf = nullptr;
PFTexParameterfv glTexParameterfv = nullptr;
PFTexParameteri glTexParameteri = nullptr;
PFTexParameteriv glTexParameteriv = nullptr;
PFTexSubImage1D glTexSubImage1D = nullptr;
PFTexSubImage2D glTexSubImage2D = nullptr;
PFTranslated glTranslated = nullptr;
PFTranslatef glTranslatef = nullptr;
PFVertex2d glVertex2d = nullptr;
PFVertex2dv glVertex2dv = nullptr;
PFVertex2f glVertex2f = nullptr;
PFVertex2fv glVertex2fv = nullptr;
PFVertex2i glVertex2i = nullptr;
PFVertex2iv glVertex2iv = nullptr;
PFVertex2s glVertex2s = nullptr;
PFVertex2sv glVertex2sv = nullptr;
PFVertex3d glVertex3d = nullptr;
PFVertex3dv glVertex3dv = nullptr;
PFVertex3f glVertex3f = nullptr;
PFVertex3fv glVertex3fv = nullptr;
PFVertex3i glVertex3i = nullptr;
PFVertex3iv glVertex3iv = nullptr;
PFVertex3s glVertex3s = nullptr;
PFVertex3sv glVertex3sv = nullptr;
PFVertex4d glVertex4d = nullptr;
PFVertex4dv glVertex4dv = nullptr;
PFVertex4f glVertex4f = nullptr;
PFVertex4fv glVertex4fv = nullptr;
PFVertex4i glVertex4i = nullptr;
PFVertex4iv glVertex4iv = nullptr;
PFVertex4s glVertex4s = nullptr;
PFVertex4sv glVertex4sv = nullptr;
PFVertexPointer glVertexPointer = nullptr;
PFViewport glViewport = nullptr;
PFCreateContext wglCreateContext = nullptr;
PFMakeCurrent wglMakeCurrent = nullptr;
PFDeleteContext wglDeleteContext = nullptr; 
PFGetProcAddress wglGetProcAddress = nullptr;

FuncTable glFuncTable[] = 
{
	{(void**)&glAccum, "glAccum"}, 
	{(void**)&glAlphaFunc, "glAlphaFunc"},
	{(void**)&glAreTexturesResident, "glAreTexturesResident"},
	{(void**)&glArrayElement,"glArrayElement"},
	{(void**)&glBegin, "glBegin"},
	{(void**)&glBindTexture, "glBindTexture"},
	{(void**)&glBitmap, "glBitmap"},
	{(void**)&glBlendFunc, "glBlendFunc"},
	{(void**)&glCallList, "glCallList"},
	{(void**)&glCallLists, "glCallLists"},
	{(void**)&glClear, "glClear"},
	{(void**)&glClearAccum, "glClearAccum"},
	{(void**)&glClearColor, "glClearColor"},
	{(void**)&glClearDepth, "glClearDepth"},
	{(void**)&glClearIndex, "glClearIndex"},
	{(void**)&glClearStencil, "glClearStencil"},
	{(void**)&glClipPlane, "glClipPlane"},
	{(void**)&glColor3b, "glColor3b"},
	{(void**)&glColor3bv, "glColor3bv"},
	{(void**)&glColor3d, "glColor3d"},
	{(void**)&glColor3dv, "glColor3dv"},
	{(void**)&glColor3f, "glColor3f"},
	{(void**)&glColor3fv, "glColor3fv"},
	{(void**)&glColor3i, "glColor3i"},
	{(void**)&glColor3iv, "glColor3iv"},
	{(void**)&glColor3s, "glColor3s"},
	{(void**)&glColor3sv, "glColor3sv"},
	{(void**)&glColor3ub, "glColor3ub"},
	{(void**)&glColor3ubv, "glColor3ubv"},
	{(void**)&glColor3ui, "glColor3ui"},
	{(void**)&glColor3uiv, "glColor3uiv"},
	{(void**)&glColor3us, "glColor3us"},
	{(void**)&glColor3usv, "glColor3usv"},
	{(void**)&glColor4b, "glColor4b"},
	{(void**)&glColor4bv, "glColor4bv"},
	{(void**)&glColor4d, "glColor4d"},
	{(void**)&glColor4dv, "glColor4dv"},
	{(void**)&glColor4f, "glColor4f"},
	{(void**)&glColor4fv, "glColor4fv"},
	{(void**)&glColor4i, "glColor4i"},
	{(void**)&glColor4iv, "glColor4iv"},
	{(void**)&glColor4s, "glColor4s"},
	{(void**)&glColor4sv, "glColor4sv"},
	{(void**)&glColor4ub, "glColor4ub"},
	{(void**)&glColor4ubv, "glColor4ubv"},
	{(void**)&glColor4ui, "glColor4ui"},
	{(void**)&glColor4uiv, "glColor4uiv"},
	{(void**)&glColor4us, "glColor4us"},
	{(void**)&glColor4usv, "glColor4usv"},
	{(void**)&glColorMask, "glColorMask"},
	{(void**)&glColorMaterial, "glColorMaterial"},
	{(void**)&glColorPointer, "glColorPointer"},
	{(void**)&glCopyPixels, "glCopyPixels"},
	{(void**)&glCopyTexImage1D, "glCopyTexImage1D"},
	{(void**)&glCopyTexImage2D, "glCopyTexImage2D"},
	{(void**)&glCopyTexSubImage1D, "glCopyTexSubImage1D"},
	{(void**)&glCopyTexSubImage2D, "glCopyTexSubImage2D"},
	{(void**)&glCullFace, "glCullFace"},
	{(void**)&glDeleteLists, "glDeleteLists"},
	{(void**)&glDeleteTextures, "glDeleteTextures"},
	{(void**)&glDepthFunc, "glDepthFunc"},
	{(void**)&glDepthMask, "glDepthMask"},
	{(void**)&glDepthRange, "glDepthRange"},
	{(void**)&glDisable, "glDisable"},
	{(void**)&glDisableClientState, "glDisableClientState"},
	{(void**)&glDrawArrays, "glDrawArrays"},
	{(void**)&glDrawBuffer, "glDrawBuffer"},
	{(void**)&glDrawElements, "glDrawElements"},
	{(void**)&glDrawPixels, "glDrawPixels"},
	{(void**)&glEdgeFlag, "glEdgeFlag"},
	{(void**)&glEdgeFlagPointer, "glEdgeFlagPointer"},
	{(void**)&glEdgeFlagv, "glEdgeFlagv"},
	{(void**)&glEnable, "glEnable"},
	{(void**)&glEnableClientState, "glEnableClientState"},
	{(void**)&glEnd, "glEnd"},
	{(void**)&glEndList, "glEndList"},
	{(void**)&glEvalCoord1d, "glEvalCoord1d"},
	{(void**)&glEvalCoord1dv, "glEvalCoord1dv"},
	{(void**)&glEvalCoord1f, "glEvalCoord1f"},
	{(void**)&glEvalCoord1fv, "glEvalCoord1fv"},
	{(void**)&glEvalCoord2d, "glEvalCoord2d"},
	{(void**)&glEvalCoord2dv, "glEvalCoord2dv"},
	{(void**)&glEvalCoord2f, "glEvalCoord2f"},
	{(void**)&glEvalCoord2fv, "glEvalCoord2fv"},
	{(void**)&glEvalMesh1, "glEvalMesh1"},
	{(void**)&glEvalMesh2, "glEvalMesh2"},
	{(void**)&glEvalPoint1, "glEvalPoint1"},
	{(void**)&glEvalPoint2, "glEvalPoint2"},
	{(void**)&glFeedbackBuffer, "glFeedbackBuffer"},
	{(void**)&glFinish, "glFinish"},
	{(void**)&glFlush, "glFlush"},
	{(void**)&glFogf, "glFogf"},
	{(void**)&glFogfv, "glFogfv"},
	{(void**)&glFogi, "glFogi"},
	{(void**)&glFogiv, "glFogiv"},
	{(void**)&glFrontFace, "glFrontFace"},
	{(void**)&glFrustum, "glFrustum"},
	{(void**)&glGenLists, "glGenLists"},
	{(void**)&glGenTextures, "glGenTextures"},
	{(void**)&glGetBooleanv, "glGetBooleanv"},
	{(void**)&glGetClipPlane, "glGetClipPlane"},
	{(void**)&glGetDoublev, "glGetDoublev"},
	{(void**)&glGetError, "glGetError"},
	{(void**)&glGetFloatv, "glGetFloatv"},
	{(void**)&glGetIntegerv, "glGetIntegerv"},
	{(void**)&glGetLightfv, "glGetLightfv"},
	{(void**)&glGetLightiv, "glGetLightiv"},
	{(void**)&glGetMapdv, "glGetMapdv"},
	{(void**)&glGetMapfv, "glGetMapfv"},
	{(void**)&glGetMapiv, "glGetMapiv"},
	{(void**)&glGetMaterialfv, "glGetMaterialfv"},
	{(void**)&glGetMaterialiv, "glGetMaterialiv"},
	{(void**)&glGetPixelMapfv, "glGetPixelMapfv"},
	{(void**)&glGetPixelMapuiv, "glGetPixelMapuiv"},
	{(void**)&glGetPixelMapusv, "glGetPixelMapusv"},
	{(void**)&glGetPointerv, "glGetPointerv"},
	{(void**)&glGetPolygonStipple, "glGetPolygonStipple"},
	{(void**)&glGetString, "glGetString"},
	{(void**)&glGetTexEnvfv, "glGetTexEnvfv"},
	{(void**)&glGetTexEnviv, "glGetTexEnviv"},
	{(void**)&glGetTexGendv, "glGetTexGendv"},
	{(void**)&glGetTexGenfv, "glGetTexGenfv"},
	{(void**)&glGetTexGeniv, "glGetTexGeniv"},
	{(void**)&glGetTexImage, "glGetTexImage"},
	{(void**)&glGetTexLevelParameterfv, "glGetTexLevelParameterfv"},
	{(void**)&glGetTexLevelParameteriv, "glGetTexLevelParameteriv"},
	{(void**)&glGetTexParameterfv, "glGetTexParameterfv"},
	{(void**)&glGetTexParameteriv, "glGetTexParameteriv"},
	{(void**)&glHint, "glHint"},
	{(void**)&glIndexMask, "glIndexMask"},
	{(void**)&glIndexPointer, "glIndexPointer"},
	{(void**)&glIndexd, "glIndexd"},
	{(void**)&glIndexdv, "glIndexdv"},
	{(void**)&glIndexf, "glIndexf"},
	{(void**)&glIndexfv, "glIndexfv"},
	{(void**)&glIndexi, "glIndexi"},
	{(void**)&glIndexiv, "glIndexiv"},
	{(void**)&glIndexs, "glIndexs"},
	{(void**)&glIndexsv, "glIndexsv"},
	{(void**)&glIndexub, "glIndexub"},
	{(void**)&glIndexubv, "glIndexubv"},
	{(void**)&glInitNames, "glInitNames"},
	{(void**)&glInterleavedArrays, "glInterleavedArrays"},
	{(void**)&glIsEnabled, "glIsEnabled"},
	{(void**)&glIsList, "glIsList"},
	{(void**)&glIsTexture, "glIsTexture"},
	{(void**)&glLightModelf, "glLightModelf"},
	{(void**)&glLightModelfv, "glLightModelfv"},
	{(void**)&glLightModeli, "glLightModeli"},
	{(void**)&glLightModeliv, "glLightModeliv"},
	{(void**)&glLightf, "glLightf"},
	{(void**)&glLightfv, "glLightfv"},
	{(void**)&glLighti, "glLighti"},
	{(void**)&glLightiv, "glLightiv"},
	{(void**)&glLineStipple, "glLineStipple"},
	{(void**)&glLineWidth, "glLineWidth"},
	{(void**)&glListBase, "glListBase"},
	{(void**)&glLoadIdentity, "glLoadIdentity"},
	{(void**)&glLoadMatrixd, "glLoadMatrixd"},
	{(void**)&glLoadMatrixf, "glLoadMatrixf"},
	{(void**)&glLoadName, "glLoadName"},
	{(void**)&glLogicOp, "glLogicOp"},
	{(void**)&glMap1d, "glMap1d"},
	{(void**)&glMap1f, "glMap1f"},
	{(void**)&glMap2d, "glMap2d"},
	{(void**)&glMap2f, "glMap2f"},
	{(void**)&glMapGrid1d, "glMapGrid1d"},
	{(void**)&glMapGrid1f, "glMapGrid1f"},
	{(void**)&glMapGrid2d, "glMapGrid2d"},
	{(void**)&glMapGrid2f, "glMapGrid2f"},
	{(void**)&glMaterialf, "glMaterialf"},
	{(void**)&glMaterialfv, "glMaterialfv"},
	{(void**)&glMateriali, "glMateriali"},
	{(void**)&glMaterialiv, "glMaterialiv"},
	{(void**)&glMatrixMode, "glMatrixMode"},
	{(void**)&glMultMatrixd, "glMultMatrixd"},
	{(void**)&glMultMatrixf, "glMultMatrixf"},
	{(void**)&glNewList, "glNewList"},
	{(void**)&glNormal3b, "glNormal3b"},
	{(void**)&glNormal3bv, "glNormal3bv"},
	{(void**)&glNormal3d, "glNormal3d"},
	{(void**)&glNormal3dv, "glNormal3dv"},
	{(void**)&glNormal3f, "glNormal3f"},
	{(void**)&glNormal3fv, "glNormal3fv"},
	{(void**)&glNormal3i, "glNormal3i"},
	{(void**)&glNormal3iv, "glNormal3iv"},
	{(void**)&glNormal3s, "glNormal3s"},
	{(void**)&glNormal3sv, "glNormal3sv"},
	{(void**)&glNormalPointer, "glNormalPointer"},
	{(void**)&glOrtho, "glOrtho"},
	{(void**)&glPassThrough, "glPassThrough"},
	{(void**)&glPixelMapfv, "glPixelMapfv"},
	{(void**)&glPixelMapuiv, "glPixelMapuiv"},
	{(void**)&glPixelMapusv, "glPixelMapusv"},
	{(void**)&glPixelStoref, "glPixelStoref"},
	{(void**)&glPixelStorei, "glPixelStorei"},
	{(void**)&glPixelTransferf, "glPixelTransferf"},
	{(void**)&glPixelTransferi, "glPixelTransferi"},
	{(void**)&glPixelZoom, "glPixelZoom"},
	{(void**)&glPointSize, "glPointSize"},
	{(void**)&glPolygonMode, "glPolygonMode"},
	{(void**)&glPolygonOffset, "glPolygonOffset"},
	{(void**)&glPolygonStipple, "glPolygonStipple"},
	{(void**)&glPopAttrib, "glPopAttrib"},
	{(void**)&glPopClientAttrib, "glPopClientAttrib"},
	{(void**)&glPopMatrix, "glPopMatrix"},
	{(void**)&glPopName, "glPopName"},
	{(void**)&glPrioritizeTextures, "glPrioritizeTextures"},
	{(void**)&glPushAttrib, "glPushAttrib"},
	{(void**)&glPushClientAttrib, "glPushClientAttrib"},
	{(void**)&glPushMatrix, "glPushMatrix"},
	{(void**)&glPushName, "glPushName"},
	{(void**)&glRasterPos2d, "glRasterPos2d"},
	{(void**)&glRasterPos2dv, "glRasterPos2dv"},
	{(void**)&glRasterPos2f, "glRasterPos2f"},
	{(void**)&glRasterPos2fv, "glRasterPos2fv"},
	{(void**)&glRasterPos2i, "glRasterPos2i"},
	{(void**)&glRasterPos2iv, "glRasterPos2iv"},
	{(void**)&glRasterPos2s, "glRasterPos2s"},
	{(void**)&glRasterPos2sv, "glRasterPos2sv"},
	{(void**)&glRasterPos3d, "glRasterPos3d"},
	{(void**)&glRasterPos3dv, "glRasterPos3dv"},
	{(void**)&glRasterPos3f, "glRasterPos3f"},
	{(void**)&glRasterPos3fv, "glRasterPos3fv"},
	{(void**)&glRasterPos3i, "glRasterPos3i"},
	{(void**)&glRasterPos3iv, "glRasterPos3iv"},
	{(void**)&glRasterPos3s, "glRasterPos3s"},
	{(void**)&glRasterPos3sv, "glRasterPos3sv"},
	{(void**)&glRasterPos4d, "glRasterPos4d"},
	{(void**)&glRasterPos4dv, "glRasterPos4dv"},
	{(void**)&glRasterPos4f, "glRasterPos4f"},
	{(void**)&glRasterPos4fv, "glRasterPos4fv"},
	{(void**)&glRasterPos4i, "glRasterPos4i"},
	{(void**)&glRasterPos4iv, "glRasterPos4iv"},
	{(void**)&glRasterPos4s, "glRasterPos4s"},
	{(void**)&glRasterPos4sv, "glRasterPos4sv"},
	{(void**)&glReadBuffer, "glReadBuffer"},
	{(void**)&glReadPixels, "glReadPixels"},
	{(void**)&glRectd, "glRectd"},
	{(void**)&glRectdv, "glRectdv"},
	{(void**)&glRectf, "glRectf"},
	{(void**)&glRectfv, "glRectfv"},
	{(void**)&glRecti, "glRecti"},
	{(void**)&glRectiv, "glRectiv"},
	{(void**)&glRects, "glRects"},
	{(void**)&glRectsv, "glRectsv"},
	{(void**)&glRenderMode, "glRenderMode"},
	{(void**)&glRotated, "glRotated"},
	{(void**)&glRotatef, "glRotatef"},
	{(void**)&glScaled, "glScaled"},
	{(void**)&glScalef, "glScalef"},
	{(void**)&glScissor, "glScissor"},
	{(void**)&glSelectBuffer, "glSelectBuffer"},
	{(void**)&glShadeModel, "glShadeModel"},
	{(void**)&glStencilFunc, "glStencilFunc"},
	{(void**)&glStencilMask, "glStencilMask"},
	{(void**)&glStencilOp, "glStencilOp"},
	{(void**)&glTexCoord1d, "glTexCoord1d"},
	{(void**)&glTexCoord1dv, "glTexCoord1dv"},
	{(void**)&glTexCoord1f, "glTexCoord1f"},
	{(void**)&glTexCoord1fv, "glTexCoord1fv"},
	{(void**)&glTexCoord1i, "glTexCoord1i"},
	{(void**)&glTexCoord1iv, "glTexCoord1iv"},
	{(void**)&glTexCoord1s, "glTexCoord1s"},
	{(void**)&glTexCoord1sv, "glTexCoord1sv"},
	{(void**)&glTexCoord2d, "glTexCoord2d"},
	{(void**)&glTexCoord2dv, "glTexCoord2dv"},
	{(void**)&glTexCoord2f, "glTexCoord2f"},
	{(void**)&glTexCoord2fv, "glTexCoord2fv"},
	{(void**)&glTexCoord2i, "glTexCoord2i"},
	{(void**)&glTexCoord2iv, "glTexCoord2iv"},
	{(void**)&glTexCoord2s, "glTexCoord2s"},
	{(void**)&glTexCoord2sv, "glTexCoord2sv"},
	{(void**)&glTexCoord3d, "glTexCoord3d"},
	{(void**)&glTexCoord3dv, "glTexCoord3dv"},
	{(void**)&glTexCoord3f, "glTexCoord3f"},
	{(void**)&glTexCoord3fv, "glTexCoord3fv"},
	{(void**)&glTexCoord3i, "glTexCoord3i"},
	{(void**)&glTexCoord3iv, "glTexCoord3iv"},
	{(void**)&glTexCoord3s, "glTexCoord3s"},
	{(void**)&glTexCoord3sv, "glTexCoord3sv"},
	{(void**)&glTexCoord4d, "glTexCoord4d"},
	{(void**)&glTexCoord4dv, "glTexCoord4dv"},
	{(void**)&glTexCoord4f, "glTexCoord4f"},
	{(void**)&gTexCoord4fv, "glTexCoord4fv"},
	{(void**)&glTexCoord4i, "glTexCoord4i"},
	{(void**)&glTexCoord4iv, "glTexCoord4iv"},
	{(void**)&glTexCoord4s, "glTexCoord4s"},
	{(void**)&glTexCoord4sv, "glTexCoord4sv"},
	{(void**)&glTexCoordPointer, "glTexCoordPointer"},
	{(void**)&glTexEnvf, "glTexEnvf"},
	{(void**)&glTexEnvfv, "glTexEnvfv"},
	{(void**)&glTexEnvi, "glTexEnvi"},
	{(void**)&glTexEnviv, "glTexEnviv"},
	{(void**)&glTexGend, "glTexGend"},
	{(void**)&glTexGendv, "glTexGendv"},
	{(void**)&glTexGenf, "glTexGenf"},
	{(void**)&glTexGenfv, "glTexGenfv"},
	{(void**)&glTexGeni, "glTexGeni"},
	{(void**)&glTexGeniv, "glTexGeniv"},
	{(void**)&glTexImage1D, "glTexImage1D"},
	{(void**)&glTexImage2D, "glTexImage2D"},
	{(void**)&glTexParameterf, "glTexParameterf"},
	{(void**)&glTexParameterfv, "glTexParameterfv"},
	{(void**)&glTexParameteri, "glTexParameteri"},
	{(void**)&glTexParameteriv, "glTexParameteriv"},
	{(void**)&glTexSubImage1D, "glTexSubImage1D"},
	{(void**)&glTexSubImage2D, "glTexSubImage2D"},
	{(void**)&glTranslated, "glTranslated"},
	{(void**)&glTranslatef, "glTranslatef"},
	{(void**)&glVertex2d, "glVertex2d"},
	{(void**)&glVertex2dv, "glVertex2dv"},
	{(void**)&glVertex2f, "glVertex2f"},
	{(void**)&glVertex2fv, "glVertex2fv"},
	{(void**)&glVertex2i, "glVertex2i"},
	{(void**)&glVertex2iv, "glVertex2iv"},
	{(void**)&glVertex2s, "glVertex2s"},
	{(void**)&glVertex2sv, "glVertex2sv"},
	{(void**)&glVertex3d, "glVertex3d"},
	{(void**)&glVertex3dv, "glVertex3dv"},
	{(void**)&glVertex3f, "glVertex3f"},
	{(void**)&glVertex3fv, "glVertex3fv"},
	{(void**)&glVertex3i, "glVertex3i"},
	{(void**)&glVertex3iv, "glVertex3iv"},
	{(void**)&glVertex3s, "glVertex3s"},
	{(void**)&glVertex3sv, "glVertex3sv"},
	{(void**)&glVertex4d, "glVertex4d"},
	{(void**)&glVertex4dv, "glVertex4dv"},
	{(void**)&glVertex4f, "glVertex4f"},
	{(void**)&glVertex4fv, "glVertex4fv"},
	{(void**)&glVertex4i, "glVertex4i"},
	{(void**)&glVertex4iv, "glVertex4iv"},
	{(void**)&glVertex4s, "glVertex4s"},
	{(void**)&glVertex4sv, "glVertex4sv"},
	{(void**)&glVertexPointer, "glVertexPointer"},
	{(void**)&glViewport, "glViewport"},
	{(void**)&wglCreateContext, "wglCreateContext"},
	{(void**)&wglMakeCurrent, "wglMakeCurrent"},
	{(void**)&wglDeleteContext, "wglDeleteContext"},
	{(void**)&wglGetProcAddress, "wglGetProcAddress"}
};

BOOL glLoadLibrary(char* user, char* gdi, char* openGL)
{
	BOOL returnValue = TRUE;
	HMODULE hOpenGL = nullptr;

	if (!KernelLoaded)
	{
		returnValue = kernelLoadLirary();
	}

	if (TRUE == returnValue)
	{
		returnValue = userLoadLibrary(user);
		 
		if (TRUE == returnValue)
		{
			returnValue = gdiLoadLibrary(gdi);

			if (TRUE == returnValue)
			{
				if (nullptr == (hOpenGL = LoadLibraryA(openGL)))
				{
					returnValue = false;
				}
				else
				{
					int funcStructSize = sizeof(FuncTable);
					int funcTableSize = sizeof(glFuncTable);
					int funcCount = funcTableSize / funcStructSize;
					returnValue = kernelSetFuncs(hOpenGL, glFuncTable, funcCount);
				}
			}
		}
	}

	return returnValue;
}