#include "Box.h"

Vector2* Box::pos;
Vector2* Box::size;

Box::Box(HWND hwnd, Vector2* p_pos, Vector2* startSize, int width) : TimedCode(State::BULLET)
{
	pos = p_pos;
	size = startSize;

	left = new SpriteCollider(new Vector2((p_pos->x - startSize->x) + ((startSize->x / width - 1) * width), p_pos->y), new Vector2(width, startSize->y), hwnd);
	right = new SpriteCollider(new Vector2(p_pos->x + startSize->x, p_pos->y), new Vector2(width, startSize->y), hwnd);
	top = new SpriteCollider(new Vector2(p_pos->x, (p_pos->y - startSize->y) + ((startSize->y / width - 1) * width)), new Vector2(startSize->x, width), hwnd);
	bottom = new SpriteCollider(new Vector2(p_pos->x, p_pos->y + startSize->y), new Vector2(startSize->x, width), hwnd);

	topLeft = new SpriteCollider(new Vector2(p_pos->x - startSize->x + ((startSize->x / width - 1) * width), p_pos->y - startSize->y + ((startSize->y / width - 1) * width)), new Vector2(width, width), hwnd);
	topRight = new SpriteCollider(new Vector2(p_pos->x + startSize->x, (p_pos->y - startSize->y) + ((startSize->y / width - 1) * width)), new Vector2(width, width), hwnd);
	bottomLeft = new SpriteCollider(new Vector2(p_pos->x - startSize->x + ((startSize->x / width - 1) * width), p_pos->y + startSize->y), new Vector2(width, width), hwnd);
	bottomRight = new SpriteCollider(new Vector2(p_pos->x + startSize->x, p_pos->y + startSize->y), new Vector2(width, width), hwnd);
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

Vector2* Box::GetPos()
{
	return pos;
}

Vector2* Box::GetScale()
{
	return size;
}

void Box::SpawnBullet(IBullet* bullet)
{
	bullet->SetPos(*new Vector2(
			rand() / (RAND_MAX / (size->x - pos->x)),
			rand() / (RAND_MAX / (size->y - pos->y))) +
		*pos);
}

void Box::EdgeBullet(IBullet* bullet)
{
	Vector2* signs = new Vector2(
		rand() / (RAND_MAX / 2) == 0 ? -1 : 1, 
		rand() / (RAND_MAX / 2) == 0 ? -1 : 1);

	bullet->SetPos(*(*signs * *size) + *pos);

}
