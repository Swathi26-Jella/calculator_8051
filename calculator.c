#include<reg51.h>
#include<string.h>
#include "calculator.h"
#include<stdio.h>

char key;
float num1 = 0, num2=0,result=0;
char op;
bit firstnum = 1; //flag to detect first or second number

//Function declarations
extern void lcd_delay(unsigned int ms);
extern void lcd_cmd(unsigned char cmd);
extern void dat(unsigned char dat);
extern void lcd_init(void);
extern void lcd_string(char *str);
extern char keypad_getkey(void);
extern void lcd_char(char ch);
extern void lcd_float(float );
extern void lcd_int(int );
int main(){
	lcd_init();
	lcd_cmd(0X01);  // to clear lcd
	lcd_cmd(0X80);  //to set cursor on first line
	lcd_string("CALCULATOR");
	lcd_cmd(0XC0);  // second row,first column
	while(1){
		key = keypad_getkey();
		if(key >= '0' && key<='9'){  //if key is number
			lcd_char(key);
			if(firstnum)
				num1 = num1 *10 +(key -'0'); //build first number
			else
				num2 = num2 *10 +(key -'0'); //build second number
		}
		else if(key == '+'|| key =='-'|| key =='*'|| key =='/'){
			op = key;
			lcd_char(op);
			firstnum = 0; //next inputs go to num2
		}
		else if(key == '='){
			lcd_char('=');
			switch(op){
				case '+': result = num1+num2; break;
				case '-': result = num1-num2; break;
				case '*': result = num1*num2; break;
				case '/': result = (num2!=0) ? (num1/num2):0; break;
				default: result = 0; break;
			}
			if(op == '/'){
				lcd_float(result);
			}
			else
				lcd_int(result);
			// reset for next calculation
			num1 = 0;
			num2 = 0;
			firstnum = 1;
			lcd_cmd(0XC0);  // second row,first column
		}
		else if(key == 'C'){
			num1 = num2 = result = 0;
			firstnum = 1;
			lcd_cmd(0X01);  // to clear lcd
			lcd_string("CALCULATOR");
			lcd_cmd(0XC0);  // second row,first column
		}
	}
}
