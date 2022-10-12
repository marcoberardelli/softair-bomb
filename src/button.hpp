#ifndef BUTTON_HPP
#define BUTTON_HPP

enum PressedButton {
    NONE,
    BLUE,
    RED
};

void enable_menu_btns();
PressedButton read_button();
void clear_button_state();

#endif