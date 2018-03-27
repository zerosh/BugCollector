#pragma once
#include "../../Core/RenderingAPI/CRenderTargetWindow.h"
#include "../../Core/Platform/Platform.h"
#include "CD3DDevice.h"

class CDirectXRenderTargetWindow : public CRenderTargetWindow
{
private:
	CPlatformWindow PlatformWindow;
	TSharedPtr<CD3DDevice> m_device;
public:
	CDirectXRenderTargetWindow(TSharedPtr<CD3DDevice> InD3DDevice)
	{
		m_device = InD3DDevice;
		// Temp setup to get started.
		FPlatformWindowCreateInfo createInfo;
		createInfo.bCreateDebugWindow = false;
		createInfo.bEnableDebugging = false;
		createInfo.bEnableVerticalSync = true;
		createInfo.Width = 1024;
		createInfo.Height = 768;

		PlatformWindow.Initialize(createInfo);
	}


	virtual void SetFullscreen() override
	{

	}


	virtual void SetFullscreenWindow() override
	{
	}


	virtual void SetWindowed(u32 InW, u32 InH) override
	{

	}


	virtual void SetVerticalSync(b8 InState) override
	{
	}


	virtual void Resize(u32 InW, u32 InH) override
	{
		// Release all reference to the SwapChain
		m_device->m_deviceContext->OMSetRenderTargets(0, 0, 0);
		m_device->m_renderTargetView->Release();

		HRESULT hr;

		if (FAILED(hr = m_device->m_swapChain->ResizeBuffers(0, InW, InH, DXGI_FORMAT_UNKNOWN, 0)))
		{
			__debugbreak();
		}


		ID3D11Texture2D* pBuffer;
		if (FAILED(hr = m_device->m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&pBuffer)))
		{
			__debugbreak();
		}


		if (FAILED(hr = m_device->m_nativeD3DDevice->CreateRenderTargetView(pBuffer, nullptr, &m_device->m_renderTargetView)))
		{
			__debugbreak();
		}

		pBuffer->Release();

		m_device->m_deviceContext->OMSetRenderTargets(1, &m_device->m_renderTargetView, nullptr);
		

		// Set up the viewport.
		D3D11_VIEWPORT vp;
		vp.Width = InW;
		vp.Height = InH;
		vp.MinDepth = 0.0f;
		vp.MaxDepth = 1.0f;
		vp.TopLeftX = 0;
		vp.TopLeftY = 0;

		m_device->m_deviceContext->RSSetViewports(1, &vp);


	}


	virtual void Move(u32 InX, u32 InY) override
	{
	}


	virtual void Show() override
	{
	}


	virtual void Hide() override
	{
	}


	virtual void Minimize() override
	{
	}


	virtual void Maximize() override
	{
	}


	virtual void SwapFrameBuffer() override
	{
	}


	virtual void Present() override
	{
		float clearColor[3] = { 1.0f,1.0f,0.0f };

		m_device->m_deviceContext->ClearRenderTargetView(m_device->m_renderTargetView, clearColor);

		if(bUseVerticalSync)
			m_device->m_swapChain->Present(1, 0);
		else
			m_device->m_swapChain->Present(0, 0);
		
	}

};