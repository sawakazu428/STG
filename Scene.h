#pragma once
#include "Novice.h"
class Scene
{
private:
	int red_;
	int blue_;
	int green_;
	int alpha_;
	int r_;
	int b_;
	int g_;
	int a_;
    int color_;
public:
	void Initialize();

	void Update();

	void Draw();

	unsigned int SetDrawBright(int r, int g,int b ,int a);

	int GetRed_() { return red_; };
	int GetGreen_() { return green_; };
	int GetBlue_() { return blue_; };
	int GetAlpha_() { return alpha_; };

};

