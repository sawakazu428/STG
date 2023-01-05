#include "Enemy.h"

void Enemy::Initialize()
{
	enemyPosX_ = 100;
	enemyPosY_ = 100;
	enemySpeedX_ = 4;
	enemySpeedY_ = 4;
	enemyRadius_ = 30;
	enemyHP_ = 1;
	enemyIsAlive_ = true;

	enemyExplosion_ = false;
	enemyRespawnCount_ = 120;

	enemyDelayFrameBullet_ = 10;
	delayFrameBulletEnemy_ = enemyDelayFrameBullet_;
}

void Enemy::Update()
{
	if (delayFrameBulletEnemy_ > 0)
	{
		delayFrameBulletEnemy_--;
	}
	if (enemyIsAlive_ == false)
	{
		enemyRespawnCount_ -= 1;
		enemyExplosion_ = true;
	}
	if (enemyRespawnCount_ <= 90) 
	{
		enemyExplosion_ = false;
	}
	if (enemyRespawnCount_ == 0) 
	{
		enemyIsAlive_ = true;
		enemyRespawnCount_ = 120;
	}

	if (enemyBullet_.GetIsEnemyBulletShot() == false && enemyIsAlive_ == true && delayFrameBulletEnemy_ <= 0) 
	{
		delayFrameBulletEnemy_ = enemyDelayFrameBullet_;
		enemyBullet_.SetEnemyBulletInfo(enemyPosX_, enemyPosY_, enemySpeedX_, enemySpeedY_, enemyRadius_);
	}
}

void Enemy::Move()
{
	if (enemyIsAlive_ == true)
	{
		enemyPosY_ += enemySpeedY_;
		if (enemyPosY_ + enemyRadius_ >= 720) //�G�̔���
		{
			enemySpeedY_ *= -1;
		}
		if (enemyPosY_ - enemyRadius_ <= 0)
		{
			enemySpeedY_ *= -1;
		}
	}
}

void Enemy::Draw()
{
	if (enemyIsAlive_ == true)
	{
		Novice::DrawBox(enemyPosX_ - 32.0f, enemyPosY_ - 32.0f,32,32, 0.0f, BLACK, kFillModeSolid);
	}
	
	/*if (enemyIsAlive_ == true)
	{
		Novice::DrawSprite(enemyPosX_ - 32.0f, enemyPosY_ - 32.0f, enemyPoint_, 1, 1, 0.0f, 0xFFFFFFFF);
	}
	if (enemyExplosion_ == true && enemyRespawnCount_ != 120)
	{
		if (enemyRespawnCount_ < 120 && enemyRespawnCount_ >= 117)
		{
			Novice::DrawSprite(enemyPosX_ - 32.0f, enemyPosX_ - 32.0f, drawExplosion1_[0], 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (enemyRespawnCount_ <= 117 && enemyRespawnCount_ >= 113)
		{
			Novice::DrawSprite(enemyPosX_ - 32.0f, enemyPosX_ - 32.0f, drawExplosion1_[1], 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (enemyRespawnCount_ <= 113 && enemyRespawnCount_ >= 107)
		{
			Novice::DrawSprite(enemyPosX_ - 32.0f, enemyPosX_ - 32.0f, drawExplosion1_[2], 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (enemyRespawnCount_ <= 107 && enemyRespawnCount_ >= 103)
		{
			Novice::DrawSprite(enemyPosX_ - 32.0f, enemyPosX_ - 32.0f, drawExplosion1_[3], 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (enemyRespawnCount_ <= 103 && enemyRespawnCount_ >= 97)
		{
			Novice::DrawSprite(enemyPosX_ - 32.0f, enemyPosX_ - 32.0f, drawExplosion1_[4], 1, 1, 0.0f, 0xFFFFFFFF);
		}
		if (enemyRespawnCount_ <= 97)
		{
			Novice::DrawSprite(enemyPosX_ - 32.0f, enemyPosX_ - 32.0f, drawExplosion1_[5], 1, 1, 0.0f, 0xFFFFFFFF);
		}
	}*/

}

void Enemy::EnemyOnColision()
{
	enemyIsAlive_ = false;
}