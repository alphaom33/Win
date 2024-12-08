#include "Menu.h"
#include "Drawer.h"
#include "Drawer.h"

Menu::Menu(std::wstring text)
{
    pos = new Vector2(100, 150);
    scale = new Vector2(400, 400);
    this->text = text;
    size = 20;
}

Menu::Menu(Vector2* pos, Vector2* scale, std::wstring text, float size)
{
    this->pos = pos;
    this->scale = scale;
    this->text = text;
    this->size = size;
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

Vector2* Menu::GetPos()
{
    return pos;
}

float Menu::GetSize()
{
    return size;
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
