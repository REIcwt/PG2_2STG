#define _USE_MATH_DEFINES
#include <math.h>
#include "Enemy.h"
#include "Novice.h"

Enemy::Enemy(int posX, int posY, int speedX, int speedY, int isAlive,int rsTimer) {
	pos_.x = posX;
	pos_.y = posY;
	speed_.x = speedX;
	speed_.y = speedY;
	radius_ = 20;
	isAlive_ = isAlive;
	respawn_ = rsTimer;
}

Enemy::~Enemy() {
}

int Enemy::Collision(int bulletPosX, int bulletPosY, int enemyPosX, int enemyPosY) {
	int dis;
	dis = int(((bulletPosX - enemyPosX) * (bulletPosX - enemyPosX)) + ((bulletPosY - enemyPosY) * (bulletPosY - enemyPosY)));
	return dis;
}

void Enemy::Update() {
	pos_.x += speed_.x;

	if (pos_.x - radius_ <= 0 || pos_.x + radius_ >= 1280) {
		speed_.x *= -1;
	}
}

void Enemy::Respawm(int timer) {
	respawn_++;
	if (respawn_ >=timer){
		respawn_ = 0;
		isAlive_ = 1;
	}
}

void Enemy::Draw() {
	Novice::DrawEllipse(int(pos_.x), int(pos_.y), radius_, radius_, 0.0f, RED, kFillModeSolid);
}