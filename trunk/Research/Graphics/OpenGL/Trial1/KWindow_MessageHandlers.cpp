#include "stdafx.h"
#include "kWindow.h"
#include <string>


BOOL KWindow::OnCreate(CREATESTRUCT * pCreateStruct){
	pCreateStruct;
	return 0;
}

LRESULT KWindow::OnPostCreate(){
	BOOL bRet = true;
	if(bRet){
		bRet = m_kontext.Initialize(this);
	}
	return bRet;
}

BOOL KWindow::OnClose(){

	BOOL bRet;
	bRet = (m_kontext.CleanUp() == TRUE) && DestroyWindow(m_hWnd);
	if(bRet){
		PostQuitMessage(0);
	}else{
		PostQuitMessage(124);
	}
	return 0;
}

LRESULT KWindow::OnIdle(){

	static DWORD dwPrevTickCount = GetTickCount();
	static DWORD dwCurrentTickCount = dwPrevTickCount;
	static DWORD dwDiff = 0;

	
	
	
	static float theta = 0.0;

	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
	glShadeModel(GL_SMOOTH);
	glClear( GL_COLOR_BUFFER_BIT );
	
	glPushMatrix();
	glRotatef( theta, 0.0f, 0.0f, 1.0f );
	glBegin( GL_TRIANGLES );	
	glColor3f( 1.0f, 0.0f, 0.0f ); glVertex2f( 0.0f, 1.0f );
	glColor3f( 0.0f, 1.0f, 0.0f ); glVertex2f( 0.87f, -0.5f );
	glColor3f( 0.0f, 0.0f, 1.0f ); glVertex2f( -0.87f, -0.5f );	
	glEnd();	
	glPopMatrix();


	dwCurrentTickCount = GetTickCount();
	dwDiff = dwCurrentTickCount - dwPrevTickCount;
	dwPrevTickCount = dwCurrentTickCount;
	static wchar_t sInfo[200];
	wsprintf(sInfo,L"%ld",dwDiff);	
	HDC hDC = (HDC)m_kontext.GetSafeDeviceHandle();
	::TextOut(hDC,0,0, sInfo, 199);
	SwapBuffers( hDC );
	theta += 0.5f;
	return 0;
}

BOOL KWindow::OnDestroy(){
	m_hWnd = 0;
	return 0;
}

BOOL KWindow::OnPaint(){
	RECT rect;
	BOOL bRequired = ::GetUpdateRect(m_hWnd,&rect, true);
	if(bRequired){
		if(!m_bActive){
			OnIdle();
		}
		::ValidateRect(m_hWnd, &rect);
	}
	return 0;
}

BOOL KWindow::OnActivate(WPARAM wActivateFlag, HWND hOtherWindow){
	wActivateFlag;hOtherWindow;


	bool bMadeActive = false;
	if(wActivateFlag == WA_ACTIVE || wActivateFlag == WA_CLICKACTIVE){
		bMadeActive = true;
	}
	m_bActive = bMadeActive;
	return 0;
}



