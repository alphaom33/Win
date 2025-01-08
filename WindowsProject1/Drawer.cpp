#include <filesystem>

#include "Drawer.h"
#include "Images.h"
#include "string"
#include "Print.h"
#include "MoreWM.h"

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
	auto index = std::find(toDraws.begin(), toDraws.end(), toNotDraw);
	if (index != toDraws.end()) {
		toDraws.erase(index);
	}
}

void Drawer::ReadySprites(HRESULT *hr, ID2D1HwndRenderTarget *pRenderTarget, IWICImagingFactory *iwicFactory) {
	std::wstring path = std::filesystem::current_path().wstring() + L"\\";
	for (auto &kv : bitmaps) {
		if (kv.second == NULL && SUCCEEDED(*hr)) {
			*hr = image::LoadBitmapFromFile(
				pRenderTarget,
				iwicFactory,
				(path + kv.first).c_str(),
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

		Vector2 pos = s->GetPosition();
		Vector2 scale = s->GetScale();
		D2D1_RECT_F rcBrushRect = D2D1::Rect(
			pos.x,
			pos.y,
			pos.x + scale.x,
			pos.y + scale.y
			);

		D2D1_POINT_2F point = s->FromCorner() ?  D2D1::Point2F(pos.x, pos.y) : D2D1::Point2F(pos.x + scale.x / 2, pos.y + scale.y / 2);
		pRenderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(s->GetRotation(), point));
		pRenderTarget->DrawBitmap(
			bitmaps[s->GetBitmap()],
			rcBrushRect,
			1.f,
			D2D1_BITMAP_INTERPOLATION_MODE_LINEAR
		);
		pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	}
}

void Drawer::UnRegisterText(ITextable* text)
{
	auto index = std::find(toWrite.begin(), toWrite.end(), text);
	if (index != toWrite.end()) {
		toWrite.erase(index);
	}
	else
	{
		if (text != NULL) OutputDebugString((text->GetText() + L" ").c_str());
		OutputDebugString(L"oh goodness mate that don't exist ere you imbecile\n");
	}
}

void Drawer::RegisterText(ITextable* text)
{
	toWrite.push_back(text);
}

HRESULT Drawer::DrawTexts(ID2D1HwndRenderTarget* pRenderTarget, IDWriteFactory* pDWriteFactory) {
	ID2D1SolidColorBrush* brush;

	HRESULT hr = S_OK;
	for (ITextable* t : toWrite)
	{
		HRESULT hr = pRenderTarget->CreateSolidColorBrush(t->GetColor(), &brush);
		if (SUCCEEDED(hr)) {
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
					a.top = t->GetPos().y,
					a.left = t->GetPos().x,
					a.right = 100000,
				};
				pRenderTarget->DrawTextW(t->GetText().c_str(), t->GetText().length(), pTextFormat, &a, brush);
			}
		}
	}
	return hr;
}

void Drawer::Reset()
{
	toDraws.clear();
	bitmaps.clear();
	toWrite.clear();
}
