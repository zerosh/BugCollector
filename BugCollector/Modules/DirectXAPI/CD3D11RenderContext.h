#pragma once
#include "../../Core/RenderingAPI/IRenderContext.h"
#include "CD3D11RenderTargetWindow.h"
#include "CD3D11Device.h"
#include "CD3D11VertexBuffer.h"

class CD3D11RenderContext : public IRenderContext
{
private: 
	TSharedPtr<CD3D11Device> D3DDevice;
	void CreateAndSetDevice();
public:
	CD3D11RenderContext();
	~CD3D11RenderContext();

	virtual TSharedPtr<CRenderTargetWindow> CreateRenderTargetWindow(TSharedPtr<CRenderTargetWindow> InParentWindow = nullptr) override;
	virtual void Initialize() override;
	virtual void Present(TSharedPtr<CRenderTargetWindow> InRenderTarget) override;
	virtual TSharedPtr<CVertexBuffer> CreateVertexBuffer(const FVertexBufferCreateInfo &InVertexBufferCreateInfo) override;

};
