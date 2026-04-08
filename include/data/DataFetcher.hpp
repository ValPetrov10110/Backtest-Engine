#pragma once

#include <string>
#include <stdexcept>

class DataFetcher{
private:
	std::string ticker;
public:
	void fetch();
	void setTicker(std::string ticker);

	class EmptyTickerException : public std::runtime_error {
	public:
		// We are setting the base classes message
		EmptyTickerException() : std::runtime_error("Error: Ticker not set"){

		}
	};
};
