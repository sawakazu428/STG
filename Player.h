﻿#pragma once
#include "Novice.h"
#include "PlayerBullet.h"
class Player
{
private:
	int playerPosX_;        // 座標
	int playerPosY_;        // 座標
	int playerRadius_;      // 半径
	int playerSpeedX_;      // 速度
	int playerSpeedY_;      // 速度
	int playerMoveSpeed_;   // 速度の初期化
	int playerHP_;          // HP
	bool playerIsAlive_;    // プレイヤーフラグ
	bool playerAvoid_;      // 回避したときのフラグ
	int avoidCoolTime_;
	int playerAvoidTime_;   // 回避している時間
	bool playerDoubleShot_; // 通常の弾を撃つフラグ
	bool playerShotGun_;    // 拡散弾を撃つフラグ
	bool playerLaserGun_;   // レーザーを撃つフラグ

	int delayFrameBullet_;       // プレイやーの弾丸発射の待機時間
	int delayFrameBullet1_;       // プレイやーの弾丸発射の待機時間
	int delayFrameBullet2_;       // プレイやーの弾丸発射の待機時間

	int playerDelayFrameBullet_; // プレイヤーが射撃するクールタイム
	int playerDelayFrameBullet1_[20]; // プレイヤーが射撃するクールタイム
	int playerDelayFrameBullet2_; // プレイヤーが射撃するクールタイム

	int playerHitTime_;          // プレイヤーが無敵になっている時間
	int playerExplosion_;        // プレイヤーがやられた後に爆発しているかのフラグ
	bool isPlayerInvincibleHit_; // プレイヤーが無敵になる時のフラグ
	bool isPlayerPoint_;         // 生存フラグ
	int playerDefeatCount_;      // プレイヤーがやられた後のフレーム管理
	int blueHealth_[5];          // HP表示
	int playerDisplay_;

	PlayerBullet playerbullet_[20];
public:
	/// <summary>
	/// �������֐�
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V�֐�
	/// </summary>
	void Update(char* keys, char* preKeys);

	/// <summary>
	/// �ړ��֐�
	/// </summary>
	void Move(char* keys, char* preKeys);

	/// <summary>
	/// �`��֐�
	/// </summary>
	void Draw();
	
	PlayerBullet* GetPlayerBullet() { return playerbullet_; }
	int GetPlayerPosX() { return playerPosX_; };
	int GetPlayerPosY() { return playerPosY_; };
	int GetPlayerSpeedX() { return playerSpeedX_; };
	int GetPlayerSpeedY() { return playerSpeedY_; };
	int GetPlayerRadius() { return playerRadius_; };
	int GetPlayerIsAlive() { return playerIsAlive_; };
	int GetPlayerHitPoint() { return playerHP_; };
	int GetPlayerAvoid() { return playerAvoid_; };
	int GetPlayerDoubleShot() { return playerDoubleShot_; };
	int GetPlayerShotGun() { return playerShotGun_; };
	int GetPlayerLaserGun() { return playerLaserGun_; };

	void PlayerOnColision();

};


