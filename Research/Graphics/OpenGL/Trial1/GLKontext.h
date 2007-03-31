#pragma once

class KWindow;

class GLKontext
{
	KWindow * m_pWindowLink;
	HDC m_hDC;
	HGLRC m_hRC;
public:
	GLKontext(void);
	BOOL Initialize(KWindow * pWindow);
	BOOL CleanUp();

	HANDLE GetSafeHandle();
	HANDLE GetSafeDeviceHandle();
public:
	~GLKontext(void);
};
