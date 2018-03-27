#pragma once

class CD3DDevice
{
public:
	ID3D11DeviceContext* m_deviceContext = nullptr;
	ID3D11Device* m_nativeD3DDevice = nullptr;
	IDXGISwapChain1* m_swapChain[3] = { nullptr, nullptr };
	
	ID3D11RenderTargetView* m_renderTargetView[3] = { nullptr, nullptr };
	ID3D11Texture2D* m_depthStencilBuffer = nullptr;
	ID3D11Texture2D* pBackBuffer = nullptr;

	~CD3DDevice()
	{
		m_deviceContext->Release();
		m_nativeD3DDevice->Release();

		for (u32 i = 0; i < 3; i++)
		{
			m_swapChain[i]->Release();
			m_renderTargetView[i]->Release();
		}
			
		
	
		m_depthStencilBuffer->Release();
		pBackBuffer->Release();
	}
};