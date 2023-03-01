#pragma once
#include "Novice.h"
class PlayerBullet
{
private:
	int playerBulletPosX_;
	int playerBulletPosY_;
	int playerRightBulletPosX_;
	int playerBottomBulletPosY_;
	int playerBulletSpeedX_;
	int playerBulletSpeedY_;
	int playerBulletRadius_;
	int playerBulletNum_;
	bool playerIsBulletShot_;
	bool isPlayerDiffusionShot_[5];
	int playerBulletPoint_;
public:
	void Initialize();

	void NormalUpdate();

	void DiffusionUpdate();

	void LinearUpdate();

	void Draw();

	void SetPlayerBulletInfo(int posX, int posY, int speedX, int speedY);

	bool* GetIsPlayerDiffusionShot() { return isPlayerDiffusionShot_; };
	int GetPlayerBulletPosX() { return playerBulletPosX_; };
	int GetPlayerBulletPosY() { return playerBulletPosY_; };	
	int GetPlayerBulletSpeedX() { return playerBulletSpeedX_; };
	int GetPlayerBulletSpeedY() { return playerBulletSpeedY_; };
	int GetPlayerBulletRadius() { return playerBulletRadius_; };
	bool GetPlayerIsBulletShot() { return playerIsBulletShot_; };
	constexpr int GetPlayerBulletNum() { return playerBulletNum_; };

	void BulletOnColision();

	void BulletDiffusionOnColision();

	void BulletReceiveOnColision();
};

