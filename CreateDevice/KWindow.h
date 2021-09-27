#pragma once
#include "KDevice.h"
class KWindow : public KDevice
{
public:
	HINSTANCE m_hInstance;
	HWND m_hWnd;
	DWORD					m_dwWindowStyle;	// ������ ��Ÿ��
	RECT					m_rcWindowBounds;   // ������ ����
	RECT					m_rcWindowClient;   // Ŭ���̾�Ʈ ����	
	UINT					m_iWindowWidth;		// Ŭ���̾�Ʈ ���� ����ũ��
	UINT					m_iWindowHeight;	// �����̾�Ʈ ���� ����ũ��
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

