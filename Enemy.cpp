#include "Enemy.h"


void BoxEnemy::Initialize(int x, int y)
{
	enemyPosX_ = x;
	enemyPosY_ = y;
	enemySpeedX_ = 1;
	enemySpeedY_ = 4;
	enemyRadius_ = 32;
	enemyHP_ = 1;
	enemyIsAlive_ = true;

	enemyExplosion_ = false;
	enemyRespawnCount_ = 120;

	enemyDelayFrameBullet_ = 60;
	delayFrameBulletEnemy_ = enemyDelayFrameBullet_;
	for (int i = 0; i < 20; i++)
	{
		enemyBullet_[i].Initialize();
	}
	for (int i = 0; i < 15; i++)
	{
		particle_[i].Initialize();
	}
	
}

void BoxEnemy::Update()
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
	if (enemyExplosion_ == true)
	{
		
		for (int i = 0; i < 15; i++)
		{
			if (particle_[i].GetParticleCrush_() == false)
			{
				particle_[i].Setpaticle(enemyPosX_, enemyPosY_, rand() % 8 - 4, rand() % 8 - 4);
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
	if (enemyRespawnCount_ <= 90) 
	{
		enemyExplosion_ = false;
	}
	if (enemyExplosion_ == false)
	{
		for (int i = 0; i < 15; i++)
		{
			particle_[i].ParticleOnColision();
		}	
	}
	if (enemyRespawnCount_ == 0) 
	{
		enemyIsAlive_ = true;
		enemyRespawnCount_ = 120;
	}
	for (int i = 0; i < 20; i++)
	{
		if (enemyBullet_[i].GetIsEnemyBulletShot() == false  && delayFrameBulletEnemy_ <= 0)
		{
			delayFrameBulletEnemy_ = enemyDelayFrameBullet_;
			enemyBullet_[i].SetEnemyBulletInfo(enemyPosX_, enemyPosY_, enemySpeedX_, enemySpeedY_, enemyRadius_);
			enemyBullet_[i].EnemyBulletOnColision();
		}
		enemyBullet_[i].Update();
	}
}

void BoxEnemy::Move()
{
	if (enemyIsAlive_ == true)
	{
		enemyPosY_ += enemySpeedY_;
		enemyPosX_ -= enemySpeedX_;

		if (enemyPosY_ + enemyRadius_ >= 720) //�G�̔���
		{
			enemySpeedY_ *= -1;
		}
		if (enemyPosY_  <= 0)
		{
			enemySpeedY_ *= -1;
		}
	}
}

void BoxEnemy::Draw()
{
	if (enemyIsAlive_ == true)
	{

		Novice::DrawBox(enemyPosX_-16, enemyPosY_-16,32,32, 0.0f, BLACK, kFillModeSolid);
	}
	for (int i = 0; i < 20; i++)
	{
		if (enemyBullet_[i].GetIsEnemyBulletShot() == true)
		{
			enemyBullet_[i].Draw();
		}
	}
	if (enemyExplosion_ == true)
	{
		for (int i = 0; i < 15; i++)
		{
			particle_[i].DrawBox();
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

void BoxEnemy::EnemyOnColision()
{
	enemyIsAlive_ = false;
}