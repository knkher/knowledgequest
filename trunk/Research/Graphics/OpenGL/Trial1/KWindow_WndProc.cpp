#include "StdAfx.h"
#include "KWindow.h"
#include "stdio.h"

int iMsg = 1;

const UINT KWindow::m_msgIdle			=	WM_APP + iMsg++;
const UINT KWindow::m_msgPostCreate		=	WM_APP + iMsg++;


LRESULT KWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){

	LRESULT lRes = 0;
	
	switch(message){
		case WM_ACTIVATE:
			{
				lRes = OnActivate(wParam, HWND(lParam));
				break;
			}
		case WM_CREATE:
			{
				lRes = OnCreate((CREATESTRUCT * )(lParam));
				break;
			}
		case WM_CLOSE:
			{
				lRes = OnClose();
				break;
			}
		case WM_DESTROY:
			{
				lRes = OnDestroy();
				break;
			}
		case WM_PAINT:
			{
				lRes = OnPaint();
				break;
			}
		default:
			{
				if(message >= WM_USER && message <= 0x07FFF){
					lRes = ProcessUserMessage(hWnd, message, wParam, lParam);
				}else if(message >=WM_APP && message <= 0xBFFF){
					lRes = ProcessAppMessage(hWnd, message, wParam, lParam);
				}else{
					lRes = ::DefWindowProc(hWnd, message, wParam, lParam);
				}
				break;
			}
	};

	/*printf("Message %ld(%ld, %ld) = %ld\n", message, wParam, lParam, lRes); */
	return lRes;
	
}

LRESULT KWindow::ProcessUserMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	LRESULT lRes = 0;

	hWnd;message;wParam;lParam;




	return lRes;
}
LRESULT KWindow::ProcessAppMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	LRESULT lRes = 0;

	hWnd;message;wParam;lParam;
	
	if (message == m_msgIdle){
		lRes = OnIdle();
	}
	else if (message == m_msgPostCreate){
		lRes = OnPostCreate();
	}

	return lRes;
}