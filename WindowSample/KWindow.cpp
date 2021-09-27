#include "KWindow.h"

KWindow* g_pWindow = NULL;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    // �޼��� �ڵ鸵
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
    // ������ �̷� ������ �������״� �������(�ü��)
    if (!RegisterClassExW(&wcex))
    {
        return false;
    }
    RECT rc = { 0, 0, 1024, 768 };
    // �۾�����(  Ÿ��Ʋ ��/��輱/�޴�/��ũ�� �� ���� ������ ������ ����), ������ ��Ÿ��, �޴�����
    AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
    // ������ ���� �Լ�
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