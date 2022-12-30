#pragma once
#include "Enemy.h"
class EnemyBullet
{
private:
	float enemyBulletPosX_;
	float enemyBulletPosY_;
	float enemyBulletRadius_;
	float enemyBulletSpeedX_;
	float enemyBulletSpeedY_;
	int enemyBulletNum_;
	bool isEnemyBulletShot_;
	int drawEnemyBullet_;
public:
	void Initialize();

	void Update();

	void Draw();

	int GetEnemyBulletPosX() { return enemyBulletPosX_; };
	int GetEnemyBulletPosY() { return enemyBulletPosY_; };
	int GetEnemyBulletRadius() { return enemyBulletRadius_; };
	int GetIsEnemyBulletShot() { return isEnemyBulletShot_; };
	void SetEnemyBulletInfo(int posX, int posY, int speedX, int speedY, int radius);

	void EnemyBulletOnColision();
};

