#include "Drawer.h"
#include "Images.h"
#include "string"
#include "Print.h"

std::vector<IDrawable*> Drawer::toDraws;
std::map<std::wstring, ID2D1Bitmap*> Drawer::bitmaps;

std::vector<ITextable*> Drawer::toWrite;

void Drawer::RegisterDraw(IDrawable *toDraw, std::vector<std::wstring> toAdd) {
	toDraws.push_back(toDraw);

	for (int i = 0; i < toAdd.size(); i++) {
		if (!bitmaps.count(toAdd[i])) bitmaps[toAdd[i]] = NULL;
	}
}

void Drawer::UnRegisterDraw(IDrawable* toNotDraw) {
	//TODO
}

void Drawer::ReadySprites(HRESULT *hr, ID2D1HwndRenderTarget *pRenderTarget, IWICImagingFactory *iwicFactory) {
	for (auto &kv : bitmaps) {
		if (SUCCEEDED(*hr)) {
			*hr = image::LoadBitmapFromFile(
				pRenderTarget,
				iwicFactory,
				kv.first.c_str(),
				200,
				0,
				&kv.second
			);
		}
	}
}

void Drawer::DrawSprites(ID2D1HwndRenderTarget* pRenderTarget) {
	for (auto s : toDraws) {
		if (!bitmaps.count(s->GetBitmap())) {
			bitmaps[s->GetBitmap()] = NULL;
		}
		if (bitmaps[s->GetBitmap()] == NULL) {
			continue;
		}

		Vector2* pos = s->GetPosition();
		Vector2* scale = s->GetScale();
		D2D1_RECT_F rcBrushRect = D2D1::Rect(
			pos->x,
			pos->y,
			pos->x + scale->x,
			pos->y + scale->y
			);
		pRenderTarget->DrawBitmap(
			bitmaps[s->GetBitmap()],
			rcBrushRect
		);
	}
}

void Drawer::UnRegisterText(ITextable* text)
{
	auto index = std::find(toWrite.begin(), toWrite.end(), text);
	for (auto a : toWrite) {
		OutputDebugString(a->GetText().c_str());
	}
	if (index != toWrite.end()) {
		OutputDebugString(L"gone");
		toWrite.erase(index);
	}
}

void Drawer::RegisterText(ITextable* text)
{
	toWrite.push_back(text);
}

HRESULT Drawer::DrawTexts(ID2D1HwndRenderTarget* pRenderTarget, IDWriteFactory* pDWriteFactory) {
	ID2D1SolidColorBrush* brush;
	HRESULT hr = pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1), &brush);

	if (SUCCEEDED(hr)) {
		for (ITextable* t : toWrite)
		{
			//OutputDebugString(L"a");
			IDWriteTextFormat* pTextFormat;
			hr = pDWriteFactory->CreateTextFormat(
				L"Gabriola",
				NULL,
				DWRITE_FONT_WEIGHT_REGULAR,
				DWRITE_FONT_STYLE_NORMAL,
				DWRITE_FONT_STRETCH_NORMAL,
				t->GetSize(),
				L"en-us",
				&pTextFormat
			);

			if (SUCCEEDED(hr)) {
				D2D1_RECT_F a{
					a.bottom = 0,
					a.top = t->GetPos()->y,
					a.left = t->GetPos()->x,
					a.right = 100000,
				};
				pRenderTarget->DrawTextW(t->GetText().c_str(), t->GetText().length(), pTextFormat, &a, brush);
			}
		}
	}
//	OutputDebugString(L"\n");
	return hr;
}
