#include "Novice.h"
#include "Player.h"

Player::Player() {
	pos_.x = 640;
	pos_.y = 360;
	radius_ = 20;
	speed_ = 5;
	isAlive_ = 1;
}


void Player::Update(char* keys, char* prekeys) {
	///-----MOVE-----\\\

	if (keys[DIK_W]) {
		pos_.y -= speed_;
	}
	if (keys[DIK_S]) {
		pos_.y += speed_;
	}
	if (keys[DIK_D]) {
		pos_.x += speed_;
	}
	if (keys[DIK_A]) {
		pos_.x -= speed_;
	}
	///-----SHOOT-----\\\

	if (bullet_.isShootFlag_ == 0) {
		bullet_.pos_.x = pos_.x;
		bullet_.pos_.y = pos_.y;
	}

	if (keys[DIK_SPACE] && prekeys[DIK_SPACE]) {
		bullet_.isShootFlag_ = 1;
	}

	bullet_.Update();
}

void Player::Draw() {
	if (isAlive_ == 1) {
		bullet_.Draw();
		Novice::DrawEllipse(pos_.x, pos_.y, radius_, radius_, 0, WHITE, kFillModeSolid);
	}
}