#include "PlayerBullet.h"

void PlayerBullet::Initialize()
{
	playerBulletPosX_ = 100;
	playerBulletPosY_ = 100;
	playerBulletSpeedX_ = 6;
	playerBulletSpeedY_ = 6;
	playerBulletRadius_ = 20;
	playerBulletNum_ = 20;
	PlayerIsBulletShot_ = true;
}

void PlayerBullet::Update()
{

}

void PlayerBullet::Draw()
{
}

void PlayerBullet::SetPlayerBulletInfo(int posX, int posY, int speedX, int speedY, int radius)
{
	posX = playerBulletPosX_;
	posY = playerBulletPosY_;
	speedX = playerBulletSpeedX_;
	speedY = playerBulletSpeedY_;
	radius = playerBulletRadius_;
}

void PlayerBullet::BulletOnColision()
{
	PlayerIsBulletShot_ = true;
}