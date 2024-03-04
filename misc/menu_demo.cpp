#include <iostream>
#include "../include/menu.hpp"

int main() {
    int choice = 0;
    std::cout << "Press 1 if you want a window with a title, or 2 if you don't want a title: ";
    std::cin >> choice;
    std::vector<std::string> items = {"Item 1", "Item 2", "Item 3", "Item 4"};
    if(choice == 1) {
        std::string title = "Main Menu";
        try {
            Menu* menu = new Menu(title, items);
            std::string selection = menu->show();
            delete menu;
            std::cout << "You selected: " << selection << std::endl;
        } catch(std::runtime_error &e) {
            std::cerr << e.what() << std::endl;
        }
    } else if(choice == 2) {
        try {
            Menu* menu = new Menu(items);
            std::string selection = menu->show();
            delete menu;
            std::cout << "You selected: " << selection << std::endl;
        } catch(std::runtime_error &e) {
            std::cerr << e.what() << std::endl;
        }
    } else {
        std::cout << "Invalid choice" << std::endl;
    }
    return 0;
}