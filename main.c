#include <stdio.h>
#include <windows.h>
#include "resource.h"
INT_PTR CALLBACK DialogProc(
  _In_ HWND   hwndDlg,
  _In_ UINT   uMsg,
  _In_ WPARAM wParam,
  _In_ LPARAM lParam
) {
	switch(uMsg) {
	case WM_COMMAND:
		switch(wParam) {
		case IDOK:
			printf("ok\n");
			break;
		case IDCANCEL:
			printf("cancel\n");
			PostQuitMessage(0);
			break;
		}
		break;
	}
	return 0;
}
int main() {
	CHAR szBuf[1024];
	HWND hDlgModeless;
	MSG msg;

	LoadStringA(NULL,IDS_1,szBuf,sizeof(szBuf));
	printf("IDS_1  =  %s\n", szBuf);

	hDlgModeless = CreateDialog(NULL,MAKEINTRESOURCE(IDD_ABOUT_DIALOG),NULL,DialogProc);
	if(hDlgModeless == 0) {
		printf("CreateDialog error %d\n",hDlgModeless);
		return -1;
	}

	ShowWindow(hDlgModeless,SW_SHOW);

	while (GetMessage (&msg, NULL, 0, 0))
	{
		if (hDlgModeless == 0 || !IsDialogMessage (hDlgModeless, &msg))
		{
			TranslateMessage (&msg) ;
			DispatchMessage  (&msg) ;
		}
	}
	return 0;
}
