#include "Main.h"

bool	Sample::Init()
{
	return true;
}
bool	Sample::Frame()
{
	return true;
}
bool	Sample::Render()
{
	return true;
}
bool	Sample::Release()
{
	return true;
}

int APIENTRY wWinMain(
			_In_ HINSTANCE hInstance,
			_In_opt_ HINSTANCE hPrevInstance,
			_In_ LPWSTR IpCmdLine,
			_In_ int nCmdShow)
{
	Sample gSample;
	if (!gSample.InitWindow(hInstance, nCmdShow, L"CreateWindow"))
	{
		MessageBox(0, _T("초기화 실패"), _T("Fatal Error"), MB_OK);
		return 0;
	}
	ShowCursor(TRUE);
	gSample.Run();
	return 1;
}