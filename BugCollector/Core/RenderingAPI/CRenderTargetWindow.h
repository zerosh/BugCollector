#pragma once
#include "../Core.h"
#include "CRenderTarget.h"

/*
	Interface between the generic api and a window you can render content to.
*/
class CRenderTargetWindow : public CRenderTarget
{
public:
	/* Set fullscreen window. */
	virtual void SetFullscreen();

	/* Set window fullscreen windowed. */
	virtual void SetFullscreenWindow();

	/* Set windoed mode for this window. */
	virtual void SetWindowed(u32 InW, u32 InH);

	/* Enable or disable vertical sync for this window. */
	virtual void SetVerticalSync(b8 InState);

	/* Resize the window size. */
	virtual void Resize(u32 InW, u32 InH);

	/* Move the window to a location on the monitor. */
	virtual void Move(u32 InX, u32 InY);

	/* Show this window. */
	virtual void Show();

	/* Hide this window. */
	virtual void Hide();

	/* Minimize the window to tray. */
	virtual void Minimize();

	/* Maximize the window */
	virtual void Maximize();

	/* Present the back to front. */
	virtual void SwapFrameBuffer();

	/* Present the window */
	virtual void Present();
};
