#include "menu.h"

usermenu::usermenu(std::string title, std::string maintitle) {
	this->title = title;
	this->maintitle = maintitle;
}



void usermenu::goback() {
	(*parent)->run();
}

void usermenu::run() {
	std::cout << maintitle << std::endl << "Выберите опцию" << std::endl;

	int i = 0;
	for (i; i < options.size();i++) {
		std::cout << i + 1 << ": " << options[i]->gettitle() << std::endl;
	}
	i++;
	std::cout << i << ": Выход" << std::endl;

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