#include "PlayerBullet.h"

void PlayerBullet::Initialize()
{
	playerBulletPosX_ = 100;
	playerBulletPosY_ = 100;
	playerRightBulletPosX_ = 120;
	playerBottomBulletPosY_ = 120;
	playerBulletSpeedX_ = 6;
	playerBulletSpeedY_ = 6;
	playerBulletRadius_ = 20;
	playerBulletNum_ = 20;
	playerIsBulletShot_ = false;
	isPlayerDiffusionShot_[5] = false;
	playerBulletPoint_ = Novice::LoadTexture("./Resources/bullet.png");
}

void PlayerBullet::NormalUpdate()
{
	
	if (playerIsBulletShot_ == true)
	{
		playerBulletPosX_ += playerBulletSpeedX_;
	}

	if (playerBulletPosX_ - playerBulletRadius_ > 1280)
	{
		playerIsBulletShot_ = false;
	}
}

void PlayerBullet::DiffusionUpdate()
{

	if (playerIsBulletShot_ == true)
	{
		playerBulletPosX_ += playerBulletSpeedX_;
		playerBulletPosY_ += playerBulletSpeedY_;
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

	if (playerIsBulletShot_ == true)
	{
		playerBulletPosX_ += playerBulletSpeedX_;
	}

	if (playerBulletPosX_ - playerBulletRadius_ < 0)
	{
		playerIsBulletShot_ = false;
	}
}

void PlayerBullet::Draw()
{
	if (playerIsBulletShot_ == true) //フラグが立っている時に弾を描画する
	{
		//Novice::DrawTriangle(playerbulletposX[i] - 5, playerbulletposY[i] - 10, playerbulletposX[i] + 5, playerbulletposY[i] - 10, playerbulletposX[i], playerbulletposY[i] - 25, 0xFFFFFFFF, kFillModeSolid); //弾
		Novice::DrawSprite(playerBulletPosX_ - 15.5f, playerBulletPosY_ - 25.0f, playerBulletPoint_, 0.5, 0.5, 0.0f, 0xFFFFFFFF);
	}
}

void PlayerBullet::SetPlayerBulletInfo(int posX, int posY, int speedX, int speedY)
{
	playerBulletPosX_ = posX;
	playerBulletPosY_ = posY;
	playerBulletSpeedX_ = speedX;
	playerBulletSpeedY_ = speedY;
}

void PlayerBullet::BulletOnColision()
{
	playerIsBulletShot_ = true;
}

void PlayerBullet::BulletDiffusionOnColision()
{
}

void PlayerBullet::BulletReceiveOnColision()
{
	playerIsBulletShot_ = false;
}
