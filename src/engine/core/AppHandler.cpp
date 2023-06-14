
#include "../../../include/engine/core/AppHandler.h"

//AppHandler::AppHandler()
//{
//}

void AppHandler::init() {
	initIOServiceAndReadData();

	initSDLSettings();
	initWindow();

	mEventsLoop = new JLNWCore::EventsLoop();
	mEventsLoop->initEventDispatcher();
	mWindowHandler->initializeRendering();

	initGame();

	processEngineComponent_SeperateThread();


	//float somt;
	//std::cin >> somt;
}

void AppHandler::initWindow() {
	mWindowHandler = new WindowHandler();
	mWindowHandler->applyTypedInstance(*mWindowHandler);
	mWindowHandler->createWindow();
}

void AppHandler::disposeApp() {
	mSpaceInvadersInit->disposeGame();

	delete mWindowHandler;
	delete mEventsLoop;
	delete mSpaceInvadersInit;
}

void AppHandler::initIOServiceAndReadData() {
	GamePrefs gamePrefs = {};
	IOService::ReadData(IOService::FileType::GAME_PREF, gamePrefs);

	//GamePrefs::createInstance(gamePrefs , gamePrefs);
	GamePrefs::applyTypedInstance(gamePrefs);
	//GamePrefs::mScreenWidth = 555;
	bool result = IOService::WriteData(IOService::FileType::GAME_PREF, gamePrefs);
}

void AppHandler::processEngineComponent_SeperateThread() {	
	mEventsLoop->initEventLoop();
	//while (mEventsLoop->getIsApplicationNotClosed()) {
	//}
}

bool AppHandler::initSDLSettings() {
	SDL_SetMainReady();
	if (SDL_Init(GamePrefs::getTypedInstance().mInitFlagsInt) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		return false;
	}
	else {
		int imgFlags = IMG_INIT_PNG || IMG_INIT_JPG;
		
		if (!(IMG_Init(imgFlags) & imgFlags))
		{
			printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
			return false;
		}

		return true;
	}
}

void AppHandler::initGame() {
	mSpaceInvadersInit = new JLNWSpaceInvaders::SpaceInvadersInitializer();
}