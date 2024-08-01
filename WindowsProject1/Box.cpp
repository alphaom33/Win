#include "Box.h"

Box::Box(HWND hwnd, Vector2* startSize) : TimedCode() {
	left = new Sprite(new Vector2((pos.x - startSize->x) + ((startSize->x / width - 1) * width), pos.y), new Vector2(width, startSize->y), hwnd);
	right = new Sprite(new Vector2(pos.x + startSize->x, pos.y), new Vector2(width, startSize->y), hwnd);
	top = new Sprite(new Vector2(pos.x, (pos.y - startSize->y) + ((startSize->y / width - 1) * width)), new Vector2(startSize->x, width), hwnd);
	bottom = new Sprite(new Vector2(pos.x, pos.y + startSize->y), new Vector2(startSize->x, width), hwnd);

	topLeft = new Sprite(new Vector2(pos.x - startSize->x + ((startSize->x / width - 1) * width), pos.y - startSize->y + ((startSize->y / width - 1) * width)), new Vector2(width, width), hwnd);
	topRight = new Sprite(new Vector2(pos.x + startSize->x, (pos.y - startSize->y) + ((startSize->y / width - 1) * width)), new Vector2(width, width), hwnd);
	bottomLeft = new Sprite(new Vector2(pos.x - startSize->x + ((startSize->x / width - 1) * width), pos.y + startSize->y), new Vector2(width, width), hwnd);
	bottomRight = new Sprite(new Vector2(pos.x + startSize->x, pos.y + startSize->y), new Vector2(width, width), hwnd);
}

void Box::Start() {

}

void Box::Periodic() {
}
