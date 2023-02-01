#pragma once
#include "Novice.h"
#include "EnemyBullet.h"
#include "Particle.h"
class BoxEnemy
{
	private:
	int enemyPosX_;              // �{�b�N�X�G�l�~�[�̍��WX
	int enemyPosY_;		         // �{�b�N�X�G�l�~�[�̍��WY
	int enemySpeedX_;	         // �{�b�N�X�G�l�~�[�̃X�s�[�hX
	int enemySpeedY_;	         // �{�b�N�X�G�l�~�[�̃X�s�[�hY
	int enemyRadius_;	         // �{�b�N�X�G�l�~�[�̔��a
	int enemyHP_;		         // �{�b�N�X�G�l�~�[��HP
	bool enemyIsAlive_;	         // �{�b�N�X�G�l�~�[�̕`��

	bool enemyExplosion_;        // �{�b�N�X�G�l�~�[�̔����t���O
	float enemyRespawnCount_;    // �{�b�N�X�G�l�~�[�̃��X�|�[������܂ł̃J�E���g

	int delayFrameBulletEnemy_;  // �{�b�N�X�G�l�~�[�̒e�����Ԋu��ۑ�����ϐ�
	int enemyDelayFrameBullet_;  // �{�b�N�X�G�l�~�[�̒e�����Ԋu
	int enemyPoint_;             // �{�b�N�X�G�l�~�[�̕`��   
	int drawExplosion1_[6];      // �{�b�N�X�G�l�~�[�̌��j���̕`��
	
	int particleRandX_;
	int particleRandY_;
	BoxEnemyBullet enemyBullet_[20]; // �{�b�N�X�G�l�~�[�̒e�̊Ǘ�����ϐ�
	Particle particle_[15];
public:
	
	/// <summary>
	/// �������֐�
	/// </summary>
	/// <param name="x"></param> ���WX
	/// <param name="y"></param> ���WY
	void Initialize(int x,int y);

	/// <summary>
	/// �X�V�֐�
	/// </summary>
	void Update();
	/// <summary>
	/// �ړ��ϐ�
	/// </summary>
	void Move();

	/// <summary>
	/// �`��֐�
	/// </summary>
	void Draw();

	/// <summary>
	/// ���j���ꂽ���̊֐�
	/// </summary>
	void EnemyOnColision();

	/// <summary>
	/// �e��Get����ׂ̊֐� + ���j���̃p�[�e�B�N���̊֐� + Get�֐��B
	/// </summary>
	/// <returns></returns>
	BoxEnemyBullet* GetEnemyBullet() { return enemyBullet_; }

	//Particle* GetPaticle() { return particle_; }
	int GetEnemyPosX() { return enemyPosX_; };
	int GetEnemyPosY() { return enemyPosY_; };
	int GetEnemySpeedX() { return enemySpeedX_; };
	int GetEnemySpeedY() { return enemySpeedY_; };
	int GetEnemyRadius() { return enemyRadius_; };
	int GetEnemyIsAlive() { return enemyIsAlive_; };
};
