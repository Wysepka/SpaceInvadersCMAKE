#include "../../../include/gameplay/initializers/MainMenuInitializer.h"

void JLNWSpaceInvaders::MainMenuInitializer::init(Scene& scene) {
	mMainMenuScene = scene;
}

void JLNWSpaceInvaders::MainMenuInitializer::dispose() {
	mMainMenuScene.addObject(new Object());
}

JLNWSpaceInvaders::MainMenuInitializer::MainMenuInitializer(Scene& scene) : mMainMenuScene(scene){}

JLNWSpaceInvaders::MainMenuInitializer::MainMenuInitializer() { 
	mMainMenuScene = *(new Scene()); 
	printf("ERROR: Initializing MainMenu with default scene ptr \n");
}

void JLNWSpaceInvaders::MainMenuInitializer::createMainMenuGraphics() {
	Sprite startGameSprite;
	startGameSprite.init(GamePrefs::getTypedInstance().mScreenWidth / 2 , GamePrefs::getTypedInstance().mScreenHeight / 2);
	std::string startGameSpriteButtonPath = std::string("Resources/PNGS/MainMenu/test1.jpg");
	//const std::string startGameSpriteButtonPath = std::string("./Resources/PNGS/MainMenu/StartGame.png");
	//const std::string startGameSpriteButtonPath = std::string("D:/Projekty/SDL/SpaceInvadersCMakeSDL/out/build/x64-Debug/Debug/Resources/PNGS/MainMenu/StartGame.png");
	startGameSprite.loadTexture(startGameSpriteButtonPath);
	Object& startGameObj = startGameSprite;
	RenderingElement& rendObj = startGameSprite;
	mMainMenuScene.addObject(&startGameObj);
	RenderingBuilder::registerRenderingElement(&rendObj);
}