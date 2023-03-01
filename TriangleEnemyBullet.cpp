#include "TriangleEnemyBullet.h"

float EaseInSine(float x)
{
	return 1 - cosf((x * M_PI) / 2);
}

void TriangleEnemyBullet::Initialize()
{
	enemyTriangleBulletPosX_ = 100;
	enemyTriangleBulletPosY_ = 100;
	enemyTriangleBulletRadius_ = 16;
	enemyTriangleBulletSpeedX_ = 4;
	enemyTriangleBulletSpeedY_ = 4;
	isEnemyTriangleBulletShot_ = false;
	drawEnemyTriangleBullet_ = Novice::LoadTexture("./Resources/enemyBullet.png");
	nowFrame_ = 0;
	endFrame_ = -300;
	kMaxFrame_ = -300;
	moveInFrame_ = 0;
}

void TriangleEnemyBullet::Update()
{

	if (isEnemyTriangleBulletShot_ == true)
	{
		nowFrame_ -= 1.0f;
		if (nowFrame_ <= kMaxFrame_)
		{
			nowFrame_ = kMaxFrame_;
			nowFrame_ = 0;
		}
		moveInFrame_ = nowFrame_ / kMaxFrame_;
		enemyTriangleBulletPosX_ = EaseInSine(moveInFrame_) * -300 + enemyTriangleBulletPosX_;
	}
	if (enemyTriangleBulletPosX_ + enemyTriangleBulletRadius_ <= 0)
	{
		nowFrame_ = 0;
		moveInFrame_ = 0;

		isEnemyTriangleBulletShot_ = false;

	}
	if (enemyTriangleBulletPosX_ + enemyTriangleBulletRadius_ <= 0)
	{
		isEnemyTriangleBulletShot_ = false;
	}
	if (enemyTriangleBulletPosY_ - enemyTriangleBulletRadius_ > 720)
	{
		isEnemyTriangleBulletShot_ = false;
	}
	if (enemyTriangleBulletPosY_ + enemyTriangleBulletRadius_ < 0)
	{
		isEnemyTriangleBulletShot_ = false;
	}
	if (enemyTriangleBulletPosX_ - enemyTriangleBulletRadius_ > 1280)
	{
		isEnemyTriangleBulletShot_ = false;
	}

}

void TriangleEnemyBullet::Draw()
{
	if (isEnemyTriangleBulletShot_ == true)
	{
		//Novice::DrawBox(enemyBulletPosX_ - 32.0f, enemyBulletPosY_ - 32.0f, 32,32, 0.0f, RED, kFillModeSolid);

		Novice::DrawSprite(enemyTriangleBulletPosX_ - 16.0f, enemyTriangleBulletPosY_ - 16.0f, drawEnemyTriangleBullet_, 0.7, 0.7, 0.0f, WHITE);
		//Novice::DrawTriangle(bulletenemy[j].bulletposX - 10, bulletenemy[j].bulletposY + 10, bulletenemy[j].bulletposX + 10, bulletenemy[j].bulletposY + 10, bulletenemy[j].bulletposX, bulletenemy[j].bulletposY + 25, 0xFFFFFFFF, kFillModeSolid); //�e
	}
}

void TriangleEnemyBullet::SetEnemyTriangleBulletInfo(int posX, int posY, int speedX, int speedY, int radius)
{
	enemyTriangleBulletPosX_ = posX;
	enemyTriangleBulletPosY_ = posY;
	enemyTriangleBulletRadius_ = radius;
}

void TriangleEnemyBullet::EnemyTriangleBulletOnColision()
{
	isEnemyTriangleBulletShot_ = true;
}

void TriangleEnemyBullet::EnemyTriangleReceiveBulletOnColision()
{
	isEnemyTriangleBulletShot_ = false;
}
