#include <windows.h>

int WinMain(HINSTANCE h1, HINSTANCE h2, char * c, int i){
	
	return ::MessageBox(0, "Testing", "Testing", MB_ABORTRETRYIGNORE);	
}
