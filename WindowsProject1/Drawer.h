#include "map"
#include "vector"
#include "IDrawable.h"
#include "wincodec.h"
#pragma once

class Drawer
{
public:
	static void RegisterDraw(IDrawable *toDraw, std::vector<std::wstring> toAdd);
	static void UnRegisterDraw(IDrawable* toNotDraw);
	static void ReadySprites(HRESULT* hr, ID2D1HwndRenderTarget* pRenderTarget, IWICImagingFactory* iwicFactory);
	static void DrawSprites(ID2D1HwndRenderTarget* pRenderTarget);
private:
	static std::vector<IDrawable*> toDraws;
	static std::map<std::wstring, ID2D1Bitmap*> bitmaps;
};

