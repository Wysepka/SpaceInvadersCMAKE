#include "../include/engine/rendering/components/Sprite.h"

void Sprite::init(int xPos, int yPos) {
	RenderingBuilder::registerRenderingElement(this);
}

bool Sprite::loadTexture(const std::string& path) {
	try {
		if (!mMainTexture.loadTexture(path, RenderingBuilder::getTypedInstance().getRenderer(), WindowHandler::getTypedInstance().getWindow())) {
			printf("Could not load texture !\n");
		}
	}
	catch(const std::exception& e){
		printf("Error loading texture: ERROR: %s\n", e.what());
	}
	return true;
}

void Sprite::render() {
	mMainTexture.render(mXPos, mYPos);
}


void Sprite::dispose() {

}

//Sprite::Sprite(){}