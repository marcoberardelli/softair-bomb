#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <TM1637Display.h>
#include "display.hpp"
#include "countdown.hpp"

static LiquidCrystal_I2C lcd(0x27, 20, 4);
static TM1637Display segment(CLK_SEGMENT, DIO_SEGMENT);

static String lcd_text[2];


void init_lcd_display() {
    lcd_text[0] = "";
    lcd_text[1] = "";
    lcd.init();
    lcd.backlight();
}

void print_row_lcd(String text, uint8_t row=0) {

    (row == 0) ? print_lcd(text, lcd_text[1]) : print_lcd(lcd_text[0], text);
}

void print_lcd(String first_row, String second_row) {
    lcd.clear();
    lcd_text[0] = first_row;
    lcd_text[1] = second_row;

    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print(first_row);
    lcd.setCursor(0, 1);
    lcd.print(second_row);
}

void clear_lcd() {
    lcd.clear();
}

void lcd_off() {
    lcd.clear();
    lcd.noBacklight();
}

void lcd_on() {
    lcd.backlight();
}

void init_segment_display() {
    segment.setBrightness(0x0f);
}

void clear_segment() {
    segment.clear();
}

void segment_off() {
    segment.setBrightness(0, false);
}

void segment_on() {
    segment.setBrightness(0x0f, true);
}

void print_time_remaining(time_t game_time) {
    int time = (game_time.minutes*100) + game_time.seconds;
    segment.showNumberDecEx(time, 0b01000000, true);
}