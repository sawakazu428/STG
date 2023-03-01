#pragma once
#pragma once
#include "Novice.h"
#include "BossEnemyBullet.h"
#include "Particle.h"
#include "Player.h"
class BossEnemy
{
private:
	int enemyBossPosX_;
	int enemyBossPosY_;
	int enemyBossPosX1_;
	int enemyBossPosY1_;
	int enemyBossPosX2_;
	int enemyBossPosY2_;
	
	bool enemyBossMove_;
	int enemyBossMoveTime_;
	int enemyBossSpeedX_;
	int enemyBossSpeedY_;
	int enemyBossRadius_;
	int enemyBossHP_;
	int enemyBossFramecount_;
	bool enemyBossIsAlive_;
	bool enemyReceiveDamage_;

	bool enemyBossExplosion_;
	float enemyBossRespawnCount_;

	int delayFrameBulletEnemyBoss_;
	int delayFrameBulletEnemySideBoss_;
	int delayFrameBulletEnemySideBoss1_;
	int enemyBossDelayFrameBullet_;
	int enemySideBossDelayFrameBullet_;
	int enemySideBossDelayFrameBullet1_;
	int enemyBossPoint_;
	int drawBossExplosion1_[6];

	BossEnemyBullet enemyBossBullet_[30];
	Particle particle_[15];
public:
	void Initialize(int x, int y, int x1, int y1, int x2, int y2);

	void Update();

	void Move();

	void Draw();

	void EnemyOnColision();


	BossEnemyBullet* GetEnemyBullet() { return enemyBossBullet_; }
	int GetBossEnemyPosX() { return enemyBossPosX_; };
	int GetBossEnemyPosY() { return enemyBossPosY_; };
	int GetBossEnemySpeedX() { return enemyBossSpeedX_; };
	int GetBossEnemySpeedY() { return enemyBossSpeedY_; };
	int GetBossEnemyRadius() { return enemyBossRadius_; };
	int GetBossEnemyIsAlive() { return enemyBossIsAlive_; };
	int GetBossEnemyRespawnCount() { return enemyBossRespawnCount_; };
	int GetBossEnemyMove() { return enemyBossMove_; };
};


