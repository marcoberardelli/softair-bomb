#ifndef BUTTON_HPP
#define BUTTON_HPP


#define BLUE_BTN_PIN 8
#define RED_BTN_PIN 9


enum PressedButton {
    NONE,
    BLUE,
    RED
};

void enable_menu_RB_btns();
void red_btn_INT();
void blue_btn_INT();
PressedButton read_button();
void clear_button_state();

#endif