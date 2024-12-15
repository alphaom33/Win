#include "map"
#include "vector"
#include "IDrawable.h"
#include "wincodec.h"
#include "dwrite.h"
#include "ITextable.h"

#pragma once
class Drawer
{
public:
	static void RegisterDraw(IDrawable *toDraw, std::vector<std::wstring> toAdd);
	static void UnRegisterDraw(IDrawable* toNotDraw);
	static void ReadySprites(HRESULT* hr, ID2D1HwndRenderTarget* pRenderTarget, IWICImagingFactory* iwicFactory);
	static void DrawSprites(ID2D1HwndRenderTarget* pRenderTarget);

	static void UnRegisterText(ITextable* text);
	static void RegisterText(ITextable* text);
	static HRESULT DrawTexts(ID2D1HwndRenderTarget* pRenderTarget, IDWriteFactory* pDWriteFactory);

private:
	static std::vector<IDrawable*> toDraws;
	static std::vector<ITextable*> toWrite;
	static std::map<std::wstring, ID2D1Bitmap*> bitmaps;
};

