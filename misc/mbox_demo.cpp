#include <iostream>
#include "../include/message_box.hpp"

int main() {
    int choice = 0;
    std::cout << "Press 1 if you want a message box with a title, or 2 if you don't want a title: ";
    std::cin >> choice;
    std::string message = "This is a message box...\n\n...with a message!\n\nUse the arrow keys to select an option and press Enter to confirm.";
    std::vector<std::string> options = {"Option 1", "Option 2", "Option 3"};
    if(choice == 1) {
        std::string title = "My message box";
        try {
            MessageBox* mbox = new MessageBox(title, message, options);
            std::string selection = mbox->show();
            delete mbox;
            std::cout << "You selected: " << selection << std::endl;
        } catch(std::runtime_error &e) {
            std::cerr << e.what() << std::endl;
        }
    } else if(choice == 2) {
        try {
            MessageBox* mbox = new MessageBox(message, options);
            std::string selection = mbox->show();
            delete mbox;
            std::cout << "You selected: " << selection << std::endl;
        } catch(std::runtime_error &e) {
            std::cerr << e.what() << std::endl;
        }
    } else {
        std::cout << "Invalid choice" << std::endl;
    }
    return 0;
}
