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
	std::cout << "������� ������: ";
	std::cin >> password;
	system("cls");
	if (this->password != password) {
		system("cls");
		std::cout << "������ ��������" << std::endl << std::endl;
	}
	access = (this->password == password);
	return (this->password == password);
}
void adminmenu::changepassword() {
	if (checkpassword()) {
		std::string password;
		std::cout << "������� ����� ������: ";
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
	std::cout << maintitle << std::endl << "�������� ��������" << std::endl;

	int i = 0;
	for (i; i < options.size();i++) {
		std::cout << i + 1 << ": " << options[i]->gettitle() << std::endl;
	}
	i++;
	std::cout << i << ": ������� ������" << std::endl;
	i++;
	std::cout << i << ": �����" << std::endl;

	int choice;
	std::cout << "�������� �������: ";
	std::cin >> choice;
	if (choice < 0 || choice > i) {
		system("cls");
		std::cout << "����� �� ������ ��������" << std::endl << std::endl;
		run();
	}
	if (choice <= options.size()) {
		system("cls");
		std::cout << "������� � " << options[choice - 1]->getmaintitle() << std::endl;
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