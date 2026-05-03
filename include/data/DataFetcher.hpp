#pragma once

// This entire .hpp file can be cleaned up slightly to make one main .init() or .run() method

#include <string>
#include <stdexcept>

class DataFetcher{
private:
	std::string ticker;
	std::string from = "2024-05-02";
	std::string to = "2026-05-01";
	std::string base_url = "https://api.massive.com";
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
