#pragma once
#include "../../engine/core/Scene.h"
#include "../include/data/GamePrefs.h"
#include "MainMenuInitializer.h"

namespace JLNWSpaceInvaders {
	class SpaceInvadersInitializer {
	private:
		MainMenuInitializer mMainMenuInit;
		uint16_t* mLevelsCount;
		Scene* mMainMenuScene;
		Scene* mHighScoreScene;
		Scene* mLevelsScenes;
	public:
		void initScenes();
		void initInitializers();
		void disposeGame();
		SpaceInvadersInitializer();
	};
}