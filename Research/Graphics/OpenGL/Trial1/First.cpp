// First.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "First.h"
#include "kapp.h"

#define MAX_LOADSTRING 100

KApp kapp;

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	kapp.winMain(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
}

