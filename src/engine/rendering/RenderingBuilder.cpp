#include "../include/engine/rendering/RenderingBuilder.h"

void RenderingBuilder::initializeRendering(SDL_Window* window) {
	mRenderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);
	mRendFunc = new std::function<void()>(std::bind(&RenderingBuilder::updateRenderers , *this));
	//std::function<void()> updateRenderersFunc = std::bind(&updateRenderers);
	mTickHandle = JLNWCore::EventDispatcher::registerToTick(*mRendFunc);
}

void RenderingBuilder::disposeRendering() {
	if (mTickHandle != NULL) {
		JLNWCore::EventDispatcher::unregisterFromTick(mTickHandle);
	}
	else {
		printf("Tick Handle is null\n");
	}
}

void RenderingBuilder::updateRenderers() {
	/*
	std::for_each(mRenderingElements.begin(), mRenderingElements.end(), [](RenderingElement* obj) {
		obj->render();
		});
	*/
	for (auto& obj : mRenderingElements)
	{
		obj->render();
	}
}

bool RenderingBuilder::registerRenderingElement(RenderingElement* element) {
	getTypedInstance().mRenderingElements.push_back(element);
	return true;
}

bool RenderingBuilder::unregisterRenderingElement(RenderingElement* element) {
	std::vector<RenderingElement*>::iterator iterator;
	for (auto i = getTypedInstance().mRenderingElements.begin(); i != getTypedInstance().mRenderingElements.end(); ++i)
	{
		if (*i == element) {
			getTypedInstance().mRenderingElements.erase(i);
			i--;
			return true;
		}
	}
	return false;
}

SDL_Renderer* RenderingBuilder::getRenderer() {
	return mRenderer;
}