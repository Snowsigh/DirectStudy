#pragma once
#include "KDevice.h"
class KWindow : public KDevice
{
public:
	HINSTANCE m_hInstance;
	HWND m_hWnd;
	DWORD					m_dwWindowStyle;	// 윈도우 스타일
	RECT					m_rcWindowBounds;   // 윈도우 영역
	RECT					m_rcWindowClient;   // 클라이언트 영역	
	UINT					m_iWindowWidth;		// 클라이언트 영역 가로크기
	UINT					m_iWindowHeight;	// 을라이언트 영역 세로크기
	bool m_bGameRun;
	KDevice kDevice;
public:
	bool InitWindow(HINSTANCE hInstance, int nCmdShow, const WCHAR* strWindowTitle);
	LRESULT MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
public:
	bool Run();
	bool GameInit();
	bool GameRun();
	bool GameRelease();
	

public:
	KWindow(void);
	virtual ~KWindow(void);

};

