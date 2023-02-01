#include "TriangleEnemy.h"


void TriangleEnemy::Initialize(int x, int y)
{
	enemyTrianglePosX_ = x;
	enemyTrianglePosY_ = y;
	enemyTriangleSpeedX_ = 1;
	enemyTriangleSpeedY_ = 4;
	enemyTriangleRadius_ = 16;
	enemyTriangleHP_ = 1;
	enemyTriangleIsAlive_ = true;

	enemyTriangleExplosion_ = false;
	enemyTriangleRespawnCount_ = 120;

	enemyTriangleDelayFrameBullet_ = 60;
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
	if (enemyTriangleRespawnCount_ <= 90)
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
		enemyTriangleRespawnCount_ = 120;
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
	if (enemyTriangleIsAlive_ == true)
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
}

void TriangleEnemy::Draw()
{
	if (enemyTriangleIsAlive_ == true)
	{

		Novice::DrawTriangle(enemyTrianglePosX_ + 16, enemyTrianglePosY_ - 16, enemyTrianglePosX_ - 16, enemyTrianglePosY_, enemyTrianglePosX_ + 16, enemyTrianglePosY_ + 16, WHITE, kFillModeSolid);
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

void TriangleEnemy::EnemyOnColision()
{
	enemyTriangleIsAlive_ = false;
}
