#pragma once

class MenuLoader{
	private:
		int menuSelection{};

		void loadMainMenu();
		void loadMenuOptions();
		void runMenuOption();
	public:
		void init();
};
