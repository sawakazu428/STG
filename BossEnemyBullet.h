#pragma once
#include "Novice.h"
class BossEnemyBullet
{
private:
	int enemyBossBulletPosX_;
	int enemyBossBulletPosY_;
	int enemyBossBulletPosX1_;
	int enemyBossBulletPosY1_;
	int enemyBossBulletPosX2_;
	int enemyBossBulletPosY2_;
	int enemyBossBulletRadius_;
	int enemyBossBulletSpeedX_;
	int enemyBossBulletSpeedY_;

	float enemyBossAcceleration_;
	float enemyBossRandX_;
	float enemyBossRandY_; 
	float enemyBossRandX1_;
	float enemyBossRandY1_;

	int enemyBossBulletNum_;
	bool isEnemyBossBulletShot_;
	bool isEnemyBossBulletShot1_;
	bool isEnemyBossBulletShot2_;

	int drawEnemyBossBullet_;
public:
	void Initialize();

	void Update();

	void Update1();

	void Update2();

	void Draw();

	int GetEnemyBossBulletPosX() { return enemyBossBulletPosX_; };
	int GetEnemyBossBulletPosY() { return enemyBossBulletPosY_; };
	int GetEnemyBossBulletPosX1() { return enemyBossBulletPosX1_; };
	int GetEnemyBossBulletPosY1() { return enemyBossBulletPosY1_; };
	int GetEnemyBossBulletPosX2() { return enemyBossBulletPosX2_; };
	int GetEnemyBossBulletPosY2() { return enemyBossBulletPosY2_; };
	int GetEnemyBossBulletRandX() { return enemyBossRandX_; };
	int GetEnemyBossBulletRandY() { return enemyBossRandY_; };
	int GetEnemyBossBulletRadius() { return enemyBossBulletRadius_; };
	int GetIsEnemyBossBulletShot() { return isEnemyBossBulletShot_; };
	int GetIsEnemyBossBulletShot1() { return isEnemyBossBulletShot1_; };
	int GetIsEnemyBossBulletShot2() { return isEnemyBossBulletShot2_; };

	void SetEnemyBossBulletInfo(int posX, int posY, int speedX, int speedY, int radius);
	void SetEnemyBossBulletInfo1(int posX, int posY, int speedX, int speedY, int radius);
	void SetEnemyBossBulletInfo2(int posX, int posY, int speedX, int speedY, int radius);

	void EnemyBossBulletOnColision();
	void EnemyBossBulletOnColision1();
	void EnemyBossBulletOnColision2();

	void EnemyBossReceiveBulletOnColision();
	void EnemyBossReceiveBulletOnColision1();
	void EnemyBossReceiveBulletOnColision2();

};

