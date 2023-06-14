#pragma once
#include "RenderingElement.h"
#include "Texture2D.h"
#include "../RenderingBuilder.h"
#include "../WindowHandler.h"

class Sprite : public RenderingElement{
protected:
private:
	Texture2D mMainTexture;
	float mXPos, mYPos;
	SDL_Renderer* mRenderer;
	SDL_Window* mWindow;
public:
	bool loadTexture(const std::string& path) override;
	void render() override;
	//bool loadTextureExternal(const std::string& path);
	void init(int xPos, int yPos);
	void dispose();
	//Sprite();
};