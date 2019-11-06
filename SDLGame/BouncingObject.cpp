#include "BouncingObject.h"

int cnt;

BouncingObject::BouncingObject(const char* filename, SDL_Renderer* ren, SDL_Window* win, int startPosX, int startPosY, int startYVelocity, GameObject* play,
	int objectHeight, int objectWidth, int selectionHeight, int selectionWidth, int selectionPositionX, int selectionPositionY, int xVel) :
GameObject(filename, ren, startPosX, startPosY,
		objectHeight, objectWidth, selectionHeight, selectionWidth, selectionPositionX, selectionPositionY) {
	yVelocity = startYVelocity;
	window = win;
	player = play;
	cnt = 0;
	xVelocity = xVel;
}

void BouncingObject::update(std::vector<BouncingObject*>* balls, int i) {
	if (getPosY() >= SDL_GetWindowSurface(window)->h - 100) {
		yVelocity *= -1;
		yVelocity += 5;
		moveY(SDL_GetWindowSurface(window)->h - 100);
	}
	else {
		yVelocity += 2;
	}
	if (getPosX() >= SDL_GetWindowSurface(window)->w - 80) {
		xVelocity *= -1;
		moveX(SDL_GetWindowSurface(window)->w - 80);
	}
	if (getPosX() <= 0) {
		xVelocity *= -1;
		moveX(0);
	}

	kill();
	moveY(getPosY() + yVelocity);
	moveX(getPosX() + xVelocity); 
	if (yVelocity <= 5 && getPosY() >= SDL_GetWindowSurface(window)->h - 105) {
		balls->erase(balls->begin()+i);
	}
}

bool BouncingObject::kill() {
	if (getPosY() >= SDL_GetWindowSurface(window)->h - 550) {
		if (collision(player)) {
			cnt++;
			std::cout << cnt << " points!\n";
			yVelocity *= -1;
			yVelocity -= 15;
			if (yVelocity < -50) {
				yVelocity = -50;
			}
			moveY(SDL_GetWindowSurface(window)->h - 200);
			return true;
		}
	}
	return false;
}

int BouncingObject::printScore() {
	std::cout << "\nYou got " << cnt << " points!\n";
	return cnt;
}