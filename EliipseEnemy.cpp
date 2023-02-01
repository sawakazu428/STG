#include "EliipseEnemy.h"


void EllipseEnemy::Initialize(int x, int y)
{
	enemyEllipsePosX_ = x;
	enemyEllipsePosY_ = y;
	enemyEllipseSpeedX_ = 1;
	enemyEllipseSpeedY_ = 4;
	enemyEllipseRadius_ = 16;
	enemyEllipseHP_ = 1;
	enemyEllipseIsAlive_ = true;

	enemyEllipseExplosion_ = false;
	enemyEllipseRespawnCount_ = 120;

	enemyEllipseDelayFrameBullet_ = 60;
	delayFrameBulletEnemyEllipse_ = enemyEllipseDelayFrameBullet_;

	
	for (int i = 0; i < 30; i++)
	{
		enemyEllipseBullet_[i].Initialize();
	}
	for (int i = 0; i < 15; i++)
	{
		particle_[i].Initialize();
	}
}

void EllipseEnemy::Update()
{
	if (delayFrameBulletEnemyEllipse_ > 0)
	{
		delayFrameBulletEnemyEllipse_--;
	}
	if (enemyEllipseIsAlive_ == false)
	{
		enemyEllipseRespawnCount_ -= 1;
		enemyEllipseExplosion_ = true;
	}
	if (enemyEllipseExplosion_ == true)
	{

		for (int i = 0; i < 15; i++)
		{
			if (particle_[i].GetParticleCrush_() == false)
			{
				particle_[i].Setpaticle(enemyEllipsePosX_, enemyEllipsePosY_, rand() % 8 - 4, rand() % 8 - 4);
			}
		}

		for (int i = 0; i < 15; i++)
		{
			if (particle_[i].GetParticleCrush_() == true)
			{
				particle_[i].Update();
			}
		}
	}
	if (enemyEllipseRespawnCount_ <= 90)
	{
		enemyEllipseExplosion_ = false;
	}
	if (enemyEllipseExplosion_ == false)
	{
		for (int i = 0; i < 15; i++)
		{
			particle_[i].ParticleOnColision();
		}
	}
	if (enemyEllipseRespawnCount_ == 0)
	{
		enemyEllipseIsAlive_ = true;
		enemyEllipseRespawnCount_ = 120;
	}

	for (int i = 0; i < 30; i++)
	{
		enemyEllipseBullet_[i].Update();
		if (enemyEllipseBullet_[i].GetIsEnemyEllipseBulletShot() == false && delayFrameBulletEnemyEllipse_ <= 0)
		{
			delayFrameBulletEnemyEllipse_ = enemyEllipseDelayFrameBullet_;
			enemyEllipseBullet_[i].SetEnemyEllipseBulletInfo(enemyEllipsePosX_, enemyEllipsePosY_, rand() % 10 - 5 , rand() % 10 - 5, enemyEllipseRadius_);
			enemyEllipseBullet_[i].EnemyEllipseBulletOnColision();
			break;
		}

	}

	/*for (int i = 10; i < 20; i++)
	{
		enemyEllipseBullet_[i].Update();
		if (enemyEllipseBullet_[i].GetIsEnemyEllipseBulletShot1() == false && delayFrameBulletEnemyEllipse_ <= 0)
		{
			delayFrameBulletEnemyEllipse_ = enemyEllipseDelayFrameBullet_;
			enemyEllipseBullet_[i].SetEnemyEllipseBulletInfo(enemyEllipsePosX_, enemyEllipsePosY_, rand() % 10 - 5, rand() % 10 - 5, enemyEllipseRadius_);
			enemyEllipseBullet_[i].EnemyEllipseBulletOnColision1();
			break;
		}


	}
	for (int i = 20; i < 30; i++)
	{
		enemyEllipseBullet_[i].Update();
		if (enemyEllipseBullet_[i].GetIsEnemyEllipseBulletShot2() == false && delayFrameBulletEnemyEllipse_ <= 0)
		{
			delayFrameBulletEnemyEllipse_ = enemyEllipseDelayFrameBullet_;
			enemyEllipseBullet_[i].SetEnemyEllipseBulletInfo(enemyEllipsePosX_, enemyEllipsePosY_, rand() % 10 - 5, rand() % 10 - 5, enemyEllipseRadius_);
			enemyEllipseBullet_[i].EnemyEllipseBulletOnColision2();
			break;
		}

	}*/
}

void EllipseEnemy::Move()
{
	if (enemyEllipseIsAlive_ == true)
	{
		enemyEllipsePosY_ += enemyEllipseSpeedY_;
		enemyEllipsePosX_ -= enemyEllipseSpeedX_;
			if (enemyEllipsePosY_ + enemyEllipseRadius_ >= 720) //�G�̔���
		{
			enemyEllipseSpeedY_ *= -1;
		}
		if (enemyEllipsePosY_ <= 0)
		{
			enemyEllipseSpeedY_ *= -1;
		}
	}
}

void EllipseEnemy::Draw()
{
	if (enemyEllipseIsAlive_ == true)
	{

		Novice::DrawEllipse(enemyEllipsePosX_, enemyEllipsePosY_ , 16, 16, 0.0f, BLACK, kFillModeSolid);
	}
	for (int i = 0; i < 30; i++)
	{
		if (enemyEllipseBullet_[i].GetIsEnemyEllipseBulletShot() == true)
		{
			enemyEllipseBullet_[i].Draw();
		}
	}
	if (enemyEllipseExplosion_ == true)
	{
		for (int i = 0; i < 15; i++)
		{
			particle_[i].DrawEllipse();
		}

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

void EllipseEnemy::EnemyOnColision()
{
	enemyEllipseIsAlive_ = false;
}