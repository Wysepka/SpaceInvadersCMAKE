#pragma once
#include <SDL_image.h>
#include "../rendering/WindowHandler.h"
#include "data/GamePrefs.h"
#include "engine/IO/IOService.h"
#include "engine/core/Singleton.h"
#include "engine/events/EventsLoop.h"
#include "gameplay/initializers/SpaceInvadersInitializer.h"

class AppHandler {
private:
	WindowHandler* mWindowHandler;
	JLNWCore::EventsLoop* mEventsLoop;
	JLNWSpaceInvaders::SpaceInvadersInitializer* mSpaceInvadersInit;
	void initIOServiceAndReadData();
	void processEngineComponent_SeperateThread();
	bool initSDLSettings();
	void initGame();
	void initWindow();

	//template<typename ClassType>
	//void initializeStaticMember()

public:
	//AppHandler();
	void init();
	void disposeApp();


};