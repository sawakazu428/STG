#pragma once
#include "Novice.h"
#define _USE_MATH_DEFINES
#include <math.h>



class EllipseEnemyBullet
{
private:
	int enemyEllipseBulletPosX_;
	int enemyEllipseBulletPosY_;
	int enemyEllipseBulletRadius_;
	int enemyEllipseBulletSpeedX_;
	int enemyEllipseBulletSpeedY_;
	int enemyEllipseBulletNum_;
	bool isEnemyEllipseBulletShot_;
	bool isEnemyEllipseBulletShot1_;
	bool isEnemyEllipseBulletShot2_;

	int drawEnemyEllipseBullet_;
public:
	void Initialize();

	void Update();

	void Draw();

	int GetEnemyEllipseBulletPosX() { return enemyEllipseBulletPosX_; };
	int GetEnemyEllipseBulletPosY() { return enemyEllipseBulletPosY_; };
	int GetEnemyEllipseBulletRadius() { return enemyEllipseBulletRadius_; };
	int GetIsEnemyEllipseBulletShot() { return isEnemyEllipseBulletShot_; };
	int GetIsEnemyEllipseBulletShot1() { return isEnemyEllipseBulletShot1_; };
	int GetIsEnemyEllipseBulletShot2() { return isEnemyEllipseBulletShot2_; };

	void SetEnemyEllipseBulletInfo(int posX, int posY, int speedX, int speedY, int radius);

	void EnemyEllipseBulletOnColision();
	void EnemyEllipseBulletOnColision1();
	void EnemyEllipseBulletOnColision2();

	void EnemyEllipseReceiveBulletOnColision();
};


