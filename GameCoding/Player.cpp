#include "pch.h"
#include "Player.h"
#include "InputManager.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::BeginPlay()
{
	Super::BeginPlay();


}

void Player::Tick()
{
	Super::Tick();

	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::S)) {

	}
}

void Player::Render(HDC hdc)
{
	Super::Render(hdc);


}
