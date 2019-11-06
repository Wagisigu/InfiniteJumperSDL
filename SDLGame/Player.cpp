#include "Player.h"

Player::Player(const char* filename, SDL_Window* win, SDL_Renderer* ren, int startPosX, int startPosY,
	int objectHeight, int objectWidth, int selectionHeight, int selectionWidth, int selectionPositionX, int selectionPositionY) : 
	GameObject(filename, ren, startPosX, startPosY,
		objectHeight, objectWidth, selectionHeight, selectionWidth, selectionPositionX, selectionPositionY) {
	window = win;
	ground = startPosY;
	cntr = 0;
}

int Player::getVelY() {
	return yVelocity;
}

void Player::setVelY(int newVelY) {
	yVelocity = newVelY;
}

void Player::setGrounded(bool onGround) {
	grounded = onGround;
}

void Player::setHasBegun() {
	hasBegun = true;
}

void Player::setGround(int groundY) {
	ground = groundY;
}

void Player::resetGround() {
	ground = SDL_GetWindowSurface(window)->h - getHeight();
}

void Player::update() {

	if (getPosY() < ground && !grounded) {
		yVelocity++;
		if (yVelocity > 39) {
			yVelocity = 39;
		}
		setSrcY(168);
		setSrcX(110);
	}

	if (playerMoveLeft) {
		moveX(getPosX() - 10);
		if (getPosY() >= ground) {
			setSrcY(56);
			if (cntr % 5 == 0) {
				moveSrcX(55);
			}
			if (getSrcX() >= 280) {
				setSrcX(0);
			}
		}
		else { setSrcX(390); }

		if (getPosX() < 0 - 66) {
			moveX(SDL_GetWindowSurface(window)->w - 1);
		}
	}

	if (playerMoveRight) {
		moveX(getPosX() + 10);
		if (getPosY() >= ground) {
			setSrcY(112);
			if (cntr % 5 == 0) {
				moveSrcX(55);
			}
			if (getSrcX() >= 280) {
				setSrcX(0);
			}
		}
		else { 
			setSrcX(440);
		}
		if (getPosX() > SDL_GetWindowSurface(window)->w) {
			moveX(-65);
		}
	}

	moveY(getPosY() + yVelocity);

	if (getPosY() >= ground) {
		moveY(ground);
		yVelocity = 0;
		if (getSrcY() > 112) {
			setSrcX(0);
			setSrcY(0);
		}
	}

	if (getPosY() >= SDL_GetWindowSurface(window)->h - getHeight() && hasBegun) {
		Game::setGoToMenu();
	}
	cntr++;
}

void Player::jump() {
	if (getPosY() == ground || grounded) {
		yVelocity = -20;
	}
}

bool Player::getHasBegun() {
	return hasBegun;
}