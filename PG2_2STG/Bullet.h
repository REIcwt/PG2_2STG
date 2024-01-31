#pragma once
#include "Struct.h"

class Bullet {
public:
	Vector2 pos_;
	int radius_;
	int speed_;
	int isShootFlag_;

public:
	Bullet();
	void Update();
	void Draw();
};
