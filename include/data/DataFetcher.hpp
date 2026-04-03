#pragma once

#include <string>

class DataFetcher{
private:
	std::string ticker;
public:
	void fetch();
	void setTicker(std::string ticker);
};
