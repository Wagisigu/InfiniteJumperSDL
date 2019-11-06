#include "Platform.h"
#include "TextureManager.h"

static bool move;

Platform::Platform(const char* filename, SDL_Window* win, SDL_Renderer* ren, int startPosX, int startPosY,
	int objectHeight, int objectWidth, int selectionHeight, int selectionWidth, int selectionPositionX, int selectionPositionY) :
	GameObject(filename, ren, startPosX, startPosY,
		objectHeight, objectWidth, selectionHeight, selectionWidth, selectionPositionX, selectionPositionY) {
	window = win;
	move = false;
}

int Platform::update(Player* other) {

	truth = 0;
	land = other->landing(this);
	if (land) {
		other->moveY(getPosY() - other->getHeight() + 3);
		other->setGround(getPosY() - other->getHeight() + 3);
		//other->setGrounded(true);
		truth = 1;
		move = true;
		other->setHasBegun();
	}
	if (!land) {
		//other->setGrounded(false);
	}
	if (move) {
		moveY(getPosY() + 3);
		if (getPosY() > SDL_GetWindowSurface(window)->h) {
			moveY((SDL_GetWindowSurface(window)->h - 1800));
			moveX(rand()%1100+1);
		}
	}
	return truth;
}