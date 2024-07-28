#include "Drawer.h"
#include "Images.h"

std::vector<IDrawable*> Drawer::toDraws;

void Drawer::RegisterDraw(IDrawable *toDraw) {
	toDraws.push_back(toDraw);
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

void Drawer::DrawSprites(ID2D1HwndRenderTarget* pRenderTarget, D2D1_RECT_F *rcBrushRect) {
	for (auto s : toDraws) {
		pRenderTarget->DrawBitmap(
			*s->GetBitmap(),
			rcBrushRect
		);
	}
	toDraws = std::vector<IDrawable*>();
}
