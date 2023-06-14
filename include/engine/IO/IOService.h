#pragma once
#include "data/GamePrefs.h"
#include <typeinfo>
#include <iostream>
#include <fstream>
#include <map>

class IOService {
public:
	enum FileType : unsigned int {
		GAME_PREF = 1,
	};

	static std::string FileType_ToString(FileType fileType);

	template<typename Data>
	static bool ReadData(FileType fileType, Data& data);
	template<typename Data>
	static bool WriteData(FileType fileType, const Data data);
	bool init();
	bool dispose();

private:
	inline static std::map<IOService::FileType,const std::string> mFileTypeToPath = {
		{IOService::FileType::GAME_PREF , std::string("Data/GamePrefs.txt")},
	};

	static bool fileExists(const std::string& name);

	static std::ifstream* mInStream;
	static std::ofstream* mOutStream;

	template<typename Data>
	static bool WriteCustomDataToFile(std::ofstream& stream, const Data dataType);
	static bool WriteCustomDataToFile(std::ofstream& stream, const GamePrefs prefs);

	template<typename Data>
	static bool ReadCustomDataFromFile(std::ifstream& stream, Data& data);
	static bool ReadCustomDataFromFile(std::ifstream& stream, GamePrefs& prefs);
};