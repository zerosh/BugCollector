#pragma once

class CD3DDevice
{
public:
	ID3D11DeviceContext* m_deviceContext = nullptr;
	ID3D11Device* m_nativeD3DDevice = nullptr;
	
	~CD3DDevice()
	{
		m_deviceContext->Release();
		m_nativeD3DDevice->Release();

	}
};