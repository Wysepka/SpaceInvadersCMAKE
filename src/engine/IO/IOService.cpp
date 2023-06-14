#include "../include/engine/IO/IOService.h"

template<typename Data>
inline bool IOService::ReadData(FileType fileType, Data& dataType)
{
	if (!mFileTypeToPath.contains(fileType)) {
		printf("There is no path specified for: %s", FileType_ToString(fileType));
		return false;
	}

	//Basically open file and close it to create file -_(-_-)_-
	if (!fileExists(mFileTypeToPath[fileType])) {
		std::ifstream stream = std::ifstream();
		const std::string path = mFileTypeToPath[fileType];
		stream.open(path, std::ios::in);
		stream.close();
	}

	std::ifstream stream = std::ifstream();
	const std::string path = mFileTypeToPath[fileType];
	stream.open(path, std::ios::in);

	try {
		if (!ReadCustomDataFromFile(stream, dataType)) {
			throw std::runtime_error("Writing to file went wrong :(");
		}
		else {
			stream.close();
			return true;
		}
	}
	catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << '\n';
		stream.close();
		return false;
	}
}

inline bool IOService::fileExists(const std::string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}

template bool IOService::ReadData<GamePrefs>(FileType fileType, GamePrefs& gamePrefs);


//template<float>
template<typename Data> bool IOService::WriteData(FileType fileType,const Data dataType)
{
	if (!mFileTypeToPath.contains(fileType)) {
		printf("There is no path specified for: %s", FileType_ToString(fileType));
		return false;
	}

	if (!fileExists(mFileTypeToPath[fileType])) {
		std::ifstream streamIn;
		streamIn.open(mFileTypeToPath[fileType]);
		streamIn.close();
	}

	std::ofstream stream = std::ofstream();
	const std::string path = mFileTypeToPath[fileType];
	stream.open(path, std::ios::out);

	try {
		if (!WriteCustomDataToFile(stream, dataType)) {
			throw std::runtime_error("Writing to file went wrong :(");
		}
		else {
			stream.close();
			return true;
		}
	}
	catch(const std::exception& e){
		printf("Caught exception: %s \n" , e.what());
		stream.close();
		return false;
	}
}

//template bool IOService::WriteData<float>(FileType fileType, float dataType);
template bool IOService::WriteData<GamePrefs>(FileType fileType, GamePrefs gamePrefs);


template<typename Data> bool IOService::WriteCustomDataToFile(std::ofstream& stream, const Data dataType) {
	printf("No Custom method is specialized in writing type: %s", typeid(dataType).name());
	return false;
}

bool IOService::WriteCustomDataToFile(std::ofstream& stream, const GamePrefs gamePrefs) {
	stream << gamePrefs;
	return true;
}

template<typename Data> bool IOService::ReadCustomDataFromFile(std::ifstream& stream, Data& data) {
	printf("No Custom method is specialized in reading type: %s", typeid(data).name());
	return false;
}

bool IOService::ReadCustomDataFromFile(std::ifstream& stream, GamePrefs& prefs) {
	stream >> prefs;
	return true;
}


std::string IOService::FileType_ToString(FileType fileType) {
	switch (fileType)
	{
	case IOService::GAME_PREF:
		return std::string("GamePref");
		break;
	default:
		return std::string("FileType Not Specified in adapter");
		break;
	}
}

bool IOService::init() {
	//mInStream = new std::ifstream()
	return true;
}

bool IOService::dispose() {
	return true;
}
