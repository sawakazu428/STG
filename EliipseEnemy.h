#pragma once
#include "Novice.h"
#include "EllipseEnemyBullet.h"
#include "Particle.h"
class EllipseEnemy
{
private:
	int enemyEllipsePosX_;
	int enemyEllipsePosY_;
	int enemyEllipseSpeedX_;
	int enemyEllipseSpeedY_;
	int enemyEllipseRadius_;
	int enemyEllipseHP_;
	int enemyEllipseFramecount_;
	bool enemyEllipseIsAlive_;

	bool enemyEllipseExplosion_;
	float enemyEllipseRespawnCount_;

	int delayFrameBulletEnemyEllipse_;
	int enemyEllipseDelayFrameBullet_;
	int enemyEllipsePoint_;
	int drawEllipseExplosion1_[6];

	EllipseEnemyBullet enemyEllipseBullet_[30];
	Particle particle_[15];
public:
	void Initialize(int x, int y);

	void Update();

	void Move();

	void Draw();

	void EnemyOnColision();


	EllipseEnemyBullet* GetEnemyBullet() { return enemyEllipseBullet_; }
	int GetEnemyPosX() { return enemyEllipsePosX_; };
	int GetEnemyPosY() { return enemyEllipsePosY_; };
	int GetEnemySpeedX() { return enemyEllipseSpeedX_; };
	int GetEnemySpeedY() { return enemyEllipseSpeedY_; };
	int GetEnemyRadius() { return enemyEllipseRadius_; };
	int GetEnemyIsAlive() { return enemyEllipseIsAlive_; };
};
