#include "PlayerBullet.h"

void PlayerBullet::Initialize()
{
	playerBulletPosX_ = 100;
	playerBulletPosY_ = 100;
	playerBulletSpeedX_ = 6;
	playerBulletSpeedY_ = 6;
	playerBulletRadius_ = 20;
	playerBulletNum_ = 20;
	playerIsBulletShot_ = true;
	playerBulletPoint_;
}

void PlayerBullet::Update()
{
	playerIsBulletShot_ = false;


	if (playerIsBulletShot_ == true)
	{
		playerBulletPosX_ -= playerBulletSpeedX_;
	}

	if (playerBulletPosX_ - playerBulletRadius_ < 0)
	{
		playerIsBulletShot_ = false;
	}
}

void PlayerBullet::Draw()
{

	if (playerIsBulletShot_ == true) //ƒtƒ‰ƒO‚ª—§‚Á‚Ä‚¢‚éŽž‚É’e‚ð•`‰æ‚·‚é
	{
		//Novice::DrawTriangle(playerbulletposX[i] - 5, playerbulletposY[i] - 10, playerbulletposX[i] + 5, playerbulletposY[i] - 10, playerbulletposX[i], playerbulletposY[i] - 25, 0xFFFFFFFF, kFillModeSolid); //’e
		Novice::DrawSprite(playerBulletPosX_ - 15.5f, playerBulletPosY_ - 25.0f, playerBulletPoint_, 0.5, 0.5, 0.0f, 0xFFFFFFFF);
	}
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
	playerIsBulletShot_ = true;
}