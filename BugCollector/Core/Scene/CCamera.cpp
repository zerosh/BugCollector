#include "CCamera.h"



TSharedPtr<CCamera> CCamera::Create()
{
	return TSharedPtr<CCamera>(new CCamera());
}
