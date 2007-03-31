#include "StdAfx.h"
#include "KWindow.h"

KWindow::KWindow(void)
{
	m_hWnd = NULL;
	m_bActive = false;
}

KWindow::~KWindow(void)
{
	if(m_hWnd){
		::MessageBox(0, L"Window Not Desytoyed Before Destructor", L"KWindow::~KWindow", MB_OK);
	}
}

HWND KWindow::CreateKWindow(
		LPCTSTR lpClassName,
		LPCTSTR lpWindowName,
		DWORD dwStyle,
		int x,
		int y,
		int nWidth,
		int nHeight,
		HWND hWndParent,
		HMENU hMenu,
		HINSTANCE hInstance,
		LPVOID lpParam
		){


			m_hWnd = 0;

			//bool bFullScreenPossible = false;
			{
				DEVMODE dmScreenSettings;								// Device Mode
				
				memset(&dmScreenSettings,0,sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
				dmScreenSettings.dmSize=sizeof(dmScreenSettings);		// Size Of The Devmode Structure
				dmScreenSettings.dmPelsWidth	= nWidth;				// Selected Screen Width
				dmScreenSettings.dmPelsHeight	= nHeight;				// Selected Screen Height
				dmScreenSettings.dmBitsPerPel	= 32;					// Selected Bits Per Pixel
				dmScreenSettings.dmFields=DM_BITSPERPEL|DM_PELSWIDTH|DM_PELSHEIGHT;

				// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
				if (ChangeDisplaySettings(&dmScreenSettings,CDS_FULLSCREEN)==DISP_CHANGE_SUCCESSFUL){
					RECT rect;
					rect.left = x;
					rect.top = y;
					rect.right = nWidth;
					rect.bottom = nHeight;
					AdjustWindowRectEx(&rect, WS_POPUP, false, 0);
					ShowCursor(FALSE);
					m_hWnd = ::CreateWindow(lpClassName,lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
				}
			}

			
				
			


			if(m_hWnd){
				if(!SendMessage(m_hWnd,m_msgPostCreate,0,0)){
					PostQuitMessage(124);
				}
			}else{
				::MessageBox(0, L"Window Creation Failed", L"KWindow::CreateKWindow",MB_OK);
			}
			return m_hWnd;
}


HANDLE KWindow::GetSafeHandle(){
	return (HANDLE)m_hWnd;
}