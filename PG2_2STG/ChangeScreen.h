#pragma once

class Screen {
public:
	int sceneNum;

	void Update(char* keys, char* prekeys);
	void Draw();
};