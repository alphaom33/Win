#include "Drawer.h"
#include "Images.h"
#include "string"
#include "Print.h"

std::vector<IDrawable*> Drawer::toDraws;
std::map<std::wstring, ID2D1Bitmap*> Drawer::bitmaps;

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
