#include "../include/menu.hpp"

Menu::Menu(std::vector<std::string> items) {
    initscr();
    noecho();
    curs_set(0);
    menuItems = items;
    selectedItem = 0;
    calculate_window_dimensions();
    menuWin = newwin(height, width, start_y, start_x);
    keypad(menuWin, TRUE);
    box(menuWin, 0, 0);
}

Menu::~Menu() {
    delwin(menuWin);
    endwin();
}

void Menu::print_menu() {
    wclear(menuWin);
    box(menuWin, 0, 0);
    int y = 2;
    for(int i = 0; i < static_cast<int>(menuItems.size()); ++i) {
        i == selectedItem ? wattron(menuWin, A_REVERSE) : wattroff(menuWin, A_REVERSE);
        int x = (width - menuItems.at(i).length()) / 2; // Calculate the x position to center the text
        mvwprintw(menuWin, y, x, menuItems.at(i).c_str());
        y += MENU_ITEM_HEIGHT_FACTOR;
    }
    wattroff(menuWin, A_REVERSE);
    wrefresh(menuWin);
}

std::string Menu::menu_navigation() {
    int key;
    while(true) {
        print_menu();
        key = wgetch(menuWin);
        switch(key) {
            case KEY_UP:
                selectedItem--;
                if(selectedItem == -1) {
                    selectedItem = menuItems.size() - 1;
                }
                break;
            case KEY_DOWN:
                selectedItem++;
                if(selectedItem == static_cast<int>(menuItems.size())) {
                    selectedItem = 0;
                }
                break;
            case 10:    // Enter key
                return menuItems.at(selectedItem);            
            default:
                break;
        }
    }
}

void Menu::calculate_window_dimensions() {
    int maxx, maxy; // Maximum x and y values of the screen
    getmaxyx(stdscr, maxy, maxx);

    height = menuItems.size() * MENU_ITEM_HEIGHT_FACTOR + 3;
    width = longest_menu_item() + MENU_ITEM_PADDING;
    start_y = (maxy - height) / 2;
    start_x = (maxx - width) / 2;
}

int Menu::longest_menu_item() {
    int longest = 0;
    for(int i = 0; i < static_cast<int>(menuItems.size()); ++i) {
        if(static_cast<int>(menuItems.at(i).length()) > longest) {
            longest = menuItems.at(i).length();
        }
    }
    return longest;
}