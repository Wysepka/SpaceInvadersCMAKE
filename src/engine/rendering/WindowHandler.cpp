#include "../../../include/engine/rendering/WindowHandler.h"


WindowHandler::WindowHandler() {

}

bool WindowHandler::createWindow() {
	//Vell , vell, vell i should get copy of instance not to fuck with it
	GamePrefs prefInst = GamePrefs::getTypedInstance();
	float height = prefInst.mScreenHeight;
	float width = prefInst.mScreenWidth;
	SDL_DisplayMode dm;
	float x = 500;
	float y = 500;

	if (SDL_GetCurrentDisplayMode(0, &dm)) {
		x = dm.w / 2;
		y = dm.h / 2;
	}
	else {
		printf("Could not get display mode, ERROR: %s", SDL_GetError());
	}

	std::string title = prefInst.mGameTitle;
	//Uint32 flags = prefInst.mWindowFlagsInt;
	Uint32 flags = SDL_WINDOW_RESIZABLE;
	mWindow = SDL_CreateWindow(title.c_str(), x, y, height, width , flags);

	if (mWindow == NULL) {
		printf("Could not create SDL_Window , ERROR: %s", SDL_GetError());
		return false;
	} 
	/*
	SDL_Renderer* renderer = SDL_CreateRenderer(window , 0, SDL_RENDERER_ACCELERATED);

	SDL_Surface* testImgSurface = IMG_Load("Resources/Rendering/Debug/background.png");

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, testImgSurface);
	SDL_Rect rect = {};
	rect.w = testImgSurface->w;
	rect.h = testImgSurface->h;

	SDL_RenderCopy(renderer, texture, &rect, NULL);

	SDL_RenderPresent(renderer);
	//SDL_UpdateWindowSurface(window);
	*/
	return true;
}

void WindowHandler::initializeRendering() {
	mRenderingBuilder = {};
	RenderingBuilder::applyTypedInstance(mRenderingBuilder);
	mRenderingBuilder.initializeRendering(mWindow);
}

SDL_Window* WindowHandler::getWindow() {
	return mWindow;
}