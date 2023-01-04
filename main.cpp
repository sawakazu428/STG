#include <Novice.h>
#include "Player.h"
#include "Enemy.h"

const char kWindowTitle[] = "GC1A_12_サワダカズキ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Player player;

	player.Initialize();

	PlayerBullet playerbullet;

	playerbullet.Initialize();

	Enemy enemy;

	enemy.Initialize();

	EnemyBullet enemybullet;

	enemybullet.Initialize();

	int playerBulletDistance;

	int enemybulletdistance;

	int score = 0;
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		player.Move(keys, preKeys);

		player.Update(keys, preKeys);

			playerBulletDistance = (playerbullet.GetPlayerBulletPosX() - enemy.GetEnemyPosX()) * (playerbullet.GetPlayerBulletPosX() - enemy.GetEnemyPosX()) + (playerbullet.GetPlayerBulletPosY() - enemy.GetEnemyPosY()) * (playerbullet.GetPlayerBulletPosY() - enemy.GetEnemyPosY());

			if (enemy.GetEnemyIsAlive() && playerbullet.GetPlayerIsBulletShot() == true)
			{
				if (playerbullet.GetPlayerBulletRadius() + enemy.GetEnemyRadius() * playerbullet.GetPlayerBulletRadius() + enemy.GetEnemyRadius() >= playerBulletDistance)
				{

				playerbullet.BulletOnColision();
				score += 100;
				}
			}
			enemy.Update();

			enemy.Move();

			enemybullet.Update();

			enemybulletdistance = (enemybullet.GetEnemyBulletPosX() - player.GetPlayerPosX()) * (enemybullet.GetEnemyBulletPosX() - player.GetPlayerPosX()) + (enemybullet.GetEnemyBulletPosY() - player.GetPlayerPosY()) * (enemybullet.GetEnemyBulletPosY() - player.GetPlayerPosY());

			if (enemybullet.GetIsEnemyBulletShot() == true && player.GetPlayerIsAlive() == true)
			{
				if ((enemybullet.GetEnemyBulletRadius() + player.GetPlayerRadius()) * (enemybullet.GetEnemyBulletRadius() + player.GetPlayerRadius()) >= enemybulletdistance) //敵の弾が自機に当たる判定
				{
					enemybullet.EnemyBulletOnColision();
					player.PlayerOnColision();
				}
			}


			///
			/// ↑更新処理ここまで
			///

			///
			/// ↓描画処理ここから
			///

			///
			/// ↑描画処理ここまで
			///

			// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}