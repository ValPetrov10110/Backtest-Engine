#include "data/DataFetcher.hpp"
#include "ui/Menu.hpp"

#include <iostream>
#include <cstdlib>

void run();

int main(){
	run();

	return EXIT_SUCCESS;
}

void run(){
	MenuLoader menu{};
	menu.init();
}
