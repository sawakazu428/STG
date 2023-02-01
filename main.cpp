#include <Novice.h>
#include "Player.h"
#include "Enemy.h"
#include "EliipseEnemy.h"
#include "TriangleEnemy.h"
#include "Scene.h"

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

	BoxEnemy enemy[5]{};
	for (int i = 0; i < 5; i++)
	{
		enemy[i].Initialize(500 + (i + 1) * 100, 160 + (i + 1) * 100);
	}

	EllipseEnemy ellipseEnemy[5]{};
	for (int i = 0; i < 3; i++)
	{
		ellipseEnemy[i].Initialize(820, 160 + (i * 200));
	}

	TriangleEnemy triangleEnemy[5]{};
	for (int i = 0; i < 3; i++)
	{
		triangleEnemy[i].Initialize(820 + (-i * 50), 160 + (i * 100));
	}

	for (int i = 3; i < 5; i++)
	{
		triangleEnemy[i].Initialize(620 + (i * 50), 160 + (i * 100));
	}
	Scene scene;

	scene.Initialize();
	int red = scene.GetRed_();
	int green = scene.GetGreen_();
	int blue = scene.GetBlue_();
	int alpha = scene.GetAlpha_();

	int flag = false;

	int playerBulletDistance;
	int playerEllipseBulletDistance;
	int playerTriangleBulletDistance;

	int enemyBulletDistance;
	int enemyEllipseBulletDistance;
	int enemyTriangleBulletDistance;

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

		if (keys[DIK_Q])
		{
			flag = true;
		}
		if(flag == true)
		{
			red++;
			
		}
		//scene.SetDrawBright(red, green, blue, alpha); // 試行段階(まだできてない)
		//if (red == 255 || green == 255 || blue == 255 || alpha == 255)
		//{
		//	flag = false;
		//}
		scene.Update();

		player.Move(keys, preKeys);

		player.Update(keys, preKeys);
		for (int i = 0; i < 5; i++)
		{
			/*enemy[i].Update();

			enemy[i].Move();*/
			ellipseEnemy[i].Update();

			ellipseEnemy[i].Move();
			/*
			triangleEnemy[i].Update();

			triangleEnemy[i].Move();*/
		}
		
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				playerBulletDistance = (player.GetPlayerBullet()[j].GetPlayerBulletPosX() - enemy[i].GetEnemyPosX()) * (player.GetPlayerBullet()[j].GetPlayerBulletPosX() - enemy[i].GetEnemyPosX()) + (player.GetPlayerBullet()[j].GetPlayerBulletPosY() - enemy[i].GetEnemyPosY()) * (player.GetPlayerBullet()[j].GetPlayerBulletPosY() - enemy[i].GetEnemyPosY());


				if (enemy[i].GetEnemyIsAlive() == true && player.GetPlayerBullet()[j].GetPlayerIsBulletShot() == true)
				{
					if (player.GetPlayerBullet()[j].GetPlayerBulletRadius() + enemy[i].GetEnemyRadius() * player.GetPlayerBullet()[j].GetPlayerBulletRadius() + enemy[i].GetEnemyRadius() >= playerBulletDistance)
					{
						score += 100;
						enemy[i].EnemyOnColision();
						player.GetPlayerBullet()[j].BulletReceiveOnColision();
					}
				}
			}
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				enemyBulletDistance = (enemy[i].GetEnemyBullet()[j].GetEnemyBulletPosX() - player.GetPlayerPosX()) * (enemy[i].GetEnemyBullet()[j].GetEnemyBulletPosX() - player.GetPlayerPosX()) + (enemy[i].GetEnemyBullet()[j].GetEnemyBulletPosY() - player.GetPlayerPosY()) * (enemy[i].GetEnemyBullet()[j].GetEnemyBulletPosY() - player.GetPlayerPosY());

				if (enemy[i].GetEnemyBullet()[j].GetIsEnemyBulletShot() == true && player.GetPlayerIsAlive() == true && player.GetPlayerAvoid() == false)
				{
					if ((enemy[i].GetEnemyBullet()[j].GetEnemyBulletRadius() + player.GetPlayerRadius()) * (enemy[i].GetEnemyBullet()[j].GetEnemyBulletRadius() + player.GetPlayerRadius()) >= enemyBulletDistance) //敵の弾が自機に当たる判定
					{
						enemy[i].GetEnemyBullet()[j].EnemyReceiveBulletOnColision();
						player.PlayerOnColision();
					}
				}
			}

		}
		//----------------------------------------------------
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				 playerEllipseBulletDistance = (player.GetPlayerBullet()[j].GetPlayerBulletPosX() - ellipseEnemy[i].GetEnemyPosX()) * (player.GetPlayerBullet()[j].GetPlayerBulletPosX() - ellipseEnemy[i].GetEnemyPosX()) + (player.GetPlayerBullet()[j].GetPlayerBulletPosY() - ellipseEnemy[i].GetEnemyPosY()) * (player.GetPlayerBullet()[j].GetPlayerBulletPosY() - ellipseEnemy[i].GetEnemyPosY());


				if (ellipseEnemy[i].GetEnemyIsAlive() == true && player.GetPlayerBullet()[j].GetPlayerIsBulletShot() == true)
				{
					if (player.GetPlayerBullet()[j].GetPlayerBulletRadius() + ellipseEnemy[i].GetEnemyRadius() * player.GetPlayerBullet()[j].GetPlayerBulletRadius() + ellipseEnemy[i].GetEnemyRadius() >= playerEllipseBulletDistance)
					{
						score += 100;
						ellipseEnemy[i].EnemyOnColision();
						player.GetPlayerBullet()[j].BulletReceiveOnColision();
					}
				}
			}
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				enemyEllipseBulletDistance = (ellipseEnemy[i].GetEnemyBullet()[j].GetEnemyEllipseBulletPosX() - player.GetPlayerPosX()) * (ellipseEnemy[i].GetEnemyBullet()[j].GetEnemyEllipseBulletPosX() - player.GetPlayerPosX()) + (ellipseEnemy[i].GetEnemyBullet()[j].GetEnemyEllipseBulletPosY() - player.GetPlayerPosY()) * (ellipseEnemy[i].GetEnemyBullet()[j].GetEnemyEllipseBulletPosY() - player.GetPlayerPosY());

				if (ellipseEnemy[i].GetEnemyBullet()[j].GetIsEnemyEllipseBulletShot() == true && player.GetPlayerIsAlive() == true && player.GetPlayerAvoid() == false)
				{
					if ((ellipseEnemy[i].GetEnemyBullet()[j].GetEnemyEllipseBulletRadius() + player.GetPlayerRadius()) * (ellipseEnemy[i].GetEnemyBullet()[j].GetEnemyEllipseBulletRadius() + player.GetPlayerRadius()) >= enemyEllipseBulletDistance) //敵の弾が自機に当たる判定
					{
						ellipseEnemy[i].GetEnemyBullet()[j].EnemyEllipseReceiveBulletOnColision();
						player.PlayerOnColision();
					}
				}
			
			}
		}

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				playerTriangleBulletDistance = (player.GetPlayerBullet()[j].GetPlayerBulletPosX() - triangleEnemy[i].GetEnemyPosX()) * (player.GetPlayerBullet()[j].GetPlayerBulletPosX() - triangleEnemy[i].GetEnemyPosX()) + (player.GetPlayerBullet()[j].GetPlayerBulletPosY() - triangleEnemy[i].GetEnemyPosY()) * (player.GetPlayerBullet()[j].GetPlayerBulletPosY() - triangleEnemy[i].GetEnemyPosY());


				if (triangleEnemy[i].GetEnemyIsAlive() == true && player.GetPlayerBullet()[j].GetPlayerIsBulletShot() == true)
				{
					if (player.GetPlayerBullet()[j].GetPlayerBulletRadius() + triangleEnemy[i].GetEnemyRadius() * player.GetPlayerBullet()[j].GetPlayerBulletRadius() + triangleEnemy[i].GetEnemyRadius() >= playerTriangleBulletDistance)
					{
						score += 100;
						triangleEnemy[i].EnemyOnColision();
						player.GetPlayerBullet()[j].BulletReceiveOnColision();
					}
				}
			}
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				enemyTriangleBulletDistance = (triangleEnemy[i].GetEnemyBullet()[j].GetEnemyTriangleBulletPosX() - player.GetPlayerPosX()) * (triangleEnemy[i].GetEnemyBullet()[j].GetEnemyTriangleBulletPosX() - player.GetPlayerPosX()) + (triangleEnemy[i].GetEnemyBullet()[j].GetEnemyTriangleBulletPosY() - player.GetPlayerPosY()) * (triangleEnemy[i].GetEnemyBullet()[j].GetEnemyTriangleBulletPosY() - player.GetPlayerPosY());

				if (triangleEnemy[i].GetEnemyBullet()[j].GetIsEnemyTriangleBulletShot() == true && player.GetPlayerIsAlive() == true && player.GetPlayerAvoid() == false)
				{
					if ((triangleEnemy[i].GetEnemyBullet()[j].GetEnemyTriangleBulletRadius() + player.GetPlayerRadius()) * (triangleEnemy[i].GetEnemyBullet()[j].GetEnemyTriangleBulletRadius() + player.GetPlayerRadius()) >= enemyTriangleBulletDistance) //敵の弾が自機に当たる判定
					{
						triangleEnemy[i].GetEnemyBullet()[j].EnemyTriangleReceiveBulletOnColision();
						player.PlayerOnColision();
					}
				}

			}
		}
			///
			/// ↑更新処理ここまで
			///

			///
			/// ↓描画処理ここから
			///
		player.Draw();
		for (int i = 0; i < 5; i++)
		{
			/*enemy[i].Draw();*/
			ellipseEnemy[i].Draw();
		/*	triangleEnemy[i].Draw();*/
		}
		scene.Draw();
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