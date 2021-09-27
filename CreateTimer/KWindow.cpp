#include "KWindow.h"
KWindow* g_pWindow = nullptr;

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
    
    GetWindowRect(m_hWnd, &m_rcWindowBounds);
    GetClientRect(m_hWnd, &m_rcWindowClient);

    m_iWindowWidth = m_rcWindowClient.right - m_rcWindowClient.left;
    m_iWindowHeight = m_rcWindowClient.bottom - m_rcWindowClient.top;

    // WM_SHOW
    ShowWindow(m_hWnd, nCmdShow);
    return true;

}
bool KWindow::GameInit()
{
    HRESULT hr;
    if (FAILED(CreateGIFactory()))
    {
        return false;
    }
    if (FAILED(CreateDevice()))
    {
        return false;
    }
    if (FAILED(CreateSwapChain(m_hWnd,
        m_iWindowWidth,
        m_iWindowHeight)))
    {
        return false;
    }
    if (FAILED(SetRenderTargetView()))
    {
        return false;
    }
    if (FAILED(SetViewPort()))
    {
        return false;
    }


    
    return true;
}
bool KWindow::GameRun()
{
    PreRander();
    Rander();
    PostRander();
    return true;
}
bool KWindow::GameRelease()
{

    CleanupDevice();
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


int APIENTRY wWinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR IpCmdLine,
    _In_ int nCmdShow)
{
    KWindow gSample;
    if (!gSample.InitWindow(hInstance, nCmdShow, L"CreateWindow"))
    {
        MessageBox(0, _T("초기화 실패"), _T("Fatal Error"), MB_OK);
        return 0;
    }
    ShowCursor(TRUE);
    gSample.Run();
    return 1;
}