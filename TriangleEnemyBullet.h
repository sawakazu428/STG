#pragma once
#include "Novice.h"
#define _USE_MATH_DEFINES
#include <math.h>



class TriangleEnemyBullet
{
private:
	int enemyTriangleBulletPosX_;
	int enemyTriangleBulletPosY_;
	int enemyTriangleBulletRadius_;
	int enemyTriangleBulletSpeedX_;
	int enemyTriangleBulletSpeedY_;
	int enemyTriangleBulletNum_;
	bool isEnemyTriangleBulletShot_;
	int drawEnemyTriangleBullet_;

	int nowFrame_;
	float endFrame_;
	float kMaxFrame_;
	float moveInFrame_;

public:
	void Initialize();

	void Update();

	void Draw();

	int GetEnemyTriangleBulletPosX() { return enemyTriangleBulletPosX_; };
	int GetEnemyTriangleBulletPosY() { return enemyTriangleBulletPosY_; };
	int GetEnemyTriangleBulletRadius() { return enemyTriangleBulletRadius_; };
	int GetIsEnemyTriangleBulletShot() { return isEnemyTriangleBulletShot_; };
	void SetEnemyTriangleBulletInfo(int posX, int posY, int speedX, int speedY, int radius);

	void EnemyTriangleBulletOnColision();

	void EnemyTriangleReceiveBulletOnColision();
};