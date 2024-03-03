#include <iostream>
#include "../include/menu.hpp"

int main() {
    std::vector<std::string> items = {"Item 1", "Item 2", "Item 3", "Item 4"};
    Menu* menu = new Menu(items);
    std::string selection = menu->menu_navigation();
    delete menu;
    std::cout << "You selected: " << selection << std::endl;
    return 0;
}