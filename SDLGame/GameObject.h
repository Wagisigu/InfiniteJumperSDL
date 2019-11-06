#pragma once
#include "Game.h"

class GameObject{

public:

	GameObject(const char* filename, SDL_Renderer* ren, int startPosX, int startPosY,
		int objectHeight, int objectWidth, int selectionHeight, int selectionWidth, int selectionPositionX, int selectionPositionY);

	~GameObject();

	void update();

	void render();

	void setSrcX(int newX);

	int getSrcX();

	void setSrcY(int newY);

	int getSrcY();

	int getHeight();

	void moveSrcX(int increment);

	void moveSrcY(int increment);

	void moveX(int newX);

	void moveY(int newY);

	int getPosX();

	int getPosY();

	bool collision(GameObject* other);

	bool landing(GameObject* other);

private:

	SDL_Renderer* renderer;
	SDL_Texture* object;
	SDL_Rect srcRect, destRect;

	bool isOn(int x, int y);
	bool isOver(int x, int y);

};