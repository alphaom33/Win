#include "Menu.h"
#include "Drawer.h"
#include "Drawer.h"

Menu::Menu(Vector2* pos, Vector2* scale, std::wstring text, float size) : TimedCode(State::MENU)
{
    this->pos = pos;
    this->scale = scale;
    this->text = text;
    this->size = size;
}

void Menu::SetCurrent()
{
    Drawer::RegisterText(this);
}

void Menu::SetNotCurrent()
{
    Drawer::UnRegisterText(this);
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
