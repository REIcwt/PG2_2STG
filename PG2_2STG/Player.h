#pragma once
#include "Struct.h"
#include "Bullet.h"

class Player {
public:
	Vector2 pos_;
	int radius_;
	int speed_;
	int isAlive_;

public:
	Bullet bullet_;
	Player();

	int GetPosX() { return pos_.x; };
	int GetPosY() { return pos_.y; };

	void Draw();
	void Update(char* keys, char* prekeys);
};