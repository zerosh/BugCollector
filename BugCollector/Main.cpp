#include "Core/CBootstrap.h"
#include "Editor/CEditorApplication.h"

int main()
{
	CEditorApplication editorApplication;
	CBootstrap::Run(&editorApplication);


	return 0;
}