#include "StdAfx.h"
#include "KApp.h"
#include "KWindow.h"

KApp * KApp::m_pTheOneApp = NULL;
const unsigned int KApp::m_uMaxWindowStringSize = MAX_LOADSTRING;



KApp::KApp(void)
{
	if(m_pTheOneApp){
		::MessageBox(0, L"Only One KApp Object Per Application can Exist. This Object will be useless", L"KApp::KApp()", MB_OK);		
		m_bFirstObject = false;
		return;
	}
	m_pTheOneApp = this;
	m_pKWindow = NULL;

	m_bFirstObject = true;
	m_hInstance = 0;
	m_atomClassReg = 0;
}

KApp * KApp::GetApp(){
	return m_pTheOneApp;
}

KApp::~KApp(void)
{
	if(m_pKWindow){
		::MessageBox(0,L"Window Not Destroyed Completely.", L"KApp::~KApp", MB_OK);
	}
}


int KApp::winMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow){
	if(!m_bFirstObject){
		return FALSE;
	}

	//Store Init Params;
	m_hInstance = hInstance;
	m_hPrevInstance = hPrevInstance;
	m_lpCmdLine = lpCmdLine;
	m_nCmdShow = nCmdShow;
 	
	bool bInit = (Initialize() == TRUE);
	if(!bInit){
		::MessageBox(0,L"Initialization Failed",L"KApp::winMain",MB_OK);
		return FALSE;
	}

	// Main message loop:
	MSG msg;	
	msg.wParam = 0;
	bool bQuit = false;
	while (!bQuit){
		if(PeekMessage(&msg,NULL,0,0,PM_REMOVE)){
			if(msg.message == WM_QUIT){
				bQuit = true;
				continue;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}else{
			if(m_pKWindow->m_hWnd && m_pKWindow->m_bActive)
				PostMessage(m_pKWindow->m_hWnd,m_pKWindow->m_msgIdle,0,0);
			else if(m_pKWindow->m_hWnd && m_pKWindow->m_kontext.GetSafeHandle()){
				Sleep(1);
			}
		}
	}

	bool bCleanUp = (CleanUp() == TRUE);
	if(!bCleanUp){
		::MessageBox(0,L"CleanUp Failed",L"KApp::winMain",MB_OK);
		return FALSE;
	}

	return (int) msg.wParam;
}

BOOL KApp::Initialize(){
	bool bRegSuccess = false;
	bool bWindowSuccess = false;


	{
		// Initialize global strings
		LoadString(m_hInstance, IDS_APP_TITLE, m_szTitle, m_uMaxWindowStringSize);
		LoadString(m_hInstance, IDC_FIRST, m_szClassName, m_uMaxWindowStringSize);

		WNDCLASSEX wcex;

		wcex.cbSize = sizeof(WNDCLASSEX);

		wcex.style			= CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc	= KApp::_sWndProc;
		wcex.cbClsExtra		= 0;
		wcex.cbWndExtra		= 0;
		wcex.hInstance		= m_hInstance;
		wcex.hIcon			= LoadIcon(m_hInstance, MAKEINTRESOURCE(IDI_FIRST));
		wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
		wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
		wcex.lpszMenuName	= NULL/*MAKEINTRESOURCE(IDC_FIRST)*/;
		wcex.lpszClassName	= m_szClassName;
		wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

		m_atomClassReg = ::RegisterClassEx(&wcex);
		bRegSuccess = true;
	}



	//Try to create window
	{
		m_pKWindow = new KWindow();
		
		HWND hWnd;
		//hWnd = m_pKWindow->CreateKWindow(m_szClassName, m_szTitle, WS_CAPTION | WS_POPUPWINDOW | WS_VISIBLE, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, m_hInstance, NULL);
		hWnd = m_pKWindow->CreateKWindow(m_szClassName, m_szTitle,WS_CLIPCHILDREN| WS_CLIPSIBLINGS |WS_POPUP| WS_VISIBLE, 0, 0, 1024, 768, NULL, NULL, m_hInstance, NULL);
		if (!hWnd){
		  bWindowSuccess = FALSE;
		}else{

			ShowWindow(hWnd, m_nCmdShow);
			UpdateWindow(hWnd);

			bWindowSuccess = TRUE;
		}

	}




	return (bRegSuccess && bWindowSuccess);
}

BOOL KApp::CleanUp(){

	//Try to destroy window
	{
		delete m_pKWindow;
		m_pKWindow = NULL;
	}

	return TRUE;
}


LRESULT CALLBACK KApp::_sWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){

	return m_pTheOneApp->m_pKWindow->WndProc(hWnd, message, wParam, lParam);

}

