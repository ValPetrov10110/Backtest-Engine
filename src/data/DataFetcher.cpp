#include "data/DataFetcher.hpp"

#include <httplib.h>

// This function is responsible for fecthing the data
void DataFetcher::fetch(){
	if(ticker.empty()){
		throw EmptyTickerException{};
	}
}


void DataFetcher::setTicker(std::string ticker){
	this->ticker = ticker;
}

