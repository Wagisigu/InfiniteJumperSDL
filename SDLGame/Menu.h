#pragma once
#include <SDL.h>

class Menu {

public:

	Menu(SDL_Renderer* ren, SDL_Window* win);

	~Menu();

	void render();

	void handleEvents();

	bool continues();

private:
	
	int mouseX, mouseY;
	bool menu;
	bool isRunning;
	SDL_Renderer* renderer;
	SDL_Window* window;
	SDL_Texture* start;
	SDL_Rect srcRect, destRect;

};