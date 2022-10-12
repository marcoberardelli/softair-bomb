#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#define CLK_SEGMENT 4
#define DIO_SEGMENT 5

#include "countdown.hpp"

void init_lcd_display();
void print_row_lcd(String text, uint8_t row);
void print_lcd(String first_row, String second_row);
void clear_lcd();
void lcd_off();
void init_segment_display();
void clear_segment();
void segment_off();
void segment_on();
void print_time_remaining(time_t game_time);

#endif