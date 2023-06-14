#pragma once
#include "../../engine/core/Scene.h"
#include "../../engine/core/Object.h"
#include "../../engine/rendering/components/Sprite.h"

namespace JLNWSpaceInvaders {
	class MainMenuInitializer {
	private:
		Scene mMainMenuScene;
	public:
		void init(Scene& scene);
		void dispose();
		MainMenuInitializer(Scene& scene);
		MainMenuInitializer();
		void createMainMenuGraphics();
	};
}