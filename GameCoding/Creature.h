#pragma once
#include "GameObject.h"

class Creature : public GameObject
{
	using Super = GameObject;
public:
	Creature();
	virtual ~Creature() override;

	virtual void BeginPlay() override;
	virtual void Tick() override;
	virtual void Render(HDC hdc) override;

protected:
	virtual void TickIdle() override {}
	virtual void TickMove() override {}
	virtual void TickSkill() override {}
	virtual void UpdateAnimation() override {}

protected:
	void SetStat(Stat stat) { _stat = stat; }
	Stat& GetStat() { return _stat; }

protected:
	Stat _stat;
};

