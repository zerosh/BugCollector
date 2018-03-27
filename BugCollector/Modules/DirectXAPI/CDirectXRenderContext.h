#pragma once
#include "../../Core/RenderingAPI/IRenderContext.h"
#include "CDirectXRenderTargetWindow.h"
#include "CD3DDevice.h"

class CDirectXRenderContext : public IRenderContext
{
private:
	

private: 
	TSharedPtr<CD3DDevice> m_device;
	
	void CreateAndSetDevice();
	void CreateAndSetBackSwapChain();
	void CreateAndSetRenderTargetView();
	void CreateAndSetViewPort();


public:
	CDirectXRenderContext();
	~CDirectXRenderContext();

	virtual TSharedPtr<CRenderTargetWindow> CreateRenderTargetWindow(TSharedPtr<CRenderTargetWindow> InParentWindow = nullptr) override;
	virtual void Initialize() override;
	virtual void Present(TSharedPtr<CRenderTargetWindow> InRenderTarget) override;
	virtual TSharedPtr<CVertexBuffer> CreateVertexBuffer(const FVertexBufferCreateInfo &InVertexBufferCreateInfo) override;

};
