#include "data/DataFetcher.hpp"

// This entire .cpp file can be cleaned up slightly to make one main .init() or .run() method

#include <httplib.h>
#include "nlohmann/json.hpp"

// This function is responsible for fecthing the data
void DataFetcher::fetch(){
	if(ticker.empty()){
		throw EmptyTickerException{};
	}

	httplib::Client cli(base_url);
	auto res = cli.Get("/v2/aggs/ticker/" + ticker + "/range/1/day/" + from + "/" + to 
			+ "&apiKey=iegPQzG1WdzC_6A_BBoKdBPJvQn8RROG");

	
	if(!res){
		std::cerr << "Request Failed\n";
		return;
	}
	else if(res->status != 200){
		std::cerr << "HTTP Error: " << res->status << "\n";
		std::cerr << "Response body: " << res->body << "\n";
		return;
	}

	auto json = nlohmann::json::parse(res->body);

}


void DataFetcher::setTicker(std::string ticker){
	this->ticker = ticker;
}

