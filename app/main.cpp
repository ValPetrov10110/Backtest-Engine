#include "data/DataFetcher.hpp"

#include <iostream>
#include <cstdlib>

int main(){
	std::cout << "Starting Backtest Engine...\n";
	DataFetcher data{};
	try{
		data.fetch();
	}
	catch(DataFetcher::EmptyTickerException& e){
		std::cerr << e.what() << "\n";
	}

	return EXIT_SUCCESS;
}
