#include "../include/menu.hpp"

Menu::Menu(std::vector<std::string> items) {
    initscr();
    noecho();
    curs_set(0);
    menuWin = newwin(LINES, COLS, 0, 0);
    keypad(menuWin, TRUE);
    box(menuWin, 0, 0);
    menuItems = items;
    selectedItem = 0;
}

Menu::~Menu() {
    delwin(menuWin);
    endwin();
}

void Menu::print_menu() {
    wclear(menuWin);
    box(menuWin, 0, 0);
    int y = 1;
    for(int i = 0; i < static_cast<int>(menuItems.size()); ++i) {
        i == selectedItem ? wattron(menuWin, A_REVERSE) : wattroff(menuWin, A_REVERSE);
        mvwprintw(menuWin, y, 1, menuItems.at(i).c_str());
        y++;
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