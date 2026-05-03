#include "engine/BacktestEngine.hpp"
#include "data/DataFetcher.hpp"
#include "Utilities.hpp"

#include <iostream>

// This is for the helper functions
namespace{
	bool tickerValidity(std::string ticker){
		// Initial check if it fits in the bounds
		if(ticker.empty() || ticker.size() > 5){
			return false;
		}
		return true;
	}
}

void BacktestEngine::setAPIData(){
	DataFetcher data;

	std::cout << "Enter ticker: ";
	std::string ticker{};
	std::cin >> ticker;
	utility::toUpper(ticker); // This will mutate the original string to all capital characters

	if(!tickerValidity(ticker)){
		std::cerr << "Ticker is invalid\n";
		return;
	}



}

void BacktestEngine::run(){
	utility::clearScreen();
	BacktestEngine::setAPIData();
}
