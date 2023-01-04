#pragma once
#include "Player.h"
class PlayerBullet
{
private:
	int playerBulletPosX_;
	int playerBulletPosY_;
	int playerBulletSpeedX_;
	int playerBulletSpeedY_;
	int playerBulletRadius_;
	int playerBulletNum_;
	bool playerIsBulletShot_;
	int playerBulletPoint_;

public:
	void Initialize();

	void Update();

	void Draw();

	void SetPlayerBulletInfo(int posX, int posY, int speedX, int speedY, int radius);

	int GetPlayerBulletPosX() { return playerBulletPosX_; };
	int GetPlayerBulletPosY() { return playerBulletPosY_; };
	int GetPlayerBulletSpeedX() { return playerBulletSpeedX_; };
	int GetPlayerBulletSpeedY() { return playerBulletSpeedY_; };
	int GetPlayerBulletRadius() { return playerBulletRadius_; };
	int GetPlayerIsBulletShot() { return playerIsBulletShot_; };

	void BulletOnColision();
};

