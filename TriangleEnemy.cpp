#include "TriangleEnemy.h"


void TriangleEnemy::Initialize(int x, int y)
{
	enemyTrianglePosX_ = x;
	enemyTrianglePosY_ = y;
	enemyTriangleSpeedX_ = 2;
	enemyTriangleSpeedY_ = 4;
	enemyTriangleRadius_ = 16;
	enemyTriangleHP_ = 1;
	enemyTriangleIsAlive_ = true;

	enemyTriangleExplosion_ = false;
	enemyTriangleRespawnCount_ = 180;

	enemyTriangleDelayFrameBullet_ = 100;
	delayFrameBulletEnemyTriangle_ = enemyTriangleDelayFrameBullet_;
	for (int i = 0; i < 20; i++)
	{
		enemyTriangleBullet_[i].Initialize();
	}
	for (int i = 0; i < 15; i++)
	{
		particle_[i].Initialize();
	}
}

void TriangleEnemy::Update()
{
	if (delayFrameBulletEnemyTriangle_ > 0)
	{
		delayFrameBulletEnemyTriangle_--;
	}
	if (enemyTriangleIsAlive_ == false)
	{
		enemyTriangleRespawnCount_ -= 1;
		enemyTriangleExplosion_ = true;
	}
	if (enemyTriangleExplosion_ == true)
	{

		for (int i = 0; i < 15; i++)
		{
			if (particle_[i].GetParticleCrush_() == false)
			{
				particle_[i].Setpaticle(enemyTrianglePosX_, enemyTrianglePosY_, rand() % 8 - 4, rand() % 8 - 4);
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
	if (enemyTriangleRespawnCount_ <= 150)
	{
		enemyTriangleExplosion_ = false;
	}
	if (enemyTriangleExplosion_ == false)
	{
		for (int i = 0; i < 15; i++)
		{
			particle_[i].ParticleOnColision();
		}
	}
	if (enemyTriangleRespawnCount_ == 0)
	{
		enemyTriangleIsAlive_ = true;
		enemyTriangleRespawnCount_ = 180;
	}
	for (int i = 0; i < 20; i++)
	{
		if (enemyTriangleBullet_[i].GetIsEnemyTriangleBulletShot() == false && delayFrameBulletEnemyTriangle_ <= 0)
		{
			delayFrameBulletEnemyTriangle_ = enemyTriangleDelayFrameBullet_;
			enemyTriangleBullet_[i].SetEnemyTriangleBulletInfo(enemyTrianglePosX_, enemyTrianglePosY_, enemyTriangleSpeedX_, enemyTriangleSpeedY_, enemyTriangleRadius_);
			enemyTriangleBullet_[i].EnemyTriangleBulletOnColision();
		}

		enemyTriangleBullet_[i].Update();
	}
}

void TriangleEnemy::Move()
{

	enemyTrianglePosY_ += enemyTriangleSpeedY_;
	enemyTrianglePosX_ -= enemyTriangleSpeedX_;
	if (enemyTrianglePosY_ + enemyTriangleRadius_ >= 720) //�G�̔���
	{
		enemyTriangleSpeedY_ *= -1;
	}
	if (enemyTrianglePosY_ <= 0)
	{
		enemyTriangleSpeedY_ *= -1;
	}

}

void TriangleEnemy::Draw()
{
	if (enemyTriangleIsAlive_ == true)
	{

		Novice::DrawTriangle(enemyTrianglePosX_ + 16, enemyTrianglePosY_ - 16, enemyTrianglePosX_ - 16, enemyTrianglePosY_, enemyTrianglePosX_ + 16, enemyTrianglePosY_ + 16, GREEN, kFillModeSolid);
	}
	for (int i = 0; i < 20; i++)
	{
		if (enemyTriangleBullet_[i].GetIsEnemyTriangleBulletShot() == true)
		{
			enemyTriangleBullet_[i].Draw();
		}
	}
	if (enemyTriangleExplosion_ == true)
	{
		for (int i = 0; i < 15; i++)
		{
			particle_[i].DrawEllipse();
		}

	}
	

}

void TriangleEnemy::EnemyOnColision()
{
	enemyTriangleIsAlive_ = false;
}
