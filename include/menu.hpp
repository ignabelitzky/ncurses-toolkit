#ifndef MENU_H
#define MENU_H

#include <ncurses.h>
#include <vector>
#include <string>

class Menu {
    public:
        Menu(std::vector<std::string> items);
        ~Menu();
        void print_menu();
        std::string menu_navigation();
    private:
        WINDOW *menuWin;
        std::vector<std::string> menuItems;
        int selectedItem;
};

#endif