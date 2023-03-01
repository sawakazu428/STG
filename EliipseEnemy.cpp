#include "EliipseEnemy.h"


void EllipseEnemy::Initialize(int x, int y)
{
	enemyEllipsePosX_ = x;
	enemyEllipsePosY_ = y;
	enemyEllipseSpeedX_ = 2;
	enemyEllipseSpeedY_ = 4;
	enemyEllipseRadius_ = 16;
	enemyEllipseHP_ = 1;
	enemyEllipseIsAlive_ = true;

	enemyEllipseExplosion_ = false;
	enemyEllipseRespawnCount_ = 180;

	enemyEllipseDelayFrameBullet_ = 40;
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
	if (enemyEllipseRespawnCount_ <= 150)
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
		enemyEllipseRespawnCount_ = 180;
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

	
}

void EllipseEnemy::Move()
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

void EllipseEnemy::Draw()
{
	if (enemyEllipseIsAlive_ == true)
	{

		Novice::DrawEllipse(enemyEllipsePosX_, enemyEllipsePosY_ , 16, 16, 0.0f, GREEN,kFillModeSolid);
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

}

void EllipseEnemy::EnemyOnColision()
{
	enemyEllipseIsAlive_ = false;
}