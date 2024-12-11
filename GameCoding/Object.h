#pragma once

enum class ObjectType
{
	None,
	Player,
	Projectile,
};

enum class MoveDir
{
	Left,
	Right,
};

class Object
{
public:
	Object(ObjectType type);
	virtual ~Object();

	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

public:
	ObjectType GetObjectType() { return _type; }

	Vector	GetPos() { return _pos; }
	void	SetPos(Vector pos) { _pos = pos; }

	float	GetRadius() { return _radius; }

protected:
	ObjectType	_type = ObjectType::None;
	MoveDir		_dir = MoveDir::Right;
	Stat		_stat = {};
	Vector		_pos = {};
	float		_radius = 0.f;
};

