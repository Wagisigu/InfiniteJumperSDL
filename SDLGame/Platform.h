#pragma once
#include <SDL.h>
#include "GameObject.h"
#include "Player.h"

class Platform : public GameObject {

public:

	Platform(const char* filename, SDL_Window* win, SDL_Renderer* ren, int startPosX, int startPosY,
		int objectHeight, int objectWidth, int selectionHeight, int selectionWidth, int selectionPositionX, int selectionPositionY);

	~Platform();

	int update(Player* other);

private:

	int truth;
	bool land;
	SDL_Texture* platform;
	SDL_Window* window;

};