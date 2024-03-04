#ifndef MESSAGE_BOX_H
#define MESSAGE_BOX_H

#include <vector>
#include <string>
#include <ncurses.h>
#include <stdexcept>

class MessageBox {
    public:
        MessageBox(std::string title, std::string message, std::vector<std::string> options);
        MessageBox(std::string message, std::vector<std::string> options);
        ~MessageBox();
        std::string show();
    private:
        void initialize(std::string title, std::string message, std::vector<std::string> options);
        void calculate_window_dimensions();
        bool fit_options();
        int options_length();
        void print_dialog_box();
        const int OPTIONS_PADDING = 5;
        WINDOW *messageBoxWin;
        std::string winTitle;
        std::string winMessage;
        std::vector<std::string> winOptions;
        int height, width, start_y, start_x;
        int selectedOption;
};

#endif