#pragma once
#include "Novice.h"
class Particle
{
private:
	int particlePosX_;
	int particlePosY_;
	int particleSpeedX_;
	int particleSpeedY_;
	int particleRadius_;
	bool particleCrush_;
public:
	void Initialize();

	void Update();

	void DrawEllipse();

	void DrawBox();

	void Setpaticle(int posX, int posY, int speedX, int speedY);

	void ParticleOnColision();

	int GetParticleCrush_() { return particleCrush_; };
};

