#include <iostream>
#include "menu.h"

int main()
{
    
    setlocale(LC_ALL, "Russian");
    mainmenu* main = new mainmenu("что", "Главное меню");
    std::cout << main->gettitle() << std::endl;
    std::cout << main->getmaintitle() << std::endl;

    adminmenu* admin = new adminmenu("Администратор", "Средства администрирования", &main);
    std::cout << admin->getpassword() << std::endl;
    std::cout << admin->getmaintitle() << std::endl;

    usermenu* user = new usermenu("Пользователь", "Меню пользователя");
    std::cout << user->gettitle() << std::endl;
    std::cout << user->getmaintitle() << std::endl;
    
    system("cls");

    main->addoption(admin);
    main->addoption(user);
    main->run();
}

