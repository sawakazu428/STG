#pragma once
#pragma once
#include "Novice.h"
#include "TriangleEnemyBullet.h"
#include "Particle.h"
class TriangleEnemy
{
private:
	int enemyTrianglePosX_;
	int enemyTrianglePosY_;
	int enemyTriangleSpeedX_;
	int enemyTriangleSpeedY_;
	int enemyTriangleRadius_;
	int enemyTriangleHP_;
	int enemyTriangleFramecount_;
	bool enemyTriangleIsAlive_;

	bool enemyTriangleExplosion_;
	float enemyTriangleRespawnCount_;

	int delayFrameBulletEnemyTriangle_;
	int enemyTriangleDelayFrameBullet_;
	int enemyTrianglePoint_;
	int drawTriangleExplosion1_[6];

	TriangleEnemyBullet enemyTriangleBullet_[20];
	Particle particle_[15];
public:
	void Initialize(int x, int y);

	void Update();

	void Move();

	void Draw();

	void EnemyOnColision();


	TriangleEnemyBullet* GetEnemyBullet() { return enemyTriangleBullet_; }
	int GetEnemyPosX() { return enemyTrianglePosX_; };
	int GetEnemyPosY() { return enemyTrianglePosY_; };
	int GetEnemySpeedX() { return enemyTriangleSpeedX_; };
	int GetEnemySpeedY() { return enemyTriangleSpeedY_; };
	int GetEnemyRadius() { return enemyTriangleRadius_; };
	int GetEnemyIsAlive() { return enemyTriangleIsAlive_; };
};

