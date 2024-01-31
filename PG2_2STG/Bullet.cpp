#include "Novice.h"
#include "Bullet.h"

Bullet::Bullet() {
	pos_.x = -100;
	pos_.y = -100;
	radius_ = 10;
	speed_ = 10;
	isShootFlag_ = 0;
}

void Bullet::Update() {
	if (isShootFlag_ == 1) {
		pos_.y -= speed_;
	}
	if (pos_.y <= -radius_) {
		isShootFlag_ = 0;
	}
}

void Bullet::Draw() {
	Novice::DrawEllipse(pos_.x, pos_.y, radius_, radius_, 0, RED, kFillModeSolid);
}