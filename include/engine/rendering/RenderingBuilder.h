#ifndef RENDERING_BUILDER_H
#define RENDERING_BUILDER_H

#pragma once
#include <functional>
#include <vector>
#include <algorithm>
#include <SDL.h>
#include <SDL_image.h>
#include "../include/engine/rendering/components/RenderingElement.h"
#include "../include/engine/events/EventDispatcher.h"

class RenderingElement;

class RenderingBuilder : public JLNWCore::Singleton<RenderingBuilder> {
private:
	void updateRenderers();
	eventpp::CallbackList<void()>::Handle mTickHandle;
	std::function<void()>* mRendFunc;
	std::vector<RenderingElement*> mRenderingElements;
	SDL_Renderer* mRenderer;
public:
	void initializeRendering(SDL_Window* window);
	void disposeRendering();
	static bool registerRenderingElement(RenderingElement* element);
	static bool unregisterRenderingElement(RenderingElement* element);
	SDL_Renderer* getRenderer();
};

#endif