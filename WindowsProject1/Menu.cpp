#include "Menu.h"
#include "Drawer.h"

Menu::Menu(Vector2* pos, Vector2* scale, std::wstring text, float size)
{
    this->pos = pos;
    this->scale = scale;
    this->text = text;
    this->size = size;
}

std::wstring Menu::GetText()
{
    return text;
}

Vector2* Menu::GetPos()
{
    return pos;
}

float Menu::GetWidth()
{
    return (float)scale->x;
}

float Menu::GetSize()
{
    return size;
}
