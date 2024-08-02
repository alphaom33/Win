#include "Drawer.h"
#include "Images.h"
#include "string"

std::vector<IDrawable*> Drawer::toDraws;

void Drawer::RegisterDraw(IDrawable *toDraw) {
	toDraws.push_back(toDraw);
}

void Drawer::UnRegisterDraw(IDrawable* toNotDraw) {
	//TODO
}

void Drawer::ReadySprites(HRESULT *hr, ID2D1HwndRenderTarget *pRenderTarget, IWICImagingFactory *iwicFactory) {
	for (auto s : toDraws) {
		if (SUCCEEDED(*hr)) {
			*hr = image::LoadBitmapFromFile(
				pRenderTarget,
				iwicFactory,
				L"C:\\Users\\mBorchert\\Desktop\\dsf.bmp",
				200,
				0,
				s->GetBitmap()
			);
		}
	}
}

void Drawer::DrawSprites(ID2D1HwndRenderTarget* pRenderTarget) {
	for (auto s : toDraws) {
		Vector2 *pos = s->GetPosition();
		Vector2* scale = s->GetScale();
		D2D1_RECT_F rcBrushRect = D2D1::Rect(
			pos->x,
			pos->y,
			pos->x + scale->x,
			pos->y + scale->y
			);
		pRenderTarget->DrawBitmap(
			*s->GetBitmap(),
			rcBrushRect
		);
	}
}
