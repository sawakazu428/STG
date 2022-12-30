#pragma once
class PlayerBullet
{
private:
	int playerBulletPosX_;
	int playerBulletPosY_;
	int playerBulletSpeedX_;
	int playerBulletSpeedY_;
	int playerBulletRadius_;
	int playerBulletNum_;
	bool PlayerIsBulletShot_;


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
	int GetPlayerIsBulletShot() { return PlayerIsBulletShot_; };

	void BulletOnColision();
};

