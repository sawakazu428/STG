#include "EnemyBullet.h"
void BoxEnemyBullet::Initialize()
{
	enemyBulletPosX_ = 100;
	enemyBulletPosY_ = 100;
	enemyBulletRadius_ = 16;
	enemyBulletSpeedX_ = 6;
	enemyBulletSpeedY_ = 6;
	isEnemyBulletShot_ = false;
	drawEnemyBullet_ = Novice::LoadTexture("./Resources/enemyBullet.png");
}

void BoxEnemyBullet::Update()
{

	if (isEnemyBulletShot_ == true)
	{
		enemyBulletPosX_ -= enemyBulletSpeedX_;
	}
	if (enemyBulletPosX_ + enemyBulletRadius_ <= 0)
	{
		isEnemyBulletShot_ = false;

	}
}

void BoxEnemyBullet::Draw()
{
	if (isEnemyBulletShot_ == true)
	{
		//Novice::DrawBox(enemyBulletPosX_ - 32.0f, enemyBulletPosY_ - 32.0f, 32,32, 0.0f, RED, kFillModeSolid);

	    Novice::DrawSprite(enemyBulletPosX_ - 16.0f, enemyBulletPosY_ - 16.0f, drawEnemyBullet_, 0.7, 0.7, 0.0f, WHITE);
		//Novice::DrawTriangle(bulletenemy[j].bulletposX - 10, bulletenemy[j].bulletposY + 10, bulletenemy[j].bulletposX + 10, bulletenemy[j].bulletposY + 10, bulletenemy[j].bulletposX, bulletenemy[j].bulletposY + 25, 0xFFFFFFFF, kFillModeSolid); //�e
	}
}

void BoxEnemyBullet::SetEnemyBulletInfo(int posX, int posY, int speedX, int speedY, int radius)
{
	enemyBulletPosX_ = posX;
	enemyBulletPosY_ = posY;
	enemyBulletRadius_ = radius;
}

void BoxEnemyBullet::EnemyBulletOnColision()
{
	isEnemyBulletShot_ = true;
}

void BoxEnemyBullet::EnemyReceiveBulletOnColision()
{
	isEnemyBulletShot_ = false;
}

