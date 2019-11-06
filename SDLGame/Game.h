#pragma once

#include "SDL.h"
#include "TextureManager.h"
#include <iostream>
#include <SDL_image.h>
#include <vector>
#include "Menu.h"

class Game {

public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	bool setupGame();

	void handleEvents();
	void update();
	void render();
	void clean();
	SDL_Window* getWindow();

	static void setGoToMenu();

	bool running() { return isRunning;}

private:

	int cntr;
	int points;
	int score;
	int highScore;
	int truth;
	int cnt = 0;
	bool isRunning;
	bool menu;
	Menu* menuScreen;
	SDL_Window *window;
	SDL_Renderer *renderer;
};
