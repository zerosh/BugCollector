#pragma once
#include "CUIElement.h"

class CUIPanel : public CUIElement
{
private:
public:
	static TSharedPtr<CUIPanel> Create()
	{
		return TSharedPtr<CUIPanel>(new CUIPanel());
	}
};