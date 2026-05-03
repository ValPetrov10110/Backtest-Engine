#pragma once

#include <string>

namespace color{
	inline constexpr std::string reset = "\033[0m";

	// Colors
	inline constexpr std::string green = "\033[32m";
	inline constexpr std::string red = "\033[31m]";
	inline constexpr std::string yellow = "\033[33m";
	inline constexpr std::string blue = "\033[34m";
	inline constexpr std::string cyan = "\033[36m";

	// Text Styles
	inline constexpr std::string bold = "\033[1m";
	inline constexpr std::string dim = "\033[2m";
}

