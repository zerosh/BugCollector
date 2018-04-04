#include "Core/CBootstrap.h"
#include "Editor/CEditorApplication.h"
//#include <vld.h>
int main()
{
	CEditorApplication editorApplication;
	CBootstrap::Run(&editorApplication);

	printf("LOL");
	return 0;
}