#include "vector"
#include "IDrawable.h"
#include "wincodec.h"
#pragma once

class Drawer
{
public:
	static void RegisterDraw(IDrawable *toDraw);
	static void ReadySprites(HRESULT* hr, ID2D1HwndRenderTarget* pRenderTarget, IWICImagingFactory* iwicFactory);
	static void DrawSprites(ID2D1HwndRenderTarget* pRenderTarget, D2D1_RECT_F *rcBrushRect);
private:
	static std::vector<IDrawable*> toDraws;
};

