// SpaceInvadersCMakeSDL.cpp : Defines the entry point for the application.
//

#include "../include/main.h"

int main(int argc, char* argv[])
{
	AppHandler appHandler;
	appHandler.init();
	appHandler.disposeApp();
	//appHandler.init();
	//cout << "Hello CMake." << endl;

	return 0;
}
