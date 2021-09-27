#pragma once
#include <Windows.h>
#include <tchar.h>
#include <d3d11.h>
#include <assert.h>
#pragma comment		(lib, "dxgi.lib")
#pragma comment		(lib, "d3d11.lib")

class KDevice 
{
private:
	ID3D11Device* m_pd3dDevice;		// ����̽� ��ü
	IDXGISwapChain* m_pSwapChain;		// ����ü�� ��ü
	ID3D11RenderTargetView* m_pRenderTargetView;// ���� ����Ÿ�� ��
	D3D11_VIEWPORT			m_ViewPort;			// ����Ʈ 
	D3D_DRIVER_TYPE         m_driverType;		// ����̽� Ÿ��( ����Ʈ:�ϵ���� ���� )
	IDXGIFactory* m_pGIFactory;		// DXGI ��ü
	ID3D11DeviceContext* m_pImmediateContext;// ����̽� ���ؽ�Ʈ
	D3D_DRIVER_TYPE			m_DriverType;		// ����̽� Ÿ��
	D3D_FEATURE_LEVEL       m_FeatureLevel;		// DirectX�� ��ɼ���

public:
	void DX_CHECK(HRESULT hr, const TCHAR* funtion);
	HRESULT	CreateDevice();
	HRESULT CreateGIFactory();
	HRESULT CreateSwapChain(HWND hWnd, UINT iWidth, UINT iHeight);
	HRESULT	SetRenderTargetView();
	HRESULT	SetViewPort();
	bool CleanupDevice();

	virtual bool PreRander();
	virtual bool Rander();
	virtual bool PostRander();

public:
	KDevice(void);
	virtual ~KDevice(void);

	

};

