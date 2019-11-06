#pragma once
#include "Game.h"
#include "GameObject.h"

class Player : public GameObject {

public:

	Player(const char* filename, SDL_Window* win, SDL_Renderer* ren, int startPosX, int startPosY,
		int objectHeight, int objectWidth, int selectionHeight, int selectionWidth, int selectionPositionX, int selectionPositionY);

	~Player();

	int getVelY();

	void setVelY(int newVelY);

	void setGrounded(bool onGround);

	void setHasBegun();

	void setGround(int groundY);

	void resetGround();

	void update();

	void jump();

	bool getHasBegun();

	bool playerMoveLeft;

	bool playerMoveRight;

private:

	int cntr;
	bool hasBegun;
	int height;
	bool grounded;
	int ground;
	int yVelocity;
	SDL_Window* window;

};