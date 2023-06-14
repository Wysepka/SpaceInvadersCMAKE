#ifndef WINDOW_HANDLER_H
#define WINDOW_HANDLER_H

#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "data/GamePrefs.h"
#include "../include/engine/rendering/RenderingBuilder.h"
#include "../include/engine/core/Singleton.h"

class WindowHandler : public JLNWCore::Singleton<WindowHandler> {
private:
	RenderingBuilder mRenderingBuilder;
	SDL_Window* mWindow;
public:
	WindowHandler();
	bool createWindow();
	void initializeRendering();
	SDL_Window* getWindow();
};

#endif