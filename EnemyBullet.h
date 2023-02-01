#pragma once
#include "Novice.h"
class BoxEnemyBullet
{
private:
	int enemyBulletPosX_;    // ボックスエネミーの弾の座標X
	int enemyBulletPosY_;    // ボックスエネミーの弾の座標Y
	int enemyBulletRadius_;  // ボックスエネミーの弾の半径
	int enemyBulletSpeedX_;  // ボックスエネミーの弾のスピードX
	int enemyBulletSpeedY_;  // ボックスエネミーの弾のスピードY
	int enemyBulletNum_;     // ボックスエネミーの弾の数
	bool isEnemyBulletShot_; // ボックスエネミーの弾のフラグ
	int drawEnemyBullet_;    // ボックスエネミーの弾の描画
public:
	/// <summary>
	/// 初期化関数
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新関数
	/// </summary>
	void Update();

	/// <summary>
	/// 描画関数
	/// </summary>
	void Draw();

	/// <summary>
	/// ゲット関数達
	/// </summary>
	/// <returns></returns>
	int GetEnemyBulletPosX() { return enemyBulletPosX_; };
	int GetEnemyBulletPosY() { return enemyBulletPosY_; };
	int GetEnemyBulletRadius() { return enemyBulletRadius_; };
	int GetIsEnemyBulletShot() { return isEnemyBulletShot_; };

	/// <summary>
	/// セット関数　// 弾とプレイヤーの位置を合わせる
	/// </summary>
	/// <param name="posX"></param>   
	/// <param name="posY"></param>   
	/// <param name="speedX"></param>
	/// <param name="speedY"></param>
	/// <param name="radius"></param>
	void SetEnemyBulletInfo(int posX, int posY, int speedX, int speedY, int radius);

	/// <summary>
	/// 弾が当たった時の関数
	/// </summary>
	void EnemyBulletOnColision();


	/// <summary>
	/// 弾を当てられた時の関数
	/// </summary>
	void EnemyReceiveBulletOnColision();
};

