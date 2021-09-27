#include "KCore.h"

bool	KCore::GameRun()
{
    if (!GameFrame()) return false;
    if (!GameRender()) return false;
    return true;
}
bool	KCore::GameInit()
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
        m_rtClient.right,
        m_rtClient.bottom)))
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

    Init();
    return true;
}
bool	KCore::GameFrame()
{
    Frame();
    return true;
}
bool	KCore::GameRender()
{
    PreRender();
    Render();
    PostRender();
    return true;
}
bool	KCore::GameRelease()
{
    Release();
    return true;
}

bool	KCore::Init()
{
    return true;
}
bool	KCore::Frame() {
    return true;
}
bool	KCore::PreRender(){

    float ClearColor[4] = { 1.0f, 1.0f, 0.0f, 1.0f }; //red,green,blue,alpha
    m_pImmediateContext->ClearRenderTargetView(m_pRenderTargetView, ClearColor);

    return true;
}
bool	KCore::Render() {
    return true;
}
bool	KCore::PostRender() {

    assert(m_pImmediateContext);
    m_pSwapChain->Present(0, 0);
    return false;
}
bool	KCore::Release() {
    return true;
}