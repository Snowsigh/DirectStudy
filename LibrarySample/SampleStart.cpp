#include "LibrarySample.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
    KWindow gSample;
    if (!gSample.InitWindow(hInstance, nCmdShow, L"CreateWindow"))
    {
        MessageBox(0, _T("CreateWindow  초기화 실패"), _T("Fatal error"), MB_OK);
        return 0;
    }
    ShowCursor(TRUE);
    gSample.Run();
    return 1;
}