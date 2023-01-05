#include "Player.h"

void Player::Initialize()
{
	playerPosX_ = 100;
	playerPosY_ = 360;
	playerRadius_ = 50;
	playerSpeedX_ = 6;
	playerSpeedY_ = 6;
	playerMoveSpeed_ = 6;
	playerHP_ = 5;
	playerIsAlive_ = true;
	playerAvoid_ = false;
	playerAvoidTime_ = 10;
	delayFrameBullet_ = 30;
	playerDelayFrameBullet_ = delayFrameBullet_;
	playerDoubleShot_ = true;
	playerShotGun_ = false;
	playerLaserGun_ = false;

	playerHitTime_ = 90;
	isPlayerInvincibleHit_ = true;
	isPlayerPoint_ = true;
	playerExplosion_ = false;
	playerDefeatCount_ = 60;
	blueHealth_[0] = Novice::LoadTexture("./Resources/blueHeart.png");
	blueHealth_[1] = Novice::LoadTexture("./Resources/blueHeart.png");
	blueHealth_[2] = Novice::LoadTexture("./Resources/blueHeart.png");

}

void Player::Update(char* keys, char* preKeys)
{
	if (playerDelayFrameBullet_ < 0)
	{
		playerDelayFrameBullet_--;
	}
	
	if (keys[DIK_Q] && preKeys[DIK_Q] == 0 && playerDoubleShot_ == true)
	{
		playerDoubleShot_ = false;
		playerShotGun_ = false;
		playerLaserGun_ = true; // ON
	}
	if (keys[DIK_Q] && preKeys[DIK_Q] == 0 && playerLaserGun_ == true)
	{
		playerDoubleShot_ = false;
		playerShotGun_ = true; // ON
		playerLaserGun_ = false;
	}
	if (keys[DIK_Q] && preKeys[DIK_Q] == 0 && playerShotGun_ == true)
	{
		playerDoubleShot_ = true; // ON
		playerShotGun_ = false;
		playerLaserGun_ = false;
	}

	if (keys[DIK_E] && preKeys[DIK_E] == 0 && playerDoubleShot_ == true)
	{
		playerDoubleShot_ = false;
		playerShotGun_ = false;
		playerLaserGun_ = true; // ON
	}
	if (keys[DIK_E] && preKeys[DIK_E] == 0 && playerLaserGun_ == true)
	{
		playerDoubleShot_ = false;
		playerShotGun_ = true; // ON
		playerLaserGun_ = false;
	}
	if (keys[DIK_E] && preKeys[DIK_E] == 0 && playerShotGun_ == true)
	{
		playerDoubleShot_ = true; // ON
		playerShotGun_ = false;
		playerLaserGun_ = false;
	}


	if (keys[DIK_Z] && preKeys[DIK_Z] == 0)
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
		playerAvoidTime_ = 10;
	}

	if (playerbullet_.GetPlayerIsBulletShot() == false)
	{
		if (keys[DIK_SPACE] && playerDelayFrameBullet_ <= 0)
		{
			playerDelayFrameBullet_ = delayFrameBullet_;
			playerbullet_.SetPlayerBulletInfo(playerPosX_, playerPosY_, playerSpeedX_, playerSpeedY_, playerRadius_);
		}
	}
	if (playerDoubleShot_ == true)
	{
		playerbullet_.NormalUpdate();
	}

	if (playerShotGun_ == true)
	{
		playerbullet_.DiffusionUpdate();
	}
	
	if (playerLaserGun_ == true)
	{
		playerbullet_.LinearUpdate();
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
		playerHP_ = 3;
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
		if (playerPosY_ - playerRadius_ < 0)
		{
			playerPosY_ = 0;
		}
		playerPosY_ -= playerSpeedY_;
	}

	if (keys[DIK_A] || keys[DIK_LEFT])
	{
		if (playerPosX_ - playerRadius_ < 0)
		{
			playerPosX_ = 0;
		}
		playerPosX_ -= playerSpeedX_;
	}

	if (keys[DIK_S] || keys[DIK_DOWN])
	{
		if (playerPosY_ + playerRadius_ > 720)
		{
			playerPosY_ = 720;
		}
		playerPosY_ += playerSpeedY_;
	}

	if (keys[DIK_D] || keys[DIK_RIGHT])
	{
		if (playerPosX_ + playerRadius_ > 1280)
		{
			playerPosX_ = 1280;
		}
		playerPosX_ += playerSpeedX_;
	}
}

void Player::Draw()
{
	if (playerHP_ >= 1)
	{
		Novice::DrawBox(playerPosX_, playerPosY_, playerRadius_, playerRadius_, 0.0f, WHITE, kFillModeSolid);
		if (isPlayerInvincibleHit_ == true)
		{
			Novice::DrawBox(playerPosX_, playerPosY_, playerRadius_, playerRadius_, 0.0f, RED, kFillModeSolid);
		}
	}

	if (playerHP_ == 3)
	{
		Novice::DrawSprite(884, 245, blueHealth_[2], 1, 1, 0.0f, 0xFFFFFFFF);
		Novice::DrawSprite(852, 245, blueHealth_[1], 1, 1, 0.0f, 0xFFFFFFFF);
		Novice::DrawSprite(820, 245, blueHealth_[0], 1, 1, 0.0f, 0xFFFFFFFF);
	}
	if (playerHP_ == 2)
	{
		Novice::DrawSprite(852, 245, blueHealth_[1], 1, 1, 0.0f, 0xFFFFFFFF);
		Novice::DrawSprite(820, 245, blueHealth_[0], 1, 1, 0.0f, 0xFFFFFFFF);
	}
	if (playerHP_ == 1)
	{
		Novice::DrawSprite(820, 245, blueHealth_[0], 1, 1, 0.0f, 0xFFFFFFFF);
	}

}

void Player::PlayerOnColision()
{
	playerHP_ -= 1;
	isPlayerInvincibleHit_ = true;
	playerIsAlive_ = false;
}
