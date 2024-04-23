#pragma once
#include <iostream>
#include <vector>

class menu
{
public:
	menu();
	menu(std::string title, std::string maintitle);

	std::string gettitle();
	std::string getmaintitle();

	void addoption(menu* option);

	virtual void run() = 0;
protected:
	std::string title = "Default";
	std::string maintitle = "Default";
	std::vector<menu*> options;
};

class mainmenu : public menu {
public:
	mainmenu(std::string title, std::string maintitle);
	
	void exit();

	void run();
private:
	
};

class adminmenu : public menu {
public:
	adminmenu(std::string title, std::string maintitle, mainmenu**parent);

	std::string getpassword();
	bool getaccess();

	bool checkpassword();
	void changepassword();
	void goback();

	void run();
private:
	std::string password = "admin";
	bool access = false;
	mainmenu** parent;
};

class usermenu : public menu {
public:
	usermenu(std::string title, std::string maintitle);



	void goback();

	void run();
private:
	mainmenu** parent;
};