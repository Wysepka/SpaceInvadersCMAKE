#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#pragma once
#include <string>
#include <windows.h>
#include <SDL.h>
#include <SDL_image.h>

class Texture2D {
private:
	int mWidth, mHeight;
	SDL_Renderer* mRenderer;
	SDL_Window* mWindow;
	SDL_Texture* mTexture;
	SDL_Surface* mSurfacePixels;
	bool loadPixelsFromFile(const std::string& path);
	bool loadFromPixels();
	void free();
public:
	bool loadTexture(const std::string& path, SDL_Renderer* renderer, SDL_Window* window);
	void render(float xPos, float yPos);
	Texture2D();
	~Texture2D();
};

#endif