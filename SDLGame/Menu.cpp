#include "Menu.h"
#include "TextureManager.h"

Menu::Menu(SDL_Renderer* ren, SDL_Window* win) {
	isRunning = true;
	menu = true;
	srcRect.x = 4;
	srcRect.w = 8;
	srcRect.y = 0;
	srcRect.h = 14;
	destRect.x = SDL_GetWindowSurface(win)->w / 2 - 32;
	destRect.y = SDL_GetWindowSurface(win)->h / 2 - 32;
	destRect.w = 66;
	destRect.h = 100;
	renderer = ren;
	window = win;
	start = TextureManager::LoadTexture("assets/icons/book4.png", ren);
	while (menu) {
		handleEvents();
		render();
	}
}

Menu::~Menu() {

}

void Menu::render() {

	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, start, &srcRect, &destRect);

	SDL_RenderPresent(renderer);
}

void Menu::handleEvents() {
	SDL_Event(event);
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_MOUSEBUTTONDOWN:
		mouseX = event.motion.x;
		mouseY = event.motion.y;

		if (mouseX <= SDL_GetWindowSurface(window)->w / 2 + 33 && mouseX >= SDL_GetWindowSurface(window)->w / 2 - 33 &&
			mouseY <= SDL_GetWindowSurface(window)->h / 2 + 50 && mouseY >= SDL_GetWindowSurface(window)->w / 2 - 50) {
			menu = false;
		}

		break;
	case SDL_QUIT:
		menu = false;
		isRunning = false;
		break;
	default:
		break;
	}
}

bool Menu::continues() {
	return isRunning;
}