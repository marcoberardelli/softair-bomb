#ifndef BUTTON_HPP
#define BUTTON_HPP


#define RED_BTN_PIN 3
#define BLUE_BTN_PIN 2

enum PressedButton {
    NONE,
    BLUE,
    RED
};


void init_RB_btns(bool enable);
void enable_RB_btns();
void disable_RB_btns();
void red_btn_INT();
void blue_btn_INT();
PressedButton read_button();
void clear_button_state();

#endif