#pragma once
#include <Novice.h>
#include "Player.h"
#include "Enemy.h"
#include "EliipseEnemy.h"
#include "TriangleEnemy.h"
#include "Scene.h"

class BaseScene
{
public:
	Player player;

	PlayerBullet playerbullet;

	BoxEnemy enemy[5]{};

	EllipseEnemy ellipseEnemy[5]{};

	TriangleEnemy triangleEnemy[5]{};
	virtual void Update() = 0;
	virtual void Draw() = 0;
};

class TitleScene:public BaseScene
{
private:
	
public:
	void Update();
	void Draw();

};

class Gamescene :public BaseScene
{
private:
	
public:
	void Update();
	void Draw();
};

class ResultScene :public BaseScene
{
private:

public:
	void Update();
	void Draw();

};

class SceneManeger
{
private:
	static BaseScene* m_pScene;
public:
	enum SCENE
	{
		TITLE,
		GAME,
		RESULT
	};
	static void ChangeScene(SCENE scene);
	static void Update();
	static void Render();
};



