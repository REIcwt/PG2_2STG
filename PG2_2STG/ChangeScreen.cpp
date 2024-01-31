#include "ChangeScreen.h"
#include "Novice.h"


void Screen::Update(char* keys, char* prekeys) {

	if (sceneNum==0) {
		if (keys[DIK_RETURN] && prekeys[DIK_RETURN]) {
			sceneNum = 1;
		}
	}
	if (sceneNum == 1) {
		if (keys[DIK_Q] && prekeys[DIK_Q]) {
			sceneNum = 0;
		}
	}
	if (sceneNum == 2) {
		if (keys[DIK_RETURN] && prekeys[DIK_RETURN]) {
			sceneNum = 0;
		}
	}
}

void Screen::Draw(){

	if (sceneNum == 0) {
		Novice::DrawBox(0, 0, 1280, 720, 0, BLACK, kFillModeSolid);
		Novice::ScreenPrintf(580, 350, "GAME START : ENTER key");
	}
	if (sceneNum == 1) {
		Novice::DrawBox(0, 0, 1280, 720, 0, BLACK, kFillModeSolid);
		Novice::ScreenPrintf(0, 0, "Back to title: Q");
	}
	if (sceneNum == 2) {
		Novice::DrawBox(0, 0, 1280, 720, 0, BLACK, kFillModeSolid);
		Novice::ScreenPrintf(580, 350, "GAME OVER : ENTER key");
	}
}
