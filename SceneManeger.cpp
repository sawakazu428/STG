#include "SceneManeger.h"
BaseScene* SceneManeger::m_pScene = NULL;
void SceneManeger::ChangeScene(SCENE scene)
{
	switch (scene)
	{
	case SCENE::TITLE:
		m_pScene = new TitleScene();
		break;
	case SCENE::GAME:
		m_pScene = new Gamescene();
		break;
	case SCENE::RESULT:
		m_pScene = new ResultScene();
		break;
	default:
		break;
	}
}

void SceneManeger::Update()
{
	m_pScene->Update();
}

void SceneManeger::Render()
{
	m_pScene->Draw();
}

void TitleScene::Update()
{
	player.Initialize();
	playerbullet.Initialize();

	for (int i = 0; i < 5; i++)
	{
		enemy[i].Initialize(500 + (i + 1) * 100, 160 + (i + 1) * 100);
	}

	for (int i = 0; i < 3; i++)
	{
		ellipseEnemy[i].Initialize(820, 160 + (i * 200));
	}

	for (int i = 0; i < 3; i++)
	{
		triangleEnemy[i].Initialize(820 + (-i * 50), 160 + (i * 100));
	}

	for (int i = 3; i < 5; i++)
	{
		triangleEnemy[i].Initialize(620 + (i * 50), 160 + (i * 100));
	}
}

void TitleScene::Draw()
{
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);
}

void Gamescene::Update()
{
	for (int i = 0; i < 5; i++)
	{
		enemy[i].Update();

		enemy[i].Move();
		ellipseEnemy[i].Update();

		ellipseEnemy[i].Move();

		triangleEnemy[i].Update();

		triangleEnemy[i].Move();
	}
}



void Gamescene::Draw()
{
	player.Draw();
	for (int i = 0; i < 5; i++)
	{
		enemy[i].Draw();
		ellipseEnemy[i].Draw();
		triangleEnemy[i].Draw();
	}
}

void ResultScene::Update()
{
}

void ResultScene::Draw()
{
}


