#pragma once
#include <string>
#include <vector>
#include <sstream>
//This is little but poor cause im using SDL library for Uint32 but anyway this works and will stick to it, in bigger project this should be banned !
#include <SDL.h>

class StringUtility {
public:
	///I know i can just pass reference type in argument and assign value but no this is small engine  ;)
	static bool FindAllCharAppearencesInString(const std::string& string, char charToFind, std::vector<int>& indexes);
	static float ParseDataLineToFloat(const std::string& string);
	static std::string ParseDataLineToString(const std::string& string);
	static void ParseDataLineToMultipleStrings(const std::string& string, std::vector<std::string>& values, char interludeChar, Uint32 words = 0);
	static bool ParseDataLineToSize(const std::string& string , size_t& size);
	static Uint32 ParseDataLineToUnsignedInt32(const std::string& string);
	static uint16_t ParseDataLineToUnsignedInt16_t(const std::string& string);
};