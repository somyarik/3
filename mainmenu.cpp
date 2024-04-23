#include "menu.h"

mainmenu::mainmenu(std::string title, std::string maintitle) {
	this->title = title;
	this->maintitle = maintitle;
}

void mainmenu::exit() {
	system("cls");
}

void mainmenu::run() {
	std::cout << maintitle << std::endl << "Выберите способ входа" << std::endl;

	int i = 0;
	for (i; i < options.size();i++) {
		std::cout << i + 1 << ": " << options[i]->gettitle() << std::endl;
	}
	i++;
	std::cout << i << ": Выход" <<  std::endl;

	int choice;
	std::cout << "Выберите вариант: ";
	std::cin >> choice;
	if (choice < 0 || choice > i + 1) {
		system("cls");
		std::cout << "Выход за предел значений" << std::endl << std::endl;
		run();
	}
	if (choice <= options.size()) {
		system("cls");
		options[choice - 1]->run();
	}
	if (choice == i + 1) {
		exit();
	}
}