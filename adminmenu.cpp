#include "menu.h"

adminmenu::adminmenu(std::string title, std::string maintitle, mainmenu** parent) {
	this->title = title;
	this->maintitle = maintitle;
	this->parent = parent;
}

std::string adminmenu::getpassword() {
	return password;
}
bool adminmenu::getaccess() {
	return access;
}

bool adminmenu::checkpassword() {
	std::string password;
	std::cout << "Введите пароль: ";
	std::cin >> password;
	system("cls");
	if (this->password != password) {
		system("cls");
		std::cout << "Пароль неверный" << std::endl << std::endl;
	}
	access = (this->password == password);
	return (this->password == password);
}
void adminmenu::changepassword() {
	if (checkpassword()) {
		std::string password;
		std::cout << "Введите новый пароль: ";
		std::cin >> password;
		this->password = password;
		access = false;
		system("cls");
	}
	else {
		goback();
	}
}
void adminmenu::goback() {
	(*parent)->run();
}

void adminmenu::run() {
	if (!access) {
		if (!checkpassword()) {
			goback();
		}
	}
	std::cout << maintitle << std::endl << "Выберите действие" << std::endl;

	int i = 0;
	for (i; i < options.size();i++) {
		std::cout << i + 1 << ": " << options[i]->gettitle() << std::endl;
	}
	i++;
	std::cout << i << ": Сменить пароль" << std::endl;
	i++;
	std::cout << i << ": Назад" << std::endl;

	int choice;
	std::cout << "Выберите вариант: ";
	std::cin >> choice;
	if (choice < 0 || choice > i) {
		system("cls");
		std::cout << "Выход за предел значений" << std::endl << std::endl;
		run();
	}
	if (choice <= options.size()) {
		system("cls");
		std::cout << "переход в " << options[choice - 1]->getmaintitle() << std::endl;
		run();
	}
	if (choice == i-1) {
		system("cls");
		changepassword();
		run();
	}
	if (choice == i) {
		system("cls");
		goback();
	}
}