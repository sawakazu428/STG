//#include "SceneManeger.h"
#include <Novice.h>
#include "Player.h"
#include "Enemy.h"
#include "EliipseEnemy.h"
#include "TriangleEnemy.h"
#include "BossEnemy.h"
#include "Scene.h"
const char kWindowTitle[] = "Try Shooting";

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
		ellipseEnemy[i].Initialize(2200, 160 + (i * 200));
	}

	TriangleEnemy triangleEnemy[5]{};
	for (int i = 0; i < 3; i++)
	{
		triangleEnemy[i].Initialize(3220 + (-i * 50), 160 + (i * 50));
	}

	for (int i = 3; i < 5; i++)
	{
		triangleEnemy[i].Initialize(3000 + (i * 50), 160 + (i * 50));
	}
	BossEnemy bossEnemy;

	bossEnemy.Initialize(4500,360, 4500, 360, 4500, 360);
	//SceneManeger sceneManeger;

	//sceneManeger.ChangeScene(sceneManeger.TITLE);

	
	//Scene scene;

	//scene.Initialize();
	//int red = scene.GetRed_();
	//int green = scene.GetGreen_();
	//int blue = scene.GetBlue_();
	//int alpha = scene.GetAlpha_();

	int flag = false;

	int playerBulletDistance;
	int playerEllipseBulletDistance;
	int playerTriangleBulletDistance;
	int playerBossBulletDistance;

	int enemyBulletDistance;
	int enemyEllipseBulletDistance;
	int enemyTriangleBulletDistance;
	int enemyBossBulletDistance;
	int enemyBossBulletDistance1;
	int enemyBossBulletDistance2;

	int TryShooting = Novice::LoadTexture("./Resources/Try Shooting.png");
	int O = Novice::LoadTexture("./Resources/O.png");
	int manual = Novice::LoadTexture("./Resources/manual.png");
	int title = Novice::LoadTexture("./Resources/EnterKey.png");
	
	int manualSelect = Novice::LoadTexture("./Resources/stageSelect NEW.png");
	
	int backGround = Novice::LoadTexture("./Resources/shape back ground.png");
	
	int result = Novice::LoadTexture("./Resources/SPACE to TITLE.png");
	int gameover = Novice::LoadTexture("./Resources/GAMEOVER.png");


	// ワールド座標の左端から右端にかけての変数
	int scrollX;
	// 背景描画の動いている変数の速度
	int scenespeed = 3;
	// 背景描画の動いている変数
	int scenePosX = 0;


	int score = 0;

	enum Scene
	{
		TITLE,
		MANUAL,
		GAME,
		RESULT
	};
	Scene scene = Scene::TITLE;

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
		
		//sceneManeger.Update();

		//if (keys[DIK_RETURN])
		//{
		//	sceneManeger.ChangeScene(sceneManeger.GAME);
		//	//gameScene.Update();
		//}
		//	
		//	
	
		//if (keys[DIK_BACKSPACE])
		//{
		//	sceneManeger.ChangeScene(sceneManeger.TITLE);
		//}

		switch (scene)
		{
		case TITLE:

			if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0)
			{
				scene = GAME;
			}
			if (keys[DIK_O] && preKeys[DIK_O] == 0)
			{
				scene = MANUAL;
			}
			scrollX = 0;

			score = 0;

			player.Initialize();

			playerbullet.Initialize();


			for (int i = 0; i < 5; i++)
			{
				enemy[i].Initialize(1300 + (i + 1) * 100, 160 + (i + 1) * 100);
			}


			for (int i = 0; i < 3; i++)
			{
				ellipseEnemy[i].Initialize(3020, 160 + (i * 200));
			}


			for (int i = 0; i < 3; i++)
			{
				triangleEnemy[i].Initialize(4000 + (-i * 50), 160 + (i * 100));
			}

			for (int i = 3; i < 5; i++)
			{
				triangleEnemy[i].Initialize(3850 + (i * 50), 160 + (i * 100));
			}
			bossEnemy.Initialize(1350, 360, 1350, 360, 1350, 360);

			break;
		case MANUAL:

			if (keys[DIK_M] && preKeys[DIK_M] == 0)
			{
				scene = TITLE;
			}
			break;
		case GAME:
			if (keys[DIK_BACKSPACE])
			{
				scene = TITLE;
			}

			if (scrollX <= 19200)
			{
				scrollX = scrollX + scenespeed;
			}

			if (scene == GAME)
			{
				scenePosX = scenePosX - scenespeed;
			}
			if (scenePosX <= -1280)
			{
				scenePosX = scenePosX + 1280;
			}

			if (keys[DIK_Q])
			{
				flag = true;
			}
			if (flag == true)
			{
				//red++;

			}
			//scene.SetDrawBright(red, green, blue, alpha); // 試行段階(まだできてない)
			//if (red == 255 || green == 255 || blue == 255 || alpha == 255)
			//{
			//	flag = false;
			//}
			//scene.Update();

			player.Move(keys, preKeys);

			player.Update(keys, preKeys);

			if (scrollX >= 6000)
			{
				bossEnemy.Move();
			}
			bossEnemy.Update();
			for (int i = 0; i < 5; i++)
			{
				enemy[i].Update();

				enemy[i].Move();
				ellipseEnemy[i].Update();

				ellipseEnemy[i].Move();

				triangleEnemy[i].Update();

				triangleEnemy[i].Move();
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

					if (enemy[i].GetEnemyBullet()[j].GetIsEnemyBulletShot() == true && player.GetPlayerIsAlive() == true && player.GetPlayerAvoid() == false && enemy[i].GetEnemyIsAlive() == true)
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
							score += 120;
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

					if (ellipseEnemy[i].GetEnemyBullet()[j].GetIsEnemyEllipseBulletShot() == true && player.GetPlayerIsAlive() == true && player.GetPlayerAvoid() == false&& ellipseEnemy[i].GetEnemyIsAlive() == true)
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
							score += 150;
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

					if (triangleEnemy[i].GetEnemyBullet()[j].GetIsEnemyTriangleBulletShot() == true && player.GetPlayerIsAlive() == true && player.GetPlayerAvoid() == false&& triangleEnemy[i].GetEnemyIsAlive() == true)
					{
						if ((triangleEnemy[i].GetEnemyBullet()[j].GetEnemyTriangleBulletRadius() + player.GetPlayerRadius()) * (triangleEnemy[i].GetEnemyBullet()[j].GetEnemyTriangleBulletRadius() + player.GetPlayerRadius()) >= enemyTriangleBulletDistance) //敵の弾が自機に当たる判定
						{
							triangleEnemy[i].GetEnemyBullet()[j].EnemyTriangleReceiveBulletOnColision();
							player.PlayerOnColision();
						}
					}

				}
			}

			//---------------------------------------------------------------
			if (bossEnemy.GetBossEnemyMove() == false)
			{
				for (int j = 0; j < 20; j++)
				{
					playerBossBulletDistance = (player.GetPlayerBullet()[j].GetPlayerBulletPosX() - bossEnemy.GetBossEnemyPosX()) * (player.GetPlayerBullet()[j].GetPlayerBulletPosX() - bossEnemy.GetBossEnemyPosX()) + (player.GetPlayerBullet()[j].GetPlayerBulletPosY() - bossEnemy.GetBossEnemyPosY()) * (player.GetPlayerBullet()[j].GetPlayerBulletPosY() - bossEnemy.GetBossEnemyPosY());


					if (bossEnemy.GetBossEnemyIsAlive() == true && player.GetPlayerBullet()[j].GetPlayerIsBulletShot() == true)
					{
						if (player.GetPlayerBullet()[j].GetPlayerBulletRadius() + bossEnemy.GetBossEnemyRadius() * player.GetPlayerBullet()[j].GetPlayerBulletRadius() + bossEnemy.GetBossEnemyRadius() >= playerBossBulletDistance)
						{
							bossEnemy.EnemyOnColision();
							player.GetPlayerBullet()[j].BulletReceiveOnColision();
						}
					}
				}
			}
			
			for (int j = 0; j < 20; j++)
			{
				enemyBossBulletDistance = (bossEnemy.GetEnemyBullet()[j].GetEnemyBossBulletPosX() - player.GetPlayerPosX()) * (bossEnemy.GetEnemyBullet()[j].GetEnemyBossBulletPosX() - player.GetPlayerPosX()) + (bossEnemy.GetEnemyBullet()[j].GetEnemyBossBulletPosY() - player.GetPlayerPosY()) * (bossEnemy.GetEnemyBullet()[j].GetEnemyBossBulletPosY() - player.GetPlayerPosY());

				if (bossEnemy.GetEnemyBullet()[j].GetIsEnemyBossBulletShot() == true && player.GetPlayerIsAlive() == true && player.GetPlayerAvoid() == false && bossEnemy.GetBossEnemyIsAlive() == true)
				{
					if ((bossEnemy.GetEnemyBullet()[j].GetEnemyBossBulletRadius() + player.GetPlayerRadius()) * (bossEnemy.GetEnemyBullet()[j].GetEnemyBossBulletRadius() + player.GetPlayerRadius()) >= enemyBossBulletDistance) //敵の弾が自機に当たる判定
					{
						bossEnemy.GetEnemyBullet()[j].EnemyBossReceiveBulletOnColision();
						player.PlayerOnColision();
					}
				}
			}
			for (int j = 0; j < 20; j++)
			{
				enemyBossBulletDistance1 = (bossEnemy.GetEnemyBullet()[j].GetEnemyBossBulletPosX1() - player.GetPlayerPosX()) * (bossEnemy.GetEnemyBullet()[j].GetEnemyBossBulletPosX1() - player.GetPlayerPosX()) + (bossEnemy.GetEnemyBullet()[j].GetEnemyBossBulletPosY1() - player.GetPlayerPosY()) * (bossEnemy.GetEnemyBullet()[j].GetEnemyBossBulletPosY1() - player.GetPlayerPosY());
				
				if (bossEnemy.GetEnemyBullet()[j].GetIsEnemyBossBulletShot1() == true && player.GetPlayerIsAlive() == true && player.GetPlayerAvoid() == false && bossEnemy.GetBossEnemyIsAlive() == true)
				{
					if ((bossEnemy.GetEnemyBullet()[j].GetEnemyBossBulletRadius() + player.GetPlayerRadius()) * (bossEnemy.GetEnemyBullet()[j].GetEnemyBossBulletRadius() + player.GetPlayerRadius()) >= enemyBossBulletDistance1) //敵の弾が自機に当たる判定
					{
						bossEnemy.GetEnemyBullet()[j].EnemyBossReceiveBulletOnColision1();
						player.PlayerOnColision();
					}
				}
			}
			for (int j = 0; j < 20; j++)
			{
				enemyBossBulletDistance2 = (bossEnemy.GetEnemyBullet()[j].GetEnemyBossBulletPosX2() - player.GetPlayerPosX()) * (bossEnemy.GetEnemyBullet()[j].GetEnemyBossBulletPosX2() - player.GetPlayerPosX()) + (bossEnemy.GetEnemyBullet()[j].GetEnemyBossBulletPosY2() - player.GetPlayerPosY()) * (bossEnemy.GetEnemyBullet()[j].GetEnemyBossBulletPosY2() - player.GetPlayerPosY());

				if (bossEnemy.GetEnemyBullet()[j].GetIsEnemyBossBulletShot2() == true && player.GetPlayerIsAlive() == true && player.GetPlayerAvoid() == false && bossEnemy.GetBossEnemyIsAlive() == true)
				{
					if ((bossEnemy.GetEnemyBullet()[j].GetEnemyBossBulletRadius() + player.GetPlayerRadius()) * (bossEnemy.GetEnemyBullet()[j].GetEnemyBossBulletRadius() + player.GetPlayerRadius()) >= enemyBossBulletDistance2) //敵の弾が自機に当たる判定
					{
						bossEnemy.GetEnemyBullet()[j].EnemyBossReceiveBulletOnColision2();
						player.PlayerOnColision();
					}
				}
			}

			if (player.GetPlayerHitPoint() == 0)
			{
				scene = RESULT;
			}
			if (bossEnemy.GetBossEnemyRespawnCount() <= 0)
			{
				score += 1000;
				scene = RESULT;
			}
			break;
			case RESULT:
				player.GetPlayerHitPoint() * 500 + score;
				if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)
				{
					scene = TITLE;
				}
			break;
		}
			///
			/// ↑更新処理ここまで
			///

			///
			/// ↓描画処理ここから
			///
			
			//gameScene.Draw();
			//sceneManeger.Render();

		switch (scene)
		{
		case TITLE:
			//Novice::DrawBox(0, 0, 1280, 720, 0.0f, WHITE, kFillModeSolid);
			Novice::DrawSprite(320,100, TryShooting, 1.5, 1.5, 0.0f, 0xFFFFFFFF);
			Novice::DrawSprite(220, 400, title, 1, 1, 0.0f, 0xFFFFFFFF);
			Novice::DrawSprite(1020,0, manual, 1, 1, 0.0f, 0xFFFFFFFF);
			Novice::DrawSprite(950, 0, O, 1, 1, 0.0f, 0xFFFFFFFF);
			break;
		case MANUAL:
			Novice::DrawSprite(0,00, manualSelect, 1, 1, 0.0f, 0xFFFFFFFF);

			break;
		case GAME:
			Novice::DrawSprite(scenePosX, 0, backGround, 1, 1, 0.0f, 0xFFFFFFFF);
			Novice::DrawSprite(scenePosX + 1280, 0, backGround, 1, 1, 0.0f, 0xFFFFFFFF);
			Novice::ScreenPrintf(1200, 0, "score %d", score);

			player.Draw();
			bossEnemy.Draw();
			for (int i = 0; i < 5; i++)
			{
				enemy[i].Draw();
				ellipseEnemy[i].Draw();
				triangleEnemy[i].Draw();
			}
			break;
		case RESULT:
			Novice::DrawBox(0, 0, 1290, 730, 0.0f,BLACK, kFillModeSolid);
			Novice::DrawSprite(100, 0, result, 1, 1, 0.0f, 0xFFFFFFFF);
			Novice::DrawSprite(220, 100, gameover, 1.5, 1.5, 0.0f, 0xFFFFFFFF);
			Novice::ScreenPrintf(430, 250, "score = %d", score);
			Novice::ScreenPrintf(430, 300, "Player HP %d * 500 + score = %d", player.GetPlayerHitPoint(), player.GetPlayerHitPoint() * 500 + score);

			break;
	
		}
			
		
		//scene.Draw();
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