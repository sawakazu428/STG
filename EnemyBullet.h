#pragma once
#include "Novice.h"
class BoxEnemyBullet
{
private:
	int enemyBulletPosX_;    // �{�b�N�X�G�l�~�[�̒e�̍��WX
	int enemyBulletPosY_;    // �{�b�N�X�G�l�~�[�̒e�̍��WY
	int enemyBulletRadius_;  // �{�b�N�X�G�l�~�[�̒e�̔��a
	int enemyBulletSpeedX_;  // �{�b�N�X�G�l�~�[�̒e�̃X�s�[�hX
	int enemyBulletSpeedY_;  // �{�b�N�X�G�l�~�[�̒e�̃X�s�[�hY
	int enemyBulletNum_;     // �{�b�N�X�G�l�~�[�̒e�̐�
	bool isEnemyBulletShot_; // �{�b�N�X�G�l�~�[�̒e�̃t���O
	int drawEnemyBullet_;    // �{�b�N�X�G�l�~�[�̒e�̕`��
public:
	/// <summary>
	/// �������֐�
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V�֐�
	/// </summary>
	void Update();

	/// <summary>
	/// �`��֐�
	/// </summary>
	void Draw();

	/// <summary>
	/// �Q�b�g�֐��B
	/// </summary>
	/// <returns></returns>
	int GetEnemyBulletPosX() { return enemyBulletPosX_; };
	int GetEnemyBulletPosY() { return enemyBulletPosY_; };
	int GetEnemyBulletRadius() { return enemyBulletRadius_; };
	int GetIsEnemyBulletShot() { return isEnemyBulletShot_; };

	/// <summary>
	/// �Z�b�g�֐��@// �e�ƃv���C���[�̈ʒu�����킹��
	/// </summary>
	/// <param name="posX"></param>   
	/// <param name="posY"></param>   
	/// <param name="speedX"></param>
	/// <param name="speedY"></param>
	/// <param name="radius"></param>
	void SetEnemyBulletInfo(int posX, int posY, int speedX, int speedY, int radius);

	/// <summary>
	/// �e�������������̊֐�
	/// </summary>
	void EnemyBulletOnColision();


	/// <summary>
	/// �e�𓖂Ă�ꂽ���̊֐�
	/// </summary>
	void EnemyReceiveBulletOnColision();
};

