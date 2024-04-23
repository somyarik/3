#include "menu.h"

menu::menu() {

}

menu::menu(std::string title, std::string maintitle) {
	this->title = title;
	this->maintitle = maintitle;
}

std::string menu::gettitle() {
	return title;
}

std::string menu::getmaintitle() {
	return maintitle;
}

void menu::addoption(menu* option) {
	options.push_back(option);
}