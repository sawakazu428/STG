#include "BossEnemy.h"
void BossEnemy::Initialize(int x, int y, int x1, int y1, int x2, int y2)
{
	enemyBossPosX_ = x;
	enemyBossPosY_ = y;
	enemyBossPosX1_ = x1;
	enemyBossPosY1_ = y1 + 150;
	enemyBossPosX2_ = x2;
	enemyBossPosY2_ = y2 - 150;

	enemyBossMove_ = true;
	enemyBossMoveTime_ = 180;
	enemyBossSpeedX_ = 2;
	enemyBossSpeedY_ = 0;
	enemyBossRadius_ = 128;
	enemyBossHP_ = 50;
	enemyBossIsAlive_ = true;
	enemyReceiveDamage_ = false;

	enemyBossExplosion_ = false;
	enemyBossRespawnCount_ = 120;

	enemyBossDelayFrameBullet_ = 40;
	enemySideBossDelayFrameBullet_ = 60;
	enemySideBossDelayFrameBullet1_ = 60;
	delayFrameBulletEnemyBoss_ = enemyBossDelayFrameBullet_;
	delayFrameBulletEnemySideBoss_ = enemySideBossDelayFrameBullet_;
	delayFrameBulletEnemySideBoss1_ = enemySideBossDelayFrameBullet1_;
	drawBossExplosion1_[0] = Novice::LoadTexture("./Resources/Explosion1.png");
	drawBossExplosion1_[1] = Novice::LoadTexture("./Resources/Explosion2.png");
	drawBossExplosion1_[2] = Novice::LoadTexture("./Resources/Explosion3.png");
	drawBossExplosion1_[3] = Novice::LoadTexture("./Resources/Explosion4.png");
	drawBossExplosion1_[4] = Novice::LoadTexture("./Resources/Explosion5.png");
	drawBossExplosion1_[5] = Novice::LoadTexture("./Resources/Explosion6.png");
	enemyBossPoint_ = Novice::LoadTexture("./Resources/Enemyship.png");

	for (int i = 0; i < 30; i++)
	{
		enemyBossBullet_[i].Initialize();
	}
	for (int i = 0; i < 15; i++)
	{
		particle_[i].Initialize();
	}
}

void BossEnemy::Update()
{
	if (enemyBossMove_ == false)
	{
		if (delayFrameBulletEnemyBoss_ > 0)
		{
			delayFrameBulletEnemyBoss_--;
		}
		if (delayFrameBulletEnemySideBoss_ > 0)
		{
			delayFrameBulletEnemySideBoss_--;
		}
		if (delayFrameBulletEnemySideBoss1_ > 0)
		{
			delayFrameBulletEnemySideBoss1_--;
		}
		if (enemyBossIsAlive_ == false)
		{
			enemyBossRespawnCount_ -= 1;
			enemyBossExplosion_ = true;
		}
		/*if (enemyBossExplosion_ == true)
		{

			for (int i = 0; i < 15; i++)
			{
				if (particle_[i].GetParticleCrush_() == false)
				{
					particle_[i].Setpaticle(enemyBossPosX_, enemyBossPosY_, rand() % 8 - 4, rand() % 8 - 4);
				}
			}

			for (int i = 0; i < 15; i++)
			{
				if (particle_[i].GetParticleCrush_() == true)
				{
					particle_[i].Update();
				}
			}
		}*/
		if (enemyBossRespawnCount_ <= 90)
		{
			enemyBossExplosion_ = false;
		}
		/*if (enemyBossExplosion_ == false)
		{
			for (int i = 0; i < 15; i++)
			{
				particle_[i].ParticleOnColision();
			}
		}*/
		/*if (enemyBossRespawnCount_ == 0)
		{
			enemyBossIsAlive_ = true;
			enemyBossRespawnCount_ = 180;
		}*/

		for (int i = 0; i < 30; i++)
		{
			enemyBossBullet_[i].Update();
			if (enemyBossBullet_[i].GetIsEnemyBossBulletShot() == false && delayFrameBulletEnemyBoss_ <= 0)
			{
				delayFrameBulletEnemyBoss_ = enemyBossDelayFrameBullet_;
				enemyBossBullet_[i].SetEnemyBossBulletInfo(enemyBossPosX_, enemyBossPosY_, rand() % 10 - 5, rand() % 10 - 5, 32);
				enemyBossBullet_[i].EnemyBossBulletOnColision();
				break;
			}
		}

		for (int i = 0; i < 20; i++)
		{
			enemyBossBullet_[i].Update1();
			if (enemyBossBullet_[i].GetIsEnemyBossBulletShot1() == false && delayFrameBulletEnemySideBoss_ <= 0)
			{
				delayFrameBulletEnemySideBoss_ = enemySideBossDelayFrameBullet_;
				enemyBossBullet_[i].SetEnemyBossBulletInfo1(enemyBossPosX_, enemyBossPosY_ + 150, 10, rand() % 10 - 5, 16);
				enemyBossBullet_[i].EnemyBossBulletOnColision1();
				break;
			}
		}
		for (int i = 0; i < 20; i++)
		{
			enemyBossBullet_[i].Update2();
			if (enemyBossBullet_[i].GetIsEnemyBossBulletShot2() == false && delayFrameBulletEnemySideBoss1_ <= 0)
			{
				delayFrameBulletEnemySideBoss1_ = enemySideBossDelayFrameBullet1_;
				enemyBossBullet_[i].SetEnemyBossBulletInfo2(enemyBossPosX_, enemyBossPosY_ - 150, 10, rand() % 10 - 5, 16);
				enemyBossBullet_[i].EnemyBossBulletOnColision2();
				break;
			}
		}

		if (enemyBossHP_ <= 0)
		{
			enemyBossIsAlive_ = false;
		}
	}
}

void BossEnemy::Move()
{
	if (enemyBossMoveTime_ >= 0);
	{
		enemyBossMoveTime_--;
	}
	if (enemyBossMove_ == true)
	{
		enemyBossPosX_ -= enemyBossSpeedX_;
	}
	if (enemyBossMoveTime_ <= 0)
	{
		enemyBossMove_ = false;
	}
}

void BossEnemy::Draw()
{
	for (int i = 0; i < 30; i++)
	{
		if (enemyBossBullet_[i].GetIsEnemyBossBulletShot() == true)
		{
			enemyBossBullet_[i].Draw();
		}
	}
	for (int i = 0; i < 20; i++)
	{
		if (enemyBossBullet_[i].GetIsEnemyBossBulletShot1() == true)
		{
			enemyBossBullet_[i].Draw();
		}

		if (enemyBossBullet_[i].GetIsEnemyBossBulletShot2() == true)
		{
			enemyBossBullet_[i].Draw();
		}
		/*Novice::ScreenPrintf(0, 180, "%d", enemyBossBullet_[0].GetEnemyBossBulletRandX());
		Novice::ScreenPrintf(0, 200, "%d", enemyBossBullet_[0].GetEnemyBossBulletPosX());*/

	}
	
	/*if (enemyBossExplosion_ == true)
	{
		for (int i = 0; i < 15; i++)
		{
			particle_[i].DrawEllipse();
		}

	}*/
	if (enemyBossIsAlive_ == true)
	{
		Novice::DrawSprite(enemyBossPosX_ - 32.0f, enemyBossPosY_ - 128.0f, enemyBossPoint_, 4, 4, 0.0f, 0xFFFFFFFF);
		//Novice::DrawBox(enemyBossPosX_, enemyBossPosY_-64, enemyBossRadius_, enemyBossRadius_, 0.0f, WHITE, kFillModeWireFrame);
	// Novice::DrawEllipse(enemyBossPosX1_, enemyBossPosY1_, 32, 32, 0.0f, WHITE, kFillModeSolid);
		//Novice::DrawEllipse(enemyBossPosX2_, enemyBossPosY2_, 32, 32, 0.0f, WHITE, kFillModeSolid);
	}
	if (enemyReceiveDamage_ == true)
	{
		Novice::DrawSprite(enemyBossPosX_ - 32.0f, enemyBossPosY_ - 128.0f, enemyBossPoint_, 4, 4, 0.0f, RED);
		enemyReceiveDamage_ = false;
	}
	if (enemyBossExplosion_ == true && enemyBossRespawnCount_ != 120)
	{
		if (enemyBossRespawnCount_ < 120 && enemyBossRespawnCount_ >= 117)
		{
			Novice::DrawSprite(enemyBossPosX_ - 32.0f, enemyBossPosY_ - 128.0f, drawBossExplosion1_[0], 4, 4, 0.0f, 0xFFFFFFFF);
		}
		if (enemyBossRespawnCount_ <= 117 && enemyBossRespawnCount_ >= 113)
		{
			Novice::DrawSprite(enemyBossPosX_ - 32.0f, enemyBossPosY_ - 128.0f, drawBossExplosion1_[1], 4, 4, 0.0f, 0xFFFFFFFF);
		}
		if (enemyBossRespawnCount_ <= 113 && enemyBossRespawnCount_ >= 107)
		{
			Novice::DrawSprite(enemyBossPosX_ - 32.0f, enemyBossPosY_ - 128.0f, drawBossExplosion1_[2], 4, 4, 0.0f, 0xFFFFFFFF);
		}
		if (enemyBossRespawnCount_ <= 107 && enemyBossRespawnCount_ >= 103)
		{
			Novice::DrawSprite(enemyBossPosX_ - 32.0f, enemyBossPosY_ - 128.0f, drawBossExplosion1_[3], 4, 4, 0.0f, 0xFFFFFFFF);
		}
		if (enemyBossRespawnCount_ <= 103 && enemyBossRespawnCount_ >= 97)
		{
			Novice::DrawSprite(enemyBossPosX_ - 32.0f, enemyBossPosY_ - 128.0f, drawBossExplosion1_[4], 4, 4, 0.0f, 0xFFFFFFFF);
		}
		if (enemyBossRespawnCount_ <= 97)
		{
			Novice::DrawSprite(enemyBossPosX_ - 32.0f, enemyBossPosY_ - 128.0f, drawBossExplosion1_[5], 4, 4, 0.0f, 0xFFFFFFFF);
		}
	}
#ifdef _DEBUG
	Novice::ScreenPrintf(0, 40, "%d", enemyBossHP_);
#endif // DEBUG

}

void BossEnemy::EnemyOnColision()
{
	enemyBossHP_ -= 1;
	enemyReceiveDamage_ = true;
}