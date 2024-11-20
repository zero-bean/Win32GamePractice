#pragma once

class Actor;

class Component
{
public:
	Component();
	virtual ~Component();

	virtual void BeginPlay();
	virtual void TickComponent();
	virtual void Render(HDC hdc) {};

	Actor* GetOwner() { return _owner; }
	void SetOwner(Actor* owner) { _owner = owner; }

protected:
	Actor* _owner;
};

