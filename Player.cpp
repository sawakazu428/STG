#include "Player.h"

void Player::Initialize()
{
	playerPosX_ = 100;
	playerPosY_ = 360;
	playerRadius_ = 32;
	playerSpeedX_ = 6;
	playerSpeedY_ = 6;
	playerMoveSpeed_ = 6;
	playerHP_ = 5;
	playerIsAlive_ = true;
	playerAvoid_ = false;
	avoidCoolTime_ = 60;
	playerAvoidTime_ = 30;
	delayFrameBullet_ = 25;
	delayFrameBullet1_ = 50;
	delayFrameBullet2_ = 40;
	playerDelayFrameBullet_ = 30;
	playerDelayFrameBullet1_[5] = { 60 };
	playerDelayFrameBullet2_ = 40;
	playerDoubleShot_ = true;
	playerShotGun_ = false;
	playerLaserGun_ = false;

	playerHitTime_ = 90;
	isPlayerInvincibleHit_ = false;
	isPlayerPoint_ = true;
	playerExplosion_ = false;
	playerDefeatCount_ = 60;
	for (int i = 0; i < 20; i++)
	{
		playerbullet_[i].Initialize();
	}
	blueHealth_[0] = Novice::LoadTexture("./Resources/blueHeart.png");
	blueHealth_[1] = Novice::LoadTexture("./Resources/blueHeart.png");
	blueHealth_[2] = Novice::LoadTexture("./Resources/blueHeart.png");
	blueHealth_[3] = Novice::LoadTexture("./Resources/blueHeart.png");
	blueHealth_[4] = Novice::LoadTexture("./Resources/blueHeart.png");
	playerDisplay_ = Novice::LoadTexture("./Resources/player.png");
}

void Player::Update(char* keys, char* preKeys)
{
	if (playerDelayFrameBullet_ >= 0)
	{
		playerDelayFrameBullet_--;
	}
	for (int j = 0; j < 5; j++)
	{
		if (playerDelayFrameBullet1_[j] >= 0)
		{
			playerDelayFrameBullet1_[j]--;
		}
	}
	if (playerDelayFrameBullet2_ >= 0)
	{
		playerDelayFrameBullet2_--;
	}
	
	if (keys[DIK_Q] && preKeys[DIK_Q] == 0 && playerDoubleShot_ == true)
	{
		playerDoubleShot_ = false;
		playerShotGun_ = false;
		playerLaserGun_ = true; // ON
	}
	if (keys[DIK_E] && preKeys[DIK_E] == 0 && playerDoubleShot_ == true)
	{
		playerDoubleShot_ = false;
		playerShotGun_ = true; // ON
		playerLaserGun_ = false; 
	}

	if (keys[DIK_Q] && preKeys[DIK_Q] == 0 && playerLaserGun_ == true)
	{
		playerDoubleShot_ = false;
		playerShotGun_ = true; // ON
		playerLaserGun_ = false;
	}
	if (keys[DIK_E] && preKeys[DIK_E] == 0 && playerLaserGun_ == true)
	{
		playerDoubleShot_ = true; // ON
		playerShotGun_ = false;
		playerLaserGun_ = false;
	}

	if (keys[DIK_Q] && preKeys[DIK_Q] == 0 && playerShotGun_ == true)
	{
		playerDoubleShot_ = true; // ON
		playerShotGun_ = false;
		playerLaserGun_ = false;
	}

	if (keys[DIK_E] && preKeys[DIK_E] == 0 && playerShotGun_ == true)
	{
		playerDoubleShot_ = false;
		playerShotGun_ = false; 
		playerLaserGun_ = true; // ON
	}

	if (playerAvoid_ == false)
	{
		avoidCoolTime_--;
	}
	if (keys[DIK_Z] && preKeys[DIK_Z] == 0 &&  playerAvoid_ == false && avoidCoolTime_ <= 0|| keys[DIK_R] && preKeys[DIK_R] == 0 && playerAvoid_ == false)
	{
		playerAvoid_ = true;
	}
	if (playerAvoid_ == true)
	{
		playerAvoidTime_--;
	}
	if (playerAvoidTime_ <= 0)
	{
		playerAvoid_ = false;
		playerAvoidTime_ = 30;
		avoidCoolTime_ = 60;
	}

	if (playerDoubleShot_ == true)
	{
		for (int i = 0; i < 20; i++)
		{
			playerbullet_[i].NormalUpdate();

			if (playerbullet_[i].GetPlayerIsBulletShot() == false)
			{
				if (keys[DIK_SPACE] && playerDelayFrameBullet_ <= 0)
				{
					playerDelayFrameBullet_ = delayFrameBullet_;
					playerbullet_[i].SetPlayerBulletInfo(playerPosX_, playerPosY_, 10, 10);
					playerbullet_[i].BulletOnColision();
				}
			}
		}
	}
		
	if (playerShotGun_ == true)
	{
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 5; j++)
			{

				playerbullet_[i].DiffusionUpdate();

				if (playerbullet_[i].GetPlayerIsBulletShot() == false)
				{
					if (keys[DIK_SPACE] && playerDelayFrameBullet1_[j] <= 0)
					{
						playerDelayFrameBullet1_[j] = delayFrameBullet1_;
						playerbullet_[i].SetPlayerBulletInfo(playerPosX_, playerPosY_, rand() % 3 - 0 + 1, rand() % 6 - 3);
						playerbullet_[i].BulletOnColision();
					}
				}


			}
		}
	}

	for (int i = 0; i < 20; i++)
	{
		if (playerLaserGun_ == true)
		{
			playerbullet_[i].LinearUpdate();

			if (playerbullet_[i].GetPlayerIsBulletShot() == false)
			{
				if (keys[DIK_SPACE] && playerDelayFrameBullet2_ <= 0)
				{
					playerDelayFrameBullet_ = delayFrameBullet_;
					playerbullet_[i].SetPlayerBulletInfo(playerPosX_, playerPosY_, playerSpeedX_, playerSpeedY_);
					playerbullet_[i].BulletOnColision();
				}
			}

		}
	}

	if (playerIsAlive_ == false)
	{
		playerHitTime_--;
	}
	if (playerHitTime_ <= 0)
	{
		playerIsAlive_ = true;
		isPlayerInvincibleHit_ = false;
		playerHitTime_ = 90;
	}
	if (playerHP_ == 0)
	{
		isPlayerPoint_ = false;
	}
	if (isPlayerPoint_ == false)
	{
		playerDefeatCount_--;
		playerExplosion_ = true;
	}
	if (playerDefeatCount_ <= 30)
	{
		playerExplosion_ = false;
	}
	if (playerDefeatCount_ == 0)
	{
		isPlayerPoint_ = true;
		playerDefeatCount_ = 60;
	}
}

void Player::Move(char* keys, char* preKeys)
{
	playerSpeedX_ = playerMoveSpeed_;
	playerSpeedY_ = playerMoveSpeed_;

	if (keys[DIK_W] || keys[DIK_UP])
	{
		if (playerPosY_ < 0)
		{
			playerPosY_ = 0;
		}
		playerPosY_ -= playerSpeedY_;
	}

	if (keys[DIK_A] || keys[DIK_LEFT])
	{
		if (playerPosX_ < 0)
		{
			playerPosX_ = 0;
		}
		playerPosX_ -= playerSpeedX_;
	}

	if (keys[DIK_S] || keys[DIK_DOWN])
	{
		if (playerPosY_ + playerRadius_ > 720)
		{
			playerPosY_ = 720 - playerRadius_;
		}
		playerPosY_ += playerSpeedY_;
	}

	if (keys[DIK_D] || keys[DIK_RIGHT])
	{
		if (playerPosX_ + playerRadius_ > 1280)
		{
			playerPosX_ = 1280 - playerRadius_;
		}
		playerPosX_ += playerSpeedX_;
	}
}

void Player::Draw()
{
	if (playerHP_ >= 1)
	{
		//Novice::DrawBox(playerPosX_-16, playerPosY_-16, playerRadius_, playerRadius_, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawSprite(playerPosX_ - 36, playerPosY_ - 36, playerDisplay_, 1, 1, 0.0f, 0xFFFFFFFF);
		if (isPlayerInvincibleHit_ == true)
		{
			Novice::DrawSprite(playerPosX_ - 36, playerPosY_ - 36, playerDisplay_, 1, 1, 0.0f, RED);

		//	Novice::DrawBox(playerPosX_-16, playerPosY_-16, playerRadius_, playerRadius_, 0.0f, RED, kFillModeSolid);
		}
	}
	if (playerHP_ == 5)
	{
		Novice::DrawSprite(128, 0, blueHealth_[4], 1, 1, 0.0f, 0xFFFFFFFF);
		Novice::DrawSprite(96, 0, blueHealth_[3], 1, 1, 0.0f, 0xFFFFFFFF);
		Novice::DrawSprite(64,0, blueHealth_[2], 1, 1, 0.0f, 0xFFFFFFFF);
		Novice::DrawSprite(32,0, blueHealth_[1], 1, 1, 0.0f, 0xFFFFFFFF);
		Novice::DrawSprite(0, 0, blueHealth_[0], 1, 1, 0.0f, 0xFFFFFFFF);
	}
	if (playerHP_ == 4)
	{
		Novice::DrawSprite(96, 0, blueHealth_[3], 1, 1, 0.0f, 0xFFFFFFFF);
		Novice::DrawSprite(64, 0, blueHealth_[2], 1, 1, 0.0f, 0xFFFFFFFF);
		Novice::DrawSprite(32, 0, blueHealth_[1], 1, 1, 0.0f, 0xFFFFFFFF);
		Novice::DrawSprite(0, 0, blueHealth_[0], 1, 1, 0.0f, 0xFFFFFFFF);
	}
	if (playerHP_ == 3)
	{
		Novice::DrawSprite(64, 0, blueHealth_[2], 1, 1, 0.0f, 0xFFFFFFFF);
		Novice::DrawSprite(32, 0, blueHealth_[1], 1, 1, 0.0f, 0xFFFFFFFF);
		Novice::DrawSprite(0, 0, blueHealth_[0], 1, 1, 0.0f, 0xFFFFFFFF);
	}
	if (playerHP_ == 2)
	{
		Novice::DrawSprite(32, 0, blueHealth_[1], 1, 1, 0.0f, 0xFFFFFFFF);
		Novice::DrawSprite(0, 0, blueHealth_[0], 1, 1, 0.0f, 0xFFFFFFFF);
	}
	if (playerHP_ == 1)
	{
		Novice::DrawSprite(0, 0, blueHealth_[0], 1, 1, 0.0f, 0xFFFFFFFF);
	}
#ifdef _DEBUG


	//Novice::ScreenPrintf(0, 0, "posX %d", playerbullet_[0].GetPlayerBulletPosX());
	//Novice::ScreenPrintf(0, 20, "posY %d", playerbullet_[0].GetPlayerBulletPosY());
	//Novice::ScreenPrintf(0, 40, "speedX %d", playerbullet_[0].GetPlayerBulletSpeedX());
	//Novice::ScreenPrintf(0, 60, "speedY %d", playerbullet_[0].GetPlayerBulletSpeedY());
	//Novice::ScreenPrintf(0, 80, "radius %d", playerbullet_[0].GetPlayerBulletRadius());
	//Novice::ScreenPrintf(0, 100, "isBullet %d", playerbullet_[0].GetPlayerIsBulletShot());
	//Novice::ScreenPrintf(0, 120, "playerShotGun_ %d", playerShotGun_);
	//Novice::ScreenPrintf(0, 140, "%d", playerAvoid_);
#endif // DEBUG

	for (int i = 0; i < 20; i++)
	{
		playerbullet_[i].Draw();
	}
}

void Player::PlayerOnColision()
{
	playerHP_ -= 1;
	isPlayerInvincibleHit_ = true;
	playerIsAlive_ = false;
}
