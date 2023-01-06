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
	randX_ = rand() % 12 - 6;
	randY_ = rand() % 12 - 6;
	playerBulletRandSpeedX_ = randX_;
	playerBulletRandSpeedY_ = randY_;
}

void PlayerBullet::NormalUpdate()
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

void PlayerBullet::DiffusionUpdate()
{

	playerIsBulletShot_ = false;


	if (playerIsBulletShot_ == true)
	{
		playerBulletPosX_ -= playerBulletRandSpeedX_;
		playerBulletPosY_ -= playerBulletRandSpeedY_;
	}

	if (playerBulletPosX_ - playerBulletRadius_ < 0)
	{
		playerIsBulletShot_ = false;
	}
	if (playerBulletPosX_ + playerBulletRadius_ > 1280)
	{
		playerIsBulletShot_ = false;
	}
	if (playerBulletPosY_ - playerBulletRadius_ < 0)
	{
		playerIsBulletShot_ = false;
	}
	if (playerBulletPosY_ + playerBulletRadius_ > 720)
	{
		playerIsBulletShot_ = false;
	}

}

void PlayerBullet::LinearUpdate()
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
	playerBulletPosX_ = posX;
	playerBulletPosY_ = posY;
	playerBulletSpeedX_ = speedX;
	playerBulletSpeedY_ = speedY;
	playerBulletRadius_ = radius;
}

void PlayerBullet::BulletOnColision()
{
	playerIsBulletShot_ = true;
}