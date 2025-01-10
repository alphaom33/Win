#include "Menu.h"
#include "Drawer.h"
#include "Box.h"

Menu::Menu(std::wstring text) : Menu(text, D2D1::ColorF(1, 1, 1))
{
}

Menu::Menu(std::wstring text, D2D1::ColorF color) : color(color)
{
    pos = Box::GetPos();
    scale = Box::GetScale();
    this->text = text;
    size = 20;
    this->color = color;
}

Menu::Menu(Vector2 pos, Vector2 scale, std::wstring text, float size) : Menu(pos, scale, text, size, D2D1::ColorF(1, 1, 1))
{
}

Menu::Menu(Vector2 pos, Vector2 scale, std::wstring text, float size, D2D1::ColorF color) : color(color)
{
    this->pos = pos;
    this->scale = scale;
    this->text = text;
    this->size = size;
    this->color = color;
}

void Menu::SetCurrent(bool current)
{
    if (current) Drawer::RegisterText(this);
    else Drawer::UnRegisterText(this);
}

std::wstring Menu::GetText()
{
    return text;
}

Vector2 Menu::GetPos()
{
    return pos;
}

float Menu::GetSize()
{
    return size;
}

D2D1::ColorF Menu::GetColor()
{
    return color;
}

void Menu::Enter()
{
}

void Menu::Periodic()
{
}

void Menu::Exit()
{
    Drawer::UnRegisterText(this);
}

void Menu::setText(std::wstring text)
{
    this->text = text;
}

void Menu::setColor(D2D1::ColorF color)
{
    this->color = color;
}
