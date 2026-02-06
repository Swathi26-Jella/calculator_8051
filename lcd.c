#inciude<reg51.h>
#include"calculator.h"
#include<stdio.h>

#define lcd_data P3
sbit en = P2^7; //E pin for LCD
sbit rs = P2^6;//RS pin for LCD

void lcd_delay (unsigned int ms);
void lcd_cmd (unsigned char cmd) ; 
void dat (unsigned char dat) ;
void lcd_init(void);
void lcd_string (char *str);
void lcd_char (char);
void lcd_float (float);
void lcd_int (int);

void lcd_init(void){
  lcd_delay (20);
  lcd_cmd (0X38);
  lcd_cmd (0X0E):
  lcd_cmd (0X01);
  lcd_cmd (0X06);
  lcd_cmd (0X0C);
  lcd_cmd (0X80);
  lcd_delay(2);
}
void lcd_cmd (unsigned char cmd){
  lcd_data = cmd;
  rs = 0;
  en = 1;
  lcd_delay (2) ;
  en = 0;
}
void dat (unsigned char dat){
  lcd_data = dat;
  rs = 1;
  en = 1;
  lcd_delay (2) ;
  en = 0;
}

void lcd_string (char *str) {
  while (*str) {
    dat (*str++);
}

void lcd_delay(unsigned int ms){
  unsigned int i,j;
  for (1 =0;i<ms;i++) 
    for(j=0;j<2000;j++);
}

void lcd_char (char ch) {
  lcd_data = ch;
  rs = 1;
  en = 1;
  lcd_delay (2);
  en = 0;
}
void lcd_int (int num) {
  char buf [10];
  int i;
  sprintf (buf, "%d", num); // int to ascii
  for(i=0;buf[i] != '\0';i++){
    dat (buf [i]);
   }
}
void lcd_float (float num) {
  char buf [16];
  int i;
  sprintf (buf, "%.2f", num); 
  for(i=0;buf[i] != '\0';i++){
    dat (buf [i]);
   }
}
