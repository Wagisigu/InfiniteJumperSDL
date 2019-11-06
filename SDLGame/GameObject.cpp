#include "GameObject.h"
#include "TextureManager.h"


GameObject::GameObject(const char* filename, SDL_Renderer* ren, int startPosX, int startPosY,
	int objectHeight, int objectWidth, int selectionHeight, int selectionWidth, int selectionPositionX, int selectionPositionY) {
	object = TextureManager::LoadTexture(filename, ren);

	destRect.x = startPosX;
	destRect.y = startPosY;
	renderer = ren;

	destRect.h = objectHeight;
	destRect.w = objectWidth;
	srcRect.h = selectionHeight;
	srcRect.w = selectionWidth;
	srcRect.x = selectionPositionX;
	srcRect.y = selectionPositionY;
}

void GameObject::update() {
}

void GameObject::render() {
	SDL_RenderCopy(renderer, object, &srcRect, &destRect);
}

void GameObject::setSrcX(int newX) {
	srcRect.x = newX;
}

int GameObject::getSrcX() {
	return srcRect.x;
}

void GameObject::setSrcY(int newY) {
	srcRect.y = newY;
}

int GameObject::getSrcY() {
	return srcRect.y;
}

int GameObject::getHeight() {
	return destRect.h;
}

void GameObject::moveSrcX(int increment) {
	srcRect.x += increment;
}

void GameObject::moveSrcY(int increment) {
	srcRect.y += increment;
}

void GameObject::moveX(int newX) {
	destRect.x = newX;
}

void GameObject::moveY(int newY) {
	destRect.y = newY;
}

int GameObject::getPosX() {
	return destRect.x;
}

int GameObject::getPosY() {
	return destRect.y;
}

bool GameObject::isOn(int x, int y) {
	if (x >= destRect.x && x <= destRect.x + destRect.w &&
		y >= destRect.y && y <= destRect.y + destRect.h) {
		return true;
	}
	return false;
}

bool GameObject::collision(GameObject* other) {
	for (int i = 0; i < destRect.w; i++) {
		for (int j = 0; j < destRect.h; j++) {
			if (isOn(i + other->getPosX(), j + other->getPosY())) {
				return true;
			}
		}
	}
	return false;
}

bool GameObject::landing(GameObject* other) {
	if (other->isOn(destRect.x, destRect.y + destRect.h) || other->isOn(destRect.x + destRect.w, destRect.y + destRect.h)) {
		return true;
	}
	return false;
}