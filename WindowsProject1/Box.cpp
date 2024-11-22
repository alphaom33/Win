#include "Box.h"

Box::Box(HWND hwnd, Vector2* startSize) : TimedCode(State::BULLET)
{
	left = new SpriteCollider(new Vector2((pos.x - startSize->x) + ((startSize->x / width - 1) * width), pos.y), new Vector2(width, startSize->y), hwnd);
	right = new SpriteCollider(new Vector2(pos.x + startSize->x, pos.y), new Vector2(width, startSize->y), hwnd);
	top = new SpriteCollider(new Vector2(pos.x, (pos.y - startSize->y) + ((startSize->y / width - 1) * width)), new Vector2(startSize->x, width), hwnd);
	bottom = new SpriteCollider(new Vector2(pos.x, pos.y + startSize->y), new Vector2(startSize->x, width), hwnd);

	topLeft = new SpriteCollider(new Vector2(pos.x - startSize->x + ((startSize->x / width - 1) * width), pos.y - startSize->y + ((startSize->y / width - 1) * width)), new Vector2(width, width), hwnd);
	topRight = new SpriteCollider(new Vector2(pos.x + startSize->x, (pos.y - startSize->y) + ((startSize->y / width - 1) * width)), new Vector2(width, width), hwnd);
	bottomLeft = new SpriteCollider(new Vector2(pos.x - startSize->x + ((startSize->x / width - 1) * width), pos.y + startSize->y), new Vector2(width, width), hwnd);
	bottomRight = new SpriteCollider(new Vector2(pos.x + startSize->x, pos.y + startSize->y), new Vector2(width, width), hwnd);
}

void Box::Enter()
{
}

void Box::Periodic()
{
}

void Box::Exit()
{
}
