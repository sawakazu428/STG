#include "Enemy.h"


void BoxEnemy::Initialize(int x, int y)
{
	enemyPosX_ = x;
	enemyPosY_ = y;
	enemySpeedX_ = 2;
	enemySpeedY_ = 4;
	enemyRadius_ = 32;
	enemyHP_ = 1;
	enemyIsAlive_ = true;

	enemyExplosion_ = false;
	enemyRespawnCount_ = 180;

	enemyDelayFrameBullet_ = 80;
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
	if (enemyRespawnCount_ <= 150) 
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
		enemyRespawnCount_ = 180;
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

	enemyPosY_ += enemySpeedY_;
	enemyPosX_ -= enemySpeedX_;

	if (enemyPosY_ + enemyRadius_ >= 720) //�G�̔���
	{
		enemySpeedY_ *= -1;
	}
	if (enemyPosY_ <= 0)
	{
		enemySpeedY_ *= -1;
	}

}

void BoxEnemy::Draw()
{
	if (enemyIsAlive_ == true)
	{

		Novice::DrawBox(enemyPosX_-16, enemyPosY_-16,32,32, 0.0f, GREEN, kFillModeSolid);
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
	
}

void BoxEnemy::EnemyOnColision()
{
	enemyIsAlive_ = false;
}