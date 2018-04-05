#include "CUIPanel.h"



TSharedPtr<CUIPanel> CUIPanel::Create()
{
	return TSharedPtr<CUIPanel>(new CUIPanel());
}
