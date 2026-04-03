#include "data/DataFetcher.hpp"

#include <iostream>
#include <cstdlib>

int main(){
	std::cout << "Starting Backtest Engine...\n";
	DataFetcher data;
	data.setTicker("AAPL");

	return EXIT_SUCCESS;
}
