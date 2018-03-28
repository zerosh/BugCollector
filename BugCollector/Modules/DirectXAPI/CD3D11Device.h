#pragma once

class CD3D11Device
{
public:
	ID3D11DeviceContext* m_deviceContext = nullptr;
	ID3D11Device* m_nativeD3DDevice = nullptr;
	
	~CD3D11Device()
	{
		m_deviceContext->Release();
		m_nativeD3DDevice->Release();

	}
};