#pragma once
#include "GLKontext.h"

class KWindow
{

public:
	static const UINT m_msgIdle;
	static const UINT m_msgPostCreate;
public:
	KWindow(void);
public:
	~KWindow(void);
public:


	//Window Handle
	HWND m_hWnd;


	//OpenGL Context;
	GLKontext m_kontext;
	bool m_bActive;

	//Call to create window;
	HWND CreateKWindow(LPCTSTR lpClassName,
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
	);

	//Windows Procedure Implementation
	LRESULT WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	HANDLE GetSafeHandle();

	//Helper Functions
	
	LRESULT KWindow::ProcessUserMessage(HWND hWnd,UINT message, WPARAM wParam, LPARAM lParam);
	LRESULT KWindow::ProcessAppMessage(HWND hWnd,UINT message, WPARAM wParam, LPARAM lParam);

	LRESULT OnPostCreate();
	LRESULT OnIdle();


	//Handlers
	BOOL OnCreate(CREATESTRUCT * pCreateStruct);
	BOOL OnDestroy();
	BOOL OnPaint();
	BOOL OnClose();
	BOOL OnActivate(WPARAM wActivateFlag, HWND hOtherWindow);


};
