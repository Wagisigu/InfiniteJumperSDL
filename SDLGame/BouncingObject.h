#pragma once
#include "Game.h"
#include "GameObject.h"

class BouncingObject : public GameObject {

public:

	BouncingObject(const char* filename, SDL_Renderer* ren, SDL_Window* window, int startPosX, int startPosY, int startYVelocity, GameObject* player,
		int objectHeight, int objectWidth, int selectionHeight, int selectionWidth, int selectionPositionX, int selectionPositionY, int xVel);

	~BouncingObject();

	void update(std::vector<BouncingObject*>* balls, int i);

	bool kill();

	static int printScore();

private:

	GameObject* object;
	bool collided;
	int yVelocity;
	int xVelocity;
	SDL_Window* window;
	GameObject* player;

};