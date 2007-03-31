#pragma once

#include "resource.h"


#define MAX_LOADSTRING 100

class KWindow;

class KApp
{
private:
	static KApp * m_pTheOneApp;
	bool m_bFirstObject;

	KWindow  * m_pKWindow;

	static unsigned int const m_uMaxWindowStringSize;

	TCHAR m_szTitle[MAX_LOADSTRING];
	TCHAR m_szClassName[MAX_LOADSTRING];

	//Init Params
	HINSTANCE m_hInstance;
	HINSTANCE m_hPrevInstance;
	LPTSTR m_lpCmdLine;
	int m_nCmdShow;

public:
	KApp(void);
	static KApp * GetApp();
	~KApp(void);


private:
	ATOM m_atomClassReg;
	BOOL Initialize();
	BOOL CleanUp();

	//Window Procedure given to windows
	static LRESULT CALLBACK _sWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	

public:
	int winMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow);
};
