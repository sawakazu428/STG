#include "Scene.h"

void Scene::Initialize()
{
	red_ = 0x00;
	green_ = 0x00;
	blue_ = 0x00;
	alpha_ = 0x00;
	r_ = 0x00;
	g_ = 0x00;
	b_ = 0x00;
	a_ = 0x00;
	color_ = 0x00000000;
}

void Scene::Update()
{
	SetDrawBright(r_, g_, b_, a_);
}

unsigned int Scene::SetDrawBright(int r, int g, int b, int a)
{
	r_ = r <<= 24;
	g_ = g <<= 16;
	b_ = b <<= 8;
	a_ = a;

	return color_ =  r_ | g_ | b_ | a_;
}

void Scene::Draw()
{
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, color_, kFillModeSolid);
	Novice::ScreenPrintf(0, 20, "%d", r_);

}


