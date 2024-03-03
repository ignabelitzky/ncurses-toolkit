#include <iostream>
#include "../include/menu.hpp"

int main() {
    int choice = 0;
    std::cout << "Press 1 if you want a window with a title, or 2 if you don't want a title: ";
    std::cin >> choice;
    if(choice == 1) {
        std::string title = "Main Menu";
        std::vector<std::string> items = {"Item 1", "Item 2", "Item 3", "Item 4"};
        Menu* menu = new Menu(title, items);
        std::string selection = menu->menu_navigation();
        delete menu;
        std::cout << "You selected: " << selection << std::endl;
    } else if(choice == 2) {
        std::vector<std::string> items = {"Item 1", "Item 2", "Item 3", "Item 4"};
        Menu* menu = new Menu(items);
        std::string selection = menu->menu_navigation();
        delete menu;
        std::cout << "You selected: " << selection << std::endl;
    } else {
        std::cout << "Invalid choice" << std::endl;
    }
    return 0;
}