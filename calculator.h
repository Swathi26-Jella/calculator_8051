#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H

void lcd_delay(unsigned int );
void lcd_cmd(unsigned char );
void dat(unsigned char );
void lcd_init(void);
void lcd_string(char *str);
char keypad_getkey(void);
void lcd_char(char ch);
void lcd_float(float );
void lcd_int(int );

#endif