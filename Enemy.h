#pragma once
#include "Novice.h"
#include "EnemyBullet.h"
#include "Particle.h"
class BoxEnemy
{
	private:
	int enemyPosX_;              // ボックスエネミーの座標X
	int enemyPosY_;		         // ボックスエネミーの座標Y
	int enemySpeedX_;	         // ボックスエネミーのスピードX
	int enemySpeedY_;	         // ボックスエネミーのスピードY
	int enemyRadius_;	         // ボックスエネミーの半径
	int enemyHP_;		         // ボックスエネミーのHP
	bool enemyIsAlive_;	         // ボックスエネミーの描画

	bool enemyExplosion_;        // ボックスエネミーの爆発フラグ
	float enemyRespawnCount_;    // ボックスエネミーのリスポーンするまでのカウント

	int delayFrameBulletEnemy_;  // ボックスエネミーの弾を撃つ間隔を保存する変数
	int enemyDelayFrameBullet_;  // ボックスエネミーの弾を撃つ間隔
	int enemyPoint_;             // ボックスエネミーの描画   
	int drawExplosion1_[6];      // ボックスエネミーの撃破時の描画
	
	int particleRandX_;
	int particleRandY_;
	BoxEnemyBullet enemyBullet_[20]; // ボックスエネミーの弾の管理する変数
	Particle particle_[15];
public:
	
	/// <summary>
	/// 初期化関数
	/// </summary>
	/// <param name="x"></param> 座標X
	/// <param name="y"></param> 座標Y
	void Initialize(int x,int y);

	/// <summary>
	/// 更新関数
	/// </summary>
	void Update();
	/// <summary>
	/// 移動変数
	/// </summary>
	void Move();

	/// <summary>
	/// 描画関数
	/// </summary>
	void Draw();

	/// <summary>
	/// 撃破された時の関数
	/// </summary>
	void EnemyOnColision();

	/// <summary>
	/// 弾をGetする為の関数 + 撃破時のパーティクルの関数 + Get関数達
	/// </summary>
	/// <returns></returns>
	BoxEnemyBullet* GetEnemyBullet() { return enemyBullet_; }

	//Particle* GetPaticle() { return particle_; }
	int GetEnemyPosX() { return enemyPosX_; };
	int GetEnemyPosY() { return enemyPosY_; };
	int GetEnemySpeedX() { return enemySpeedX_; };
	int GetEnemySpeedY() { return enemySpeedY_; };
	int GetEnemyRadius() { return enemyRadius_; };
	int GetEnemyIsAlive() { return enemyIsAlive_; };
};
