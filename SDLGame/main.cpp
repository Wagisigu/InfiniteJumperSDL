#include "Game.h"

Game *game = nullptr;

int main(int argc, char *argv[]) {

	const int FPS = 60;
	const int FRAME_DELAY = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;
	bool menu = true;

	game = new Game();

	game->init("BounceBitch", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 1600, false);

	while (game->running()) {

		frameStart = SDL_GetTicks();

		if (menu) {
			menu = game->setupGame();
		}

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (FRAME_DELAY > frameTime) {
			SDL_Delay(FRAME_DELAY);
		}
	}
	game->clean();

	return 0;
}