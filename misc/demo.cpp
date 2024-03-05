#include "../include/menu.hpp"
#include "../include/message_box.hpp"
#include <iostream>

int main()
{
    std::vector<std::string> items = {"Show a message box",
                                      "Show a message box without a title", "Show a menu with a title",
                                      "Show a menu without a title", "Exit"};
    std::string selection;
    do
    {
        try
        {
            Menu *menu = new Menu(" [Main menu] ", items);
            selection = menu->show();
            delete menu;
        }
        catch (std::runtime_error &e)
        {
            std::cerr << e.what() << std::endl;
        }

        if (selection == items.at(0))
        {
            std::vector<std::string> options = {"Accept", "Cancel", "Help"};
            try
            {
                MessageBox *message_box = new MessageBox(" [Message Box Title] ", "This is a message box...\n\nwith a title\n\nUse the arrow keys to select an option and press Enter to confirm.", options);
                selection = message_box->show();
                delete message_box;
            }
            catch (std::runtime_error &e)
            {
                std::cerr << e.what() << std::endl;
            }
        }
        else if (selection == items.at(1))
        {
            std::vector<std::string> options = {"Accept", "Cancel", "Help"};
            try
            {
                MessageBox *message_box = new MessageBox("This is a message box...\n\nwithout a title\n\nUse the arrow keys to select an option and press Enter to confirm.",
                                                         options);
                selection = message_box->show();
                delete message_box;
            }
            catch (std::runtime_error &e)
            {
                std::cerr << e.what() << std::endl;
            }
        }
        else if (selection == items.at(2))
        {
            std::vector<std::string> items = {"Item 1", "Item 2", "Item 3", "Item 4"};
            try
            {
                Menu *menu = new Menu(" [Main Menu Title] ", items);
                selection = menu->show();
                delete menu;
            }
            catch (std::runtime_error &e)
            {
                std::cerr << e.what() << std::endl;
            }
        }
        else if (selection == items.at(3))
        {
            std::vector<std::string> items = {"Item 1", "Item 2", "Item 3", "Item 4"};
            try
            {
                Menu *menu = new Menu(items);
                selection = menu->show();
                delete menu;
            }
            catch (std::runtime_error &e)
            {
                std::cerr << e.what() << std::endl;
            }
        }
        else if (selection == items.at(4))
        {
            std::cout << "Exiting..." << std::endl;
            break;
        }
        else
        {
            std::cout << "Invalid selection" << std::endl;
        }
    } while (selection != items.at(4));
    return 0;
}