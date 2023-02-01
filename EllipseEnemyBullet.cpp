#include "EllipseEnemyBullet.h"

void EllipseEnemyBullet::Initialize()
{
	enemyEllipseBulletPosX_ = 100;
	enemyEllipseBulletPosY_ = 100;
	enemyEllipseBulletRadius_ = 8;
	enemyEllipseBulletSpeedX_ = 4;
	enemyEllipseBulletSpeedY_ = 4;
	isEnemyEllipseBulletShot_ = false;
	isEnemyEllipseBulletShot1_ = false;
	isEnemyEllipseBulletShot2_ = false;
	drawEnemyEllipseBullet_ = Novice::LoadTexture("./Resources/enemyBullet.png");

}

void EllipseEnemyBullet::Update()
{

	if (isEnemyEllipseBulletShot_ == true)
	{
		enemyEllipseBulletPosX_ += enemyEllipseBulletSpeedX_;
		enemyEllipseBulletPosY_ += enemyEllipseBulletSpeedY_;
	}
	if (enemyEllipseBulletPosX_ + enemyEllipseBulletRadius_ <= 0)
	{
		isEnemyEllipseBulletShot_ = false;
	}
	if (enemyEllipseBulletPosY_ - enemyEllipseBulletRadius_ > 720)
	{
		isEnemyEllipseBulletShot_ = false;
	}
	if (enemyEllipseBulletPosY_ + enemyEllipseBulletRadius_ < 0)
	{
		isEnemyEllipseBulletShot_ = false;
	}
	if (enemyEllipseBulletPosX_ - enemyEllipseBulletRadius_ > 1280) 
	{
		isEnemyEllipseBulletShot_ = false;
	}
	//------------------------------------------
	if (isEnemyEllipseBulletShot1_ == true)
	{
		enemyEllipseBulletPosX_ += enemyEllipseBulletSpeedX_;
		enemyEllipseBulletPosY_ += enemyEllipseBulletSpeedY_;
	}
	if (enemyEllipseBulletPosX_ + enemyEllipseBulletRadius_ <= 0)
	{
		isEnemyEllipseBulletShot1_ = false;
	}
	if (enemyEllipseBulletPosY_ - enemyEllipseBulletRadius_ > 720)
	{
		isEnemyEllipseBulletShot1_ = false;
	}
	if (enemyEllipseBulletPosY_ + enemyEllipseBulletRadius_ < 0)
	{
		isEnemyEllipseBulletShot1_ = false;
	}
	if (enemyEllipseBulletPosX_ - enemyEllipseBulletRadius_ > 1280)
	{
		isEnemyEllipseBulletShot1_ = false;
	}
	//--------------------------------------------
	if (isEnemyEllipseBulletShot2_ == true)
	{
		enemyEllipseBulletPosX_ += enemyEllipseBulletSpeedX_;
		enemyEllipseBulletPosY_ += enemyEllipseBulletSpeedY_;
	}
	if (enemyEllipseBulletPosX_ + enemyEllipseBulletRadius_ <= 0)
	{
		isEnemyEllipseBulletShot2_ = false;
	}
	if (enemyEllipseBulletPosY_ - enemyEllipseBulletRadius_ > 720)
	{
		isEnemyEllipseBulletShot2_ = false;
	}
	if (enemyEllipseBulletPosY_ + enemyEllipseBulletRadius_ < 0)
	{
		isEnemyEllipseBulletShot2_ = false;
	}
	if (enemyEllipseBulletPosX_ - enemyEllipseBulletRadius_ > 1280)
	{
		isEnemyEllipseBulletShot2_ = false;
	}
}

void EllipseEnemyBullet::Draw()
{
	if (isEnemyEllipseBulletShot_ == true)
	{
		//Novice::DrawBox(enemyBulletPosX_ - 32.0f, enemyBulletPosY_ - 32.0f, 32,32, 0.0f, RED, kFillModeSolid);
		Novice::DrawEllipse(enemyEllipseBulletPosX_, enemyEllipseBulletPosY_, enemyEllipseBulletRadius_, enemyEllipseBulletRadius_, 0.0f, WHITE, kFillModeSolid);
		//Novice::DrawSprite(enemyEllipseBulletPosX_ - 16.0f, enemyEllipseBulletPosY_ - 16.0f, drawEnemyEllipseBullet_, 0.7, 0.7, 0.0f, WHITE);
		//Novice::DrawTriangle(bulletenemy[j].bulletposX - 10, bulletenemy[j].bulletposY + 10, bulletenemy[j].bulletposX + 10, bulletenemy[j].bulletposY + 10, bulletenemy[j].bulletposX, bulletenemy[j].bulletposY + 25, 0xFFFFFFFF, kFillModeSolid); //�e
	}
}

void EllipseEnemyBullet::SetEnemyEllipseBulletInfo(int posX, int posY, int speedX, int speedY, int radius)
{
	enemyEllipseBulletPosX_ = posX;
	enemyEllipseBulletPosY_ = posY;
	enemyEllipseBulletSpeedX_ = speedX;
	enemyEllipseBulletSpeedY_ = speedY;
	enemyEllipseBulletRadius_ = radius;
}

void EllipseEnemyBullet::EnemyEllipseBulletOnColision()
{
	isEnemyEllipseBulletShot_ = true;
}

void EllipseEnemyBullet::EnemyEllipseBulletOnColision1()
{
	isEnemyEllipseBulletShot1_ = true;
}

void EllipseEnemyBullet::EnemyEllipseBulletOnColision2()
{
	isEnemyEllipseBulletShot2_ = true;
}

void EllipseEnemyBullet::EnemyEllipseReceiveBulletOnColision()
{
	isEnemyEllipseBulletShot_ = false;
}
