#include "EnemyBullet.h"
void EnemyBullet::Initialize()
{
	enemyBulletPosX_ = 100;
	enemyBulletPosY_ = 100;
	enemyBulletRadius_ = 30;
	enemyBulletSpeedX_ = 4;
	enemyBulletSpeedY_ = 4;
	//drawEnemyBullet_ = Novice::LoadTexture("./Resources/enemyBullet.png");
}

void EnemyBullet::Update()
{
	isEnemyBulletShot_ = true;

	if (isEnemyBulletShot_ == true)
	{
		enemyBulletPosY_ -= enemyBulletSpeedY_;
	}
	if (enemyBulletPosY_ + enemyBulletRadius_ >= 720)
	{
		isEnemyBulletShot_ = false;

	}
}

void EnemyBullet::Draw()
{
	if (isEnemyBulletShot_ == true)
	{
		Novice::DrawBox(enemyBulletPosX_ - 32.0f, enemyBulletPosY_ - 32.0f, 32,32, 0.0f, RED, kFillModeSolid);

		//Novice::DrawSprite(enemyBulletPosX_ - 32.0f, enemyBulletPosY_ - 32.0f, drawEnemyBullet_, 1, 1, 0.0f, 0xFFFFFFFF);
		//Novice::DrawTriangle(bulletenemy[j].bulletposX - 10, bulletenemy[j].bulletposY + 10, bulletenemy[j].bulletposX + 10, bulletenemy[j].bulletposY + 10, bulletenemy[j].bulletposX, bulletenemy[j].bulletposY + 25, 0xFFFFFFFF, kFillModeSolid); //�e
	}
}

void EnemyBullet::SetEnemyBulletInfo(int posX, int posY, int speedX, int speedY, int radius)
{
	posX = enemyBulletPosX_;
	posY = enemyBulletPosY_;
	speedX = enemyBulletSpeedX_;
	speedY = enemyBulletSpeedY_;
	radius = enemyBulletRadius_;
}

void EnemyBullet::EnemyBulletOnColision()
{
	isEnemyBulletShot_ = false;
}

