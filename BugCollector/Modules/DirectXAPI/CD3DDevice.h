#pragma once

class D3DDevice
{
public:

	ID3D11Device * m_device;
	IDXGISwapChain* m_swapChain;
	ID3D11DeviceContext* m_deviceContext;
	ID3D11RenderTargetView* m_renderTargetView;
	ID3D11Texture2D* m_depthStencilBuffer;
	ID3D11Texture2D *pBackBuffer;
	HWND WindowHandle = nullptr;

	void InitD3D11()
	{
		const auto featureLevel = D3D_FEATURE_LEVEL_11_1;
		m_device = nullptr;
		m_swapChain = nullptr;
		m_deviceContext = nullptr;
		m_renderTargetView = nullptr;
		m_depthStencilBuffer = nullptr;

		DXGI_SWAP_CHAIN_DESC sd;
		ZeroMemory(&sd, sizeof(sd));
		sd.BufferCount = 1;
		sd.BufferDesc.Width = 800; //TODO: GetWindowWidth
		sd.BufferDesc.Height = 600;
		sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		sd.BufferDesc.RefreshRate.Numerator = 60;
		sd.BufferDesc.RefreshRate.Denominator = 1;
		sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		sd.OutputWindow = GetActiveWindow();
		sd.SampleDesc.Count = 1;
		sd.SampleDesc.Quality = 0;
		sd.Windowed = TRUE;

		auto flags = D3D11_CREATE_DEVICE_BGRA_SUPPORT | D3D11_CREATE_DEVICE_DEBUG;

		auto result = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, flags, &featureLevel, 1,
			D3D11_SDK_VERSION, &sd, &m_swapChain, &m_device, nullptr, &m_deviceContext);

		if (FAILED(result))
			__debugbreak();

		m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);

		if (FAILED(m_device->CreateRenderTargetView(pBackBuffer, nullptr, &m_renderTargetView)))
			__debugbreak();

		m_deviceContext->OMSetRenderTargets(1, &m_renderTargetView, nullptr);

		D3D11_VIEWPORT vp;
		vp.Width = 800; //TODO: GetWindowWidth
		vp.Height = 600;
		vp.MinDepth = 0.0f;
		vp.MaxDepth = 1.0f;
		vp.TopLeftX = 0;
		vp.TopLeftY = 0;
		m_deviceContext->RSSetViewports(1, &vp);
	}
};