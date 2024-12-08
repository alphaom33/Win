#pragma once
class IButton {
public:
	virtual void SetSprite(bool on) = 0;
	virtual void Register() = 0;
	virtual void UnRegister() = 0;
	virtual void Clicked() = 0;
};
