#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <SDL.h>
#include "../include/engine/core/Singleton.h"
#include "../include/engine/utility/StringUtility.h"

class GamePrefs : public JLNWCore::Singleton<GamePrefs> {
public:
	enum PrefFlagType {None = 0, Init = 1 , Window = 2};
	//GamePrefs();

	float mScreenHeight = 620;
	float mScreenWidth = 480;
	std::string mGameTitle = "Spice Invaders !";
	std::vector<std::string> mInitFlags = { {std::string("SDL_INIT_VIDEO")}, {std::string("SDL_INIT_TIMER") } };
	std::vector<std::string> mWindowFlags = { {std::string("SDL_WINDOW_SHOWN")} , {std::string("SDL_WINDOW_RESIZABLE") } };
	Uint32 mInitFlagsInt;
	Uint32 mWindowFlagsInt;
	uint16_t mLevelsCount = 1;

	//static bool createInstance(const GamePrefs gamePrefs);
	
	bool operator!=(const GamePrefs& prefs) const {
		return this->mScreenHeight != prefs.mScreenHeight && this->mScreenWidth != prefs.mScreenHeight;
	}
	bool operator==(const GamePrefs& prefs) const {
		return this->mScreenHeight == prefs.mScreenHeight && this->mScreenWidth == prefs.mScreenHeight;
	}
	
	/// <summary>
	/// This is used only for SDL NULL if check
	/// </summary>
	/// <param name="value"></param>
	/// <returns></returns>
	bool operator!=(const int& value) const {
		return this->mScreenHeight != value && this->mScreenWidth != value && mInitFlags.size() > 0;
	}
	bool operator==(const int& value) const {
		return this->mScreenHeight == value && this->mScreenWidth == value && mInitFlags.size() == 0;
	}

	friend const std::ofstream& operator<<(std::ofstream& ofs, const GamePrefs& g);

	friend std::ifstream& operator>>(std::ifstream& ifs, GamePrefs& g);

private:
	static unsigned int StringInitFlagToInt(const std::string& string);
	static unsigned int StringWindowFlagToInt(const std::string& string);

	static void ReadFlagsData(std::ifstream& ifs, std::string& line, std::vector<std::string>& tempValues,PrefFlagType flagType , Uint32& flagMember, std::vector<std::string>& flagStringMember);
};
