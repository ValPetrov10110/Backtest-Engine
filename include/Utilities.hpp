#pragma once

#include <string>
#include <cstdlib>

namespace utility{
	inline void toUpper(std::string& s){
		for(char& c : s){
			c = std::toupper(c);
		}
	}

	inline void clearScreen(){
		#ifdef _WIN32
			std::system("cls");
		#else
			std::system("clear");
		#endif
	}
}
