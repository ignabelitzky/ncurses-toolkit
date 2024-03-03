#ifndef MENU_H
#define MENU_H

#include <ncurses.h>
#include <vector>
#include <string>

class Menu {
    public:
        Menu(std::vector<std::string> items);
        Menu(std::string title, std::vector<std::string> items);
        ~Menu();
        void print_menu();
        std::string menu_navigation();
    private:
        const int MENU_ITEM_HEIGHT_FACTOR = 2;
        const int MENU_ITEM_PADDING = 10;
        WINDOW *menuWin;
        std::string winTitle;
        std::vector<std::string> menuItems;
        int selectedItem;
        int height, width, start_y, start_x;
        void calculate_window_dimensions();
        int longest_menu_item();
};

#endif