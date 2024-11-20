#include "pch.h"
#include "CameraComponent.h"
#include "SceneManager.h"
#include "Actor.h"

CameraComponent::CameraComponent()
{
}

CameraComponent::~CameraComponent()
{
}

void CameraComponent::BeginPlay()
{
}

void CameraComponent::TickComponent()
{
	if (_owner == nullptr)
		return;

	Vec2 pos = _owner->GetPos();

	pos.x = ::clamp(pos.x, 400.f, 3024.f - 400.f);
	pos.y = ::clamp(pos.y, 300.f, 2064.f - 300.f);

	GET_SINGLE(SceneManager)->SetCameraPos(pos);
}
