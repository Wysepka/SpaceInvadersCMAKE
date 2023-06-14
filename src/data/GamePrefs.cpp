#include "../include/data/GamePrefs.h"

const std::ofstream& operator<<(std::ofstream& ofs, const GamePrefs& g) {
	ofs << "ScreenHeight: " << g.mScreenHeight << '\n';
	ofs << "ScreenWidth: " << g.mScreenWidth << '\n';
	ofs << "GameTitle: " << g.mGameTitle << '\n';
	ofs << "InitFlagsCount: " << g.mInitFlags.size() << '\n';
	ofs << "InitFlags: ";
	for (size_t i = 0; i < g.mInitFlags.size(); i++)
	{
		ofs << g.mInitFlags[i];
		if (i < g.mInitFlags.size() - 1) {
			ofs << '|';
		}
	}
	ofs << '\n';

	ofs << "WindowFlagsCount: " << g.mWindowFlags.size() << '\n';
	ofs << "WindowFlags: ";
	for (size_t i = 0; i < g.mWindowFlags.size(); i++)
	{
		ofs << g.mWindowFlags[i];
		if (i < g.mWindowFlags.size() - 1) {
			ofs << '|';
		}
	}
	ofs << '\n';
	ofs << "LevelsCount: " << g.mLevelsCount << '\n';

	return ofs;
}

std::ifstream& operator>>(std::ifstream& ifs, GamePrefs& g) {
	std::string line;
	std::getline(ifs, line);
	g.mScreenHeight = StringUtility::ParseDataLineToFloat(line);
	line.clear();
	
	std::getline(ifs, line);
	g.mScreenWidth = StringUtility::ParseDataLineToFloat(line);
	line.clear();
	
	std::getline(ifs, line);
	g.mGameTitle = StringUtility::ParseDataLineToString(line);
	line.clear();
	
	size_t flagsCount = 0;
	std::vector<std::string> values = {};

	GamePrefs::ReadFlagsData(ifs, line, values, GamePrefs::PrefFlagType::Init, g.mInitFlagsInt, g.mInitFlags);
	GamePrefs::ReadFlagsData(ifs, line, values, GamePrefs::PrefFlagType::Window, g.mWindowFlagsInt, g.mWindowFlags);

	std::getline(ifs, line);
	g.mLevelsCount = StringUtility::ParseDataLineToUnsignedInt16_t(line);
	line.clear();

	return ifs;
}

void GamePrefs::ReadFlagsData(std::ifstream& ifs, std::string& line, std::vector<std::string>& tempValues ,PrefFlagType flagType, Uint32& flagMember, std::vector<std::string>& flagStringMember ) {
	std::getline(ifs, line);
	size_t flagsCount = 0;
	StringUtility::ParseDataLineToSize(line, flagsCount);
	line.clear();

	std::getline(ifs, line);
	StringUtility::ParseDataLineToMultipleStrings(line, tempValues, '|', flagsCount);
	flagStringMember = tempValues;

	for (size_t i = 0; i < tempValues.size(); i++)
	{
		if (flagType == PrefFlagType::Init) {
			flagMember |= GamePrefs::StringInitFlagToInt(tempValues[i]);
		}
		else if (flagType == PrefFlagType::Window) {
			flagMember |= GamePrefs::StringWindowFlagToInt(tempValues[i]);
		}
	}
	line.clear();
	tempValues.clear();
}

unsigned int GamePrefs::StringInitFlagToInt(const std::string& string) {
	if (string == "SDL_INIT_VIDEO") {
		return SDL_INIT_VIDEO;
	}
	else if (string == "SDL_INIT_TIMER") {
		return SDL_INIT_TIMER;
	}
	else {
		return 0u;
	}
}

unsigned int GamePrefs::StringWindowFlagToInt(const std::string& string) {
	if (string == "SDL_WINDOW_RESIZABLE") {
		return SDL_WINDOW_RESIZABLE;
	}
	else  if (string == "SDL_WINDOW_SHOWN") {
		return SDL_WINDOW_SHOWN;
	}
	else {
		return 0u;
	}
}