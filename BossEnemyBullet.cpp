#include "BossEnemyBullet.h"

void BossEnemyBullet::Initialize()
{
	enemyBossBulletPosX_ = 100;
	enemyBossBulletPosY_ = 100;
	enemyBossBulletPosX1_ = 100;
	enemyBossBulletPosY1_ = 100;
	enemyBossBulletPosX2_ = 100;
	enemyBossBulletPosY2_ = 100;
	enemyBossBulletRadius_ = 32;
	enemyBossBulletSpeedX_ = 4;
	enemyBossBulletSpeedY_ = 4;


	enemyBossAcceleration_ = -0.4f;
	enemyBossRandX_ = 0;
	enemyBossRandY_ = 0;
	enemyBossRandX1_ = 0;
	enemyBossRandY1_ = 0;

	isEnemyBossBulletShot_ = false;
	isEnemyBossBulletShot1_ = false;
	isEnemyBossBulletShot2_ = false;
	drawEnemyBossBullet_ = Novice::LoadTexture("./Resources/enemyBullet.png");

}

void BossEnemyBullet::Update()
{

	if (isEnemyBossBulletShot_ == true)
	{
		enemyBossBulletPosX_ += enemyBossBulletSpeedX_;
		enemyBossBulletPosY_ += enemyBossBulletSpeedY_;
	}
	if (enemyBossBulletPosX_ + enemyBossBulletRadius_ <= 0)
	{
		isEnemyBossBulletShot_ = false;
	}
	if (enemyBossBulletPosY_ - enemyBossBulletRadius_ > 720)
	{
		isEnemyBossBulletShot_ = false;
	}
	if (enemyBossBulletPosY_ + enemyBossBulletRadius_ < 0)
	{
		isEnemyBossBulletShot_ = false;
	}
	if (enemyBossBulletPosX_ - enemyBossBulletRadius_ > 1280)
	{
		isEnemyBossBulletShot_ = false;
	}
}

void BossEnemyBullet::Update1()
{
	if (isEnemyBossBulletShot1_ == true)
	{
		enemyBossRandX_ += enemyBossAcceleration_;

		enemyBossBulletPosX1_ += enemyBossRandX_;
		enemyBossBulletPosY1_ += enemyBossRandY_;
	}
	if (enemyBossBulletPosX1_ + 16 <= 0)
	{
		isEnemyBossBulletShot1_ = false;
	}
	if (enemyBossBulletPosY1_ - 16 > 720)
	{
		isEnemyBossBulletShot1_ = false;
	}
	if (enemyBossBulletPosY1_ + 16 < 0)
	{
		isEnemyBossBulletShot1_ = false;
	}
	if (enemyBossBulletPosX1_ - 16 > 1280)
	{
		isEnemyBossBulletShot1_ = false;
	}
}

void BossEnemyBullet::Update2()
{
	if (isEnemyBossBulletShot2_ == true)
	{
		enemyBossRandX1_ += enemyBossAcceleration_;

		enemyBossBulletPosX2_ += enemyBossRandX1_;
		enemyBossBulletPosY2_ += enemyBossRandY1_;
	}
	if (enemyBossBulletPosX2_ + 16 <= 0)
	{
		isEnemyBossBulletShot2_ = false;
	}
	if (enemyBossBulletPosY2_ - 16 > 720)
	{
		isEnemyBossBulletShot2_ = false;
	}
	if (enemyBossBulletPosY2_ + 16 < 0)
	{
		isEnemyBossBulletShot2_ = false;
	}
	if (enemyBossBulletPosX2_ - 16 > 1280)
	{
		isEnemyBossBulletShot2_ = false;
	}
}

void BossEnemyBullet::Draw()
{
	if (isEnemyBossBulletShot_ == true)
	{
		Novice::DrawEllipse(enemyBossBulletPosX_, enemyBossBulletPosY_, enemyBossBulletRadius_, enemyBossBulletRadius_, 0.0f, WHITE, kFillModeSolid);
	}
	if (isEnemyBossBulletShot1_ == true)
	{
		Novice::DrawEllipse(enemyBossBulletPosX1_, enemyBossBulletPosY1_, 16, 16, 0.0f, WHITE, kFillModeSolid);
	}
	if (isEnemyBossBulletShot2_ == true)
	{
		Novice::DrawEllipse(enemyBossBulletPosX2_, enemyBossBulletPosY2_, 16, 16, 0.0f, WHITE, kFillModeSolid);
	}
}

void BossEnemyBullet::SetEnemyBossBulletInfo(int posX, int posY, int speedX, int speedY, int radius)
{
	enemyBossBulletPosX_ = posX;
	enemyBossBulletPosY_ = posY;
	enemyBossBulletSpeedX_ = speedX;
	enemyBossBulletSpeedY_ = speedY;
	enemyBossBulletRadius_ = radius;	
}

void BossEnemyBullet::SetEnemyBossBulletInfo1(int posX, int posY, int speedX, int speedY, int radius)
{
	enemyBossBulletPosX1_ = posX;
	enemyBossBulletPosY1_ = posY;
	enemyBossRandX_ = speedX;
	enemyBossRandY_ = speedY;
	enemyBossBulletRadius_ = radius;
}

void BossEnemyBullet::SetEnemyBossBulletInfo2(int posX, int posY, int speedX, int speedY, int radius)
{
	enemyBossBulletPosX2_ = posX;
	enemyBossBulletPosY2_ = posY;
	enemyBossRandX1_ = speedX;
	enemyBossRandY1_ = speedY;
	enemyBossBulletRadius_ = radius;
}

void BossEnemyBullet::EnemyBossBulletOnColision()
{
	isEnemyBossBulletShot_ = true;
}

void BossEnemyBullet::EnemyBossBulletOnColision1()
{
	isEnemyBossBulletShot1_ = true;
}

void BossEnemyBullet::EnemyBossBulletOnColision2()
{
	isEnemyBossBulletShot2_ = true;
}

void BossEnemyBullet::EnemyBossReceiveBulletOnColision()
{
	isEnemyBossBulletShot_ = false;
}

void BossEnemyBullet::EnemyBossReceiveBulletOnColision1()
{
	isEnemyBossBulletShot1_ = false;
}

void BossEnemyBullet::EnemyBossReceiveBulletOnColision2()
{
	isEnemyBossBulletShot2_ = false;
}
