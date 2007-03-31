#include "StdAfx.h"
#include "GLKontext.h"
#include "kwindow.h"

GLKontext::GLKontext(void)
{
	m_pWindowLink = 0;
	m_hDC = 0;
	m_hRC = 0;
}

BOOL GLKontext::Initialize(KWindow * pWindow){
	if(!(pWindow && pWindow->GetSafeHandle())){
		return FALSE;
	}
	m_pWindowLink = pWindow;
	

	m_hDC = ::GetDC(pWindow->m_hWnd);
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory( &pfd, sizeof( pfd ) );
	pfd.nSize = sizeof( pfd );
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER | PFD_GENERIC_ACCELERATED;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 24;
	pfd.cDepthBits = 16;
	pfd.iLayerType = PFD_MAIN_PLANE;
	int iFormat = ChoosePixelFormat( m_hDC, &pfd );
	SetPixelFormat( m_hDC, iFormat, &pfd );

	// create the render context (RC)
    m_hRC = wglCreateContext( m_hDC );

    // make it the current render context
    wglMakeCurrent( m_hDC, m_hRC );
	return TRUE;
}

BOOL GLKontext::CleanUp(){
	wglMakeCurrent(NULL,NULL);
	if(m_hRC){
		wglDeleteContext( m_hRC );
	}
	if(m_pWindowLink && m_pWindowLink->GetSafeHandle()){
		ReleaseDC(m_pWindowLink->m_hWnd, m_hDC);
	}
	return true;
}

HANDLE GLKontext::GetSafeHandle(){
	return (HANDLE)m_hRC;
}

HANDLE GLKontext::GetSafeDeviceHandle(){
	return (HANDLE)m_hDC;
}

GLKontext::~GLKontext(void)
{
}
