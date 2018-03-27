#pragma once

class CD3DDevice
{
public:
	ID3D11DeviceContext* m_deviceContext = nullptr;
	ID3D11Device* m_nativeD3DDevice = nullptr;
	IDXGISwapChain1* m_swapChain = nullptr;
	ID3D11RenderTargetView* m_renderTargetView = nullptr;
	ID3D11Texture2D* m_depthStencilBuffer = nullptr;
	ID3D11Texture2D* pBackBuffer = nullptr;

	CD3DDevice() { };
	
};