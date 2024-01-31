#pragma once
#include "Struct.h"
#include "Bullet.h"

class Enemy {
protected:
public:
	Enemy(int posX, int posY, int speedX, int speedY, int isAlive, int respawn_);
	~Enemy();

	Vector2 pos_;
	Vector2 speed_;
	int radius_;
	int isAlive_;
	int respawn_;

	int GetPosX() { return pos_.x; };
	int GetPosY() { return pos_.y; };

	int Collision(int bulletPosX, int bulletPosY, int enemyPosX, int enemyPosY);

	void Update();
	void Respawm(int timer);
	void Draw();
};