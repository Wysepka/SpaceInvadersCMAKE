#include "../../../include/gameplay/initializers/SpaceInvadersInitializer.h"

void JLNWSpaceInvaders::SpaceInvadersInitializer::initScenes() {
	mMainMenuScene = new Scene();
	mHighScoreScene = new Scene();
	mLevelsCount = &GamePrefs::getTypedInstance().mLevelsCount;
	mLevelsScenes = new Scene[*mLevelsCount];

	//mMainMenuInit.init(*mMainMenuScene);
}

void JLNWSpaceInvaders::SpaceInvadersInitializer::disposeGame() {
	delete mMainMenuScene;
	delete mHighScoreScene;
	delete[] mLevelsScenes;

	//mMainMenuInit.dispose();
}

JLNWSpaceInvaders::SpaceInvadersInitializer::SpaceInvadersInitializer() {
	initScenes();
	initInitializers();
}

void JLNWSpaceInvaders::SpaceInvadersInitializer::initInitializers() {
	mMainMenuInit = { *mMainMenuScene };
	mMainMenuInit.createMainMenuGraphics();
}