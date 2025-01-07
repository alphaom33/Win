#include "Box.h"

Vector2 Box::pos;
Vector2 Box::size;

Box::Box(HWND hwnd, Vector2 p_pos, Vector2 startSize, int width) : TimedCode(State::BULLET)
{
	pos = p_pos;
	size = startSize;

	left = new SpriteCollider(Vector2((p_pos.x - startSize.x) + ((startSize.x / width - 1) * width), p_pos.y), Vector2(width, startSize.y), hwnd, L"C:\\Users\\mBorchert\\Desktop\\wall.bmp", 0, false);
	right = new SpriteCollider(Vector2(p_pos.x + startSize.x, p_pos.y), Vector2(width, startSize.y), hwnd, L"C:\\Users\\mBorchert\\Desktop\\wall.bmp", 180, false);
	new Sprite(Vector2(p_pos.x + startSize.x, (p_pos.y - startSize.y) + ((startSize.y / width - 1) * width)), Vector2(width, startSize.x), hwnd, L"C:\\Users\\mBorchert\\Desktop\\wall.bmp", 90, true);
	new Sprite(Vector2(p_pos.x, p_pos.y + startSize.y + width), Vector2(width, startSize.x), hwnd, L"C:\\Users\\mBorchert\\Desktop\\wall.bmp", 270, true);
	new Collider(Vector2(p_pos.x, (p_pos.y - startSize.y) + ((startSize.y / width - 1) * width)), Vector2(startSize.x, width));
	new Collider(Vector2(p_pos.x, p_pos.y + startSize.y), Vector2(startSize.x, width));

	Vector2 block = Vector2(width + 2, width + 2);
	topLeft = new SpriteCollider(Vector2(p_pos.x - startSize.x + ((startSize.x / width - 1) * width), p_pos.y - startSize.y + ((startSize.y / width - 1) * width)), block, hwnd, L"C:\\Users\\mBorchert\\Desktop\\corner.bmp", 270, false);
	topRight = new SpriteCollider(Vector2(p_pos.x + startSize.x, (p_pos.y - startSize.y) + ((startSize.y / width - 1) * width)), block, hwnd, L"C:\\Users\\mBorchert\\Desktop\\corner.bmp", 0, false);
	bottomLeft = new SpriteCollider(Vector2(p_pos.x - startSize.x + ((startSize.x / width - 1) * width), p_pos.y + startSize.y), block, hwnd, L"C:\\Users\\mBorchert\\Desktop\\corner.bmp", 180, false);
	bottomRight = new SpriteCollider(Vector2(p_pos.x + startSize.x, p_pos.y + startSize.y), block, hwnd, L"C:\\Users\\mBorchert\\Desktop\\corner.bmp", 90, false);
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

Vector2 Box::GetPos()
{
	return pos;
}

Vector2 Box::GetScale()
{
	return size;
}

void Box::SpawnBullet(IBullet* bullet)
{
	Vector2 delta = Vector2(
		rand() / (RAND_MAX / (size.x - pos.x)),
		rand() / (RAND_MAX / (size.y - pos.y)));

	bullet->SetPos(delta + pos);
}

void Box::EdgeBullet(IBullet* bullet)
{
	int side = rand() / (RAND_MAX / 4);
	switch (side) {
	case 0:
		bullet->SetPos(Vector2(pos.x + (rand() / (RAND_MAX / size.x)), pos.y));
		break;
	case 1:
		bullet->SetPos(Vector2(pos.x + (rand() / (RAND_MAX / size.x)), pos.y + size.y));
		break;
	case 2:
		bullet->SetPos(Vector2(pos.x, pos.y + (rand() / (RAND_MAX / size.y))));
		break;
	case 3:
		bullet->SetPos(Vector2(pos.x + size.x, pos.y + (rand() / (RAND_MAX / size.y))));
		break;
	}
}
