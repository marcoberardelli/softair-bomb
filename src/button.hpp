#ifndef BUTTON_HPP
#define BUTTON_HPP
#define EI_NOTEXTERNAL

enum PressedButton {
    NONE,
    BLUE,
    RED
};

void enable_menu_btns();
PressedButton read_button();
void clear_button_state();

#endif