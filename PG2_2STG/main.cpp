#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "ChangeScreen.h"

const char kWindowTitle[] = "SHOOTING";


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Screen* screen = new Screen();

	Player* player = new Player();

	Enemy* enemyA = new Enemy(100, 100, 4, 0, 1,100);
	Enemy* enemyB = new Enemy(100, 300, 4, 0, 1,100);

	
	int respawn = 100;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		
		screen->Update(keys, preKeys);

		if (screen->sceneNum == 0) {
			player->isAlive_ = 1;
			player->pos_.x = 640;
			player->pos_.y = 360;
			enemyA->isAlive_ = 1;
			enemyB->isAlive_ = 1;
		}

		enemyA->Update();
		enemyB->Update();

		if (screen->sceneNum == 1) {
			if (player->isAlive_ == 1) {
				player->Update(keys, preKeys);

				if (enemyA->Collision(player->pos_.x, player->pos_.y, enemyA->GetPosX(), enemyA->GetPosY()) <= (enemyA->GetRadius() + player->radius_) * (enemyA->GetRadius() + player->radius_) && enemyA->isAlive_ == 1) {
					player->isAlive_ = 0;
				}

				if (enemyB->Collision(player->pos_.x, player->pos_.y, enemyB->GetPosX(), enemyB->GetPosY()) <= (enemyB->GetRadius() + player->radius_) * (enemyB->GetRadius() + player->radius_) && enemyB->isAlive_ == 1) {
					player->isAlive_ = 0;
				}
			}


			if (enemyA->isAlive_ == 1) {
				if (enemyA->Collision(player->bullet_.pos_.x, player->bullet_.pos_.y, enemyA->GetPosX(), enemyA->GetPosY()) <= (enemyA->GetRadius() + player->bullet_.radius_) * (enemyA->GetRadius() + player->bullet_.radius_)) {
					enemyA->isAlive_ = 0;
				}
			}
			if (enemyB->isAlive_ == 1) {
				if (enemyB->Collision(player->bullet_.pos_.x, player->bullet_.pos_.y, enemyB->GetPosX(), enemyB->GetPosY()) <= (enemyB->GetRadius() + player->bullet_.radius_) * (enemyB->GetRadius() + player->bullet_.radius_)) {
					enemyB->isAlive_ = 0;
				}
			}

			

			if (enemyA->isAlive_ == 0) {
				enemyA->Respawm(respawn);
			}
			if (enemyB->isAlive_ == 0) {
				enemyB->Respawm(respawn);
			}

			if (player->isAlive_ == 0) {
				screen->sceneNum = 2;
			}

		}


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		screen->Draw();
		if (screen->sceneNum == 1) {
			player->Draw();

			if (enemyA->isAlive_ == 1) {
				enemyA->Draw();
			}
			if (enemyB->isAlive_ == 1) {
				enemyB->Draw();
			}
		}
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
