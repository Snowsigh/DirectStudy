#include "KWindow.h"

KWindow* g_pWindow = NULL;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    // 메세지 핸들링
    assert(g_pWindow);
    return g_pWindow->MsgProc(hWnd, message, wParam, lParam);
}
LRESULT  KWindow::MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

bool KWindow::InitWindow(HINSTANCE hInstance, int nCmdShow, const WCHAR* strWindowTitle)
{
    m_hInstance = hInstance;

    WNDCLASSEXW wcex;
    ZeroMemory(&wcex, sizeof(WNDCLASSEXW));
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.hInstance = hInstance;
    wcex.hbrBackground = CreateSolidBrush(RGB(133, 143, 108));
    wcex.lpszClassName = L"KKO_Project";
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    // 앞으로 이런 윈도우 생성할테니 등록해줘(운영체제)
    if (!RegisterClassExW(&wcex))
    {
        return false;
    }
    RECT rc = { 0, 0, 1024, 768 };
    // 작업영역(  타이틀 바/경계선/메뉴/스크롤 바 등의 영역을 제외한 영역), 윈도우 스타일, 메뉴여부
    AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
    // 윈도우 생성 함수
    m_hWnd = CreateWindowEx(
        0,
        L"KKO_Project",
        strWindowTitle,
        WS_OVERLAPPEDWINDOW,
        0,
        0,
        rc.right - rc.left,
        rc.bottom - rc.top,
        NULL,
        NULL,
        hInstance,
        NULL);
    if (m_hWnd == NULL)
    {
        return false;
    }
    
    GetWindowRect(m_hWnd, &m_rtWindow);
    GetClientRect(m_hWnd, &m_rtClient);
    // WM_SHOW
    ShowWindow(m_hWnd, nCmdShow);
    return true;

}
bool KWindow::GameInit()
{
    return true;
}
bool KWindow::GameRun()
{
    return true;
}
bool KWindow::GameRelease()
{
    return true;
}
bool KWindow::Run()
{
    GameInit();
    MSG msg;
    while (m_bGameRun)
    {
        if (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                break;
            }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            m_bGameRun = GameRun();
        }
    }
    GameRelease();
    return true;
}
KWindow::KWindow(void) : m_bGameRun(true)
{
    m_hInstance = NULL;
    m_hWnd = NULL;
    g_pWindow = this;
}
KWindow::~KWindow(void)
{
}