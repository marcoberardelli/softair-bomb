#include <Arduino.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);

void lcd_print(String text) {
    lcd.backlight();
    lcd.println(text);
}

void lcd_clear() {
    lcd.clear();
}

void lcd_off() {
    lcd.clear();
    lcd.noBacklight();
}

void init_display() {
    lcd.init();
    lcd.backlight();
}