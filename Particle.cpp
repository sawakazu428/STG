#include "Particle.h"

void Particle::Initialize()
{
	particlePosX_ = 0;
	particlePosY_ = 0;
	particleSpeedX_ = 3;
	particleSpeedY_ = 3;
	particleRadius_ = 4;
	particleCrush_ = false;
}

void Particle::Update()
{
	particlePosX_ += particleSpeedX_;
	particlePosY_ += particleSpeedY_;	
}

void Particle::DrawEllipse()
{
	Novice::DrawEllipse(particlePosX_, particlePosY_, particleRadius_, particleRadius_, 0.0f, WHITE, kFillModeSolid);
}

void Particle::DrawBox()
{
	Novice::DrawBox(particlePosX_, particlePosY_, particleRadius_, particleRadius_, 0.0f, WHITE, kFillModeSolid);
}

void Particle::Setpaticle(int posX, int posY, int speedX, int speedY)
{
	particlePosX_ = posX;
	particlePosY_ = posY;
	particleSpeedX_ = speedX;
	particleSpeedY_ = speedY;
	particleCrush_ = true;
}

void Particle::ParticleOnColision()
{
	particleCrush_ = false;
}
