#pragma once

#include <string>

// This is the daily bar
struct bar{
	std::string symbol;
	std::string timestamp;

	double open;
	double high;
	double low;
	double close;
	long long volume;
};
