#pragma once
#include "Novice.h"
#include "EnemyBullet.h"
class Enemy
{
private:
	int enemyPosX_;
	int enemyPosY_;
	int enemySpeedX_;
	int enemySpeedY_;
	int enemyRadius_;
	int enemyHP_;
	int enemyFramecount_;
	bool enemyIsAlive_;

	bool enemyExplosion_;
	float enemyRespawnCount_;

	int delayFrameBulletEnemy_;
	int enemyDelayFrameBullet_;
	int enemyPoint_;
	int drawExplosion1_[6];

	EnemyBullet enemyBullet_;
public:
	void Initialize();

	void Update();

	void Move();

	void Draw();

	void EnemyOnColision();

	int GetEnemyPosX() { return enemyPosX_; };
	int GetEnemyPosY() { return enemyPosY_; };
	int GetEnemySpeedX() { return enemySpeedX_; };
	int GetEnemySpeedY() { return enemySpeedY_; };
	int GetEnemyRadius() { return enemyRadius_; };
	int GetEnemyIsAlive() { return enemyIsAlive_; };
};
