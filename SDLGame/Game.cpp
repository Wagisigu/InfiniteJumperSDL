#include "Game.h"
#include "BouncingObject.h"
#include "Player.h"
#include "Platform.h"

BouncingObject* bouncyBook1,* bouncyBook2,* bouncyBook3,* bouncyBook4;
Player* player;
Platform* platform1,* platform2,* platform3;

std::vector <BouncingObject*> balls;
std::vector <Platform*> platforms;

bool goToMenu;

Game::Game() {
	
}
Game::~Game() {

}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {

	menu = true;
	int flags = 0;

	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialized!..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window) {
			std::cout << "Window Created!..." << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 0, 181, 204, 1);
			std::cout << "Renderer Created!..." << std::endl;
		}

		isRunning = true;

	}
	else {
		isRunning = false;
	}
}

bool Game::setupGame() {
	menuScreen = new Menu(renderer, window);
	isRunning = menuScreen->continues();
	delete menuScreen;
	points = 0;
	score = 0;
	cntr = 0;

	player = new Player("assets/Sora Trials.png", window, renderer, 0,
		(SDL_GetWindowSurface(window)->h) - 112, 112, 110, 56, 55, 0, 0);

	for (int i = 1; i < 10; i++) {
		platforms.push_back(new Platform("assets/blackSquare.png", window, renderer, rand()%1100+1,
			(SDL_GetWindowSurface(window)->h) - i*200, 40, 250, 16, 16, 0, 0));
	}

	return false;
}

void Game::handleEvents() {
	SDL_Event(event);
	SDL_PollEvent(&event);
	
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;

	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_LEFT:
			player->playerMoveLeft = true;
			break;
		case SDLK_RIGHT:
			player->playerMoveRight = true;
			break;
		case SDLK_UP:
			player->jump();
			break;
		case SDLK_DOWN:
			break;
		default:
			break;
		}
		break;

	case SDL_KEYUP:
		switch (event.key.keysym.sym) {
		case SDLK_LEFT:
			player->playerMoveLeft = false;
			break;
		case SDLK_RIGHT:
			player->playerMoveRight = false;
			player->setSrcY(0);
			player->setSrcX(0);
			break;
		case SDLK_UP:
			break;
		case SDLK_DOWN:
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}
}

void Game::update() {
	truth = 0;
	for (int i = 0; i < platforms.size(); i++) {
		truth += platforms.at(i)->update(player);
	}
	if (truth > 0) {
		player->setGrounded(true);
	}
	else {
		player->resetGround();
		player->setGrounded(false);
	}
	player->update();
	if (goToMenu) {
		if (score > highScore) {
			highScore = score;
		}
		std::cout << "Highscore: " << highScore << std::endl;
		platforms.clear();
		setupGame();
		goToMenu = false;
	}
	if (player->getHasBegun()) {
		points++;
		if (points % 60 == 0) {
			score++;
			points = 0;
			std::cout << score << " points\n";
		}
	}
}

void Game::render() {
	SDL_RenderClear(renderer);
	for (int i = 0; i < platforms.size(); i++) {
		platforms.at(i)->render();
	}
	player->render();
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned!..." << std::endl;
}

SDL_Window* Game::getWindow() {
	return window;
}

void Game::setGoToMenu() {
	goToMenu = true;
}