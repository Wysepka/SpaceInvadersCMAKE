#include "../include/engine/utility/StringUtility.h"

bool StringUtility::FindAllCharAppearencesInString(const std::string& string, char charToFind, std::vector<int>& indexes) {
	bool foundIndex = false;
	for (size_t i = 0; i < string.size(); i++)
	{
		if (string[i] == charToFind) {
			indexes.push_back(i);
			foundIndex = true;
		}
	}
	return foundIndex;
}

std::string StringUtility::ParseDataLineToString(const std::string& string) {
	size_t semicolonID = string.find(':');
	size_t valueIDStart = semicolonID + 2;
	size_t stringLength = string.length() - valueIDStart;
	return string.substr(valueIDStart, stringLength);
}

void StringUtility::ParseDataLineToMultipleStrings(const std::string& string, std::vector<std::string>& values, char interludeChar, Uint32 words) {
	std::string stringValueAferSemicolon = ParseDataLineToString(string);
	std::vector<char> wordParser = {};

	for (size_t i = 0; i < stringValueAferSemicolon.size(); i++)
	{
		if (stringValueAferSemicolon[i] == interludeChar) {
			values.push_back(std::string(wordParser.begin(), wordParser.end()));
			wordParser.clear();
		}
		else if (stringValueAferSemicolon[i] == ' ') {
			continue;
		}
		else if (i == stringValueAferSemicolon.size() - 1) {
			wordParser.push_back(stringValueAferSemicolon[i]);
			values.push_back(std::string(wordParser.begin(), wordParser.end()));
			wordParser.clear();
		}
		else {
			wordParser.push_back(stringValueAferSemicolon[i]);
		}
	}
}

float StringUtility::ParseDataLineToFloat(const std::string& string) {
	size_t semicolonID = string.find(':');
	size_t valueID = semicolonID + 2;
	size_t digitsCount = string.length() - valueID;
	return std::stof(string.substr(valueID, digitsCount));
}

bool StringUtility::ParseDataLineToSize(const std::string& string , size_t& size) {
	try {
		size_t semicolonID = string.find(':');
		size_t valueID = semicolonID + 2;
		size_t digitsCount = string.length() - valueID;
		std::stringstream sstream(string.substr(valueID, digitsCount));
		sstream >> size;
	}
	catch(const std::exception& e){
		printf("Caught exception: %s , when trying to cast from string to size_t \n", e.what());
		return false;
	}
	return true;
}

Uint32 StringUtility::ParseDataLineToUnsignedInt32(const std::string& string) {
	size_t semicolonID = string.find(':');
	size_t valueID = semicolonID + 2;
	size_t digitsCount = string.length() - valueID;
	return static_cast<Uint32>(std::stoul(string.substr(valueID, digitsCount)));
}

uint16_t StringUtility::ParseDataLineToUnsignedInt16_t(const std::string& string) {
	size_t semicolonID = string.find(':');
	size_t valueID = semicolonID + 2;
	size_t digitsCount = string.length() - valueID;
	return static_cast<uint16_t>(std::stoi(string.substr(valueID, digitsCount)));
}