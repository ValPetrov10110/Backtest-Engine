#include "ui/Menu.hpp"
#include "ui/Color.hpp"

#include <cstdlib>
#include <iostream>

// This is where my helper functions will go
namespace{
	// This will clear the terminal screen depending on the OS
	void clearScreen(){
		#ifdef _WIN32
			std::system("cls");
		#else
			std::system("clear");
		#endif
	}
}

// This method will not display the results from loadMenuOptions()
void MenuLoader::runMenuOption(){
	clearScreen();
	switch(menuSelection){
		case 1:
			// This will run the backtest
			break;
		case 2:
			// This will view the previous backtest results
			break;
		case 3:
			// This will go into the settings
			break;
		case 4:
			// This will display the help/about section
			break;
		case 0:
			// This will exit the program
			break;
		default:
			std::cout << "This is a placeholder for now\n";
	}
}

// This method both displays the menu options and saves it to the internal 
// menuSelection variable
void MenuLoader::loadMenuOptions(){
	std::cout << "\n\t1. Run New Backtest";
	std::cout << "\n\t2. View Last Results";
	std::cout << "\n\t3. Settings";
	std::cout << "\n\t4. Help / About";
	std::cout << "\n\t0. Exit\n";

	std::cout << "\n\tSelect Option: ";
	int selection{};
	std::cin >> selection;
	menuSelection = selection;
}

void MenuLoader::loadMainMenu(){
	clearScreen();
	std::cout << color::bold << color::cyan << "\t=================================\n";
	std::cout << "\t|\t Backtest Engine\t|\n";
	std::cout << "\t=================================\n" << color::reset;
	loadMenuOptions();
}

void MenuLoader::init(){
	loadMainMenu(); // Load the main menu with its options
	runMenuOption(); // Display the options internals

}
