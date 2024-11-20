#include "pch.h"
#include "SphereCollider.h"
#include "BoxCollider.h"
#include "SceneManager.h"
#include "Actor.h"

BoxCollider::BoxCollider() : Collider(ColliderType::Box)
{

}

BoxCollider::~BoxCollider()
{

}

void BoxCollider::BeginPlay()
{
	Super::BeginPlay();


}

void BoxCollider::TickComponent()
{
	Super::TickComponent();


}

void BoxCollider::Render(HDC hdc)
{
	Super::Render(hdc);

	if (_showDebug == false)
		return;

	Vec2 cameraPos = GET_SINGLE(SceneManager)->GetCameraPos();
	Vec2 pos = GetOwner()->GetPos();
	pos.x -= (cameraPos.x - GWinSizeX / 2);
	pos.y -= (cameraPos.y - GWinSizeY / 2);


	HBRUSH myBrush = (HBRUSH)::GetStockObject(NULL_BRUSH);
	HBRUSH oldBrush = (HBRUSH)::SelectObject(hdc, myBrush);
	HPEN myPen = CreatePen(PS_SOLID, 1, RGB(255, 255, 0));
	HPEN oldPen = (HPEN)::SelectObject(hdc, myPen);

	Utils::DrawRect(hdc, pos, _size.x, _size.y);

	::SelectObject(hdc, oldBrush);
	::DeleteObject(myBrush);
	::SelectObject(hdc, oldPen);
	::DeleteObject(myPen);
}

bool BoxCollider::CheckCollision(Collider* other)
{
	switch (other->GetColliderType()) {
	case ColliderType::Sphere:
		return CheckCollisionBox2Box(this, static_cast<BoxCollider*>(other));
	case ColliderType::Box:
		return CheckCollisionSphere2Box(static_cast<SphereCollider*>(other), this);
	}

	return false;
}
