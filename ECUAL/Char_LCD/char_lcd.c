/* 
 * File:   char_lcd.c
 * Author: Mohammed Bahey El-Deen
 * LinkedIn: https://www.linkedin.com/in/mohammed-bahey-el-deen-656095198/
 * Created on December 31, 2023, 6:28 PM
 */

#include "char_lcd.h"

static void lcd_send_4bits(uint8_t data);
static void lcd_4bits_send_enable(void);
static void lcd_4bits_pos(uint8_t row, uint8_t column);



void lcd_4bits_initialize (void){
    
    __delay_ms(20);
    lcd_4bits_send_command(LCD_8BITS_2_LINE);
    __delay_ms(5);
    lcd_4bits_send_command(LCD_8BITS_2_LINE);
    __delay_us(150);
    lcd_4bits_send_command(LCD_8BITS_2_LINE);
    lcd_4bits_send_command(LCD_CLEAR);
    lcd_4bits_send_command(LCD_RETURN_HOME);
    lcd_4bits_send_command(LCD_ENTRY_MODE);
    lcd_4bits_send_command(LCD_DISPLAY_ON_CURSOR_OFF);
    lcd_4bits_send_command(LCD_4BITS_2_LINE);
    lcd_4bits_send_command(LCD_DDRAM_START);
    
}

void lcd_4bits_send_command(uint8_t command){
    RS_SetLow();
    lcd_send_4bits(command >> 4);
    lcd_4bits_send_enable();
    lcd_send_4bits(command);
    lcd_4bits_send_enable();
}


void lcd_4bits_send_char_data(uint8_t chr){
    RS_SetHigh();
    lcd_send_4bits((chr >> 4));
    lcd_4bits_send_enable();
    lcd_send_4bits(chr);
    lcd_4bits_send_enable();
}

void lcd_4bits_send_string(uint8_t *str){
    
    while(*str){
        lcd_4bits_send_char_data(*str++);
    }
}

void lcd_4bits_send_char_data_pos(uint8_t chr, uint8_t row, uint8_t col){
    
    lcd_4bits_pos(row, col);
    lcd_4bits_send_char_data(chr);
}


void lcd_4bits_send_string_data_pos(uint8_t *str, uint8_t row, uint8_t col){
    lcd_4bits_pos(row, col);
    
    while(*str){
        lcd_4bits_send_char_data(*str++);
    }
}

static void lcd_send_4bits(uint8_t data){
    LATDbits.LATD0 = (data >> 0) & 0x01;
    LATDbits.LATD1 = (data >> 1) & 0x01;
    LATDbits.LATD2 = (data >> 2) & 0x01;
    LATDbits.LATD3 = (data >> 3) & 0x01;
}

static void lcd_4bits_send_enable(void){
    E_SetHigh();
    __delay_ms(5);
    E_SetLow();
}

static void lcd_4bits_pos(uint8_t row, uint8_t column){
    column--;
    switch(row){
        case ROW1: lcd_4bits_send_command(0x80 + column); break;
        case ROW2: lcd_4bits_send_command(0xC0 + column); break;
        case ROW3: lcd_4bits_send_command(0x94 + column); break;
        case ROW4: lcd_4bits_send_command(0xD4 + column); break;
    }
}

/* To write numbers in LCD with the extra NULL termination */
void convert_uint8_to_string(uint8_t value, uint8_t* str) {
    
    uint8_t TempStr[4] = {0, 0, 0, 0}; //Since LCD stores the last digit until overwritten we need this to put null only at the end of digits
    uint8_t data = 0;
       memset(str, ' ', 3);
       str[4] = '\0'; 
       sprintf((char *)TempStr, "%i" ,value); 
       while(TempStr[data] != '\0'){
           str[data] = TempStr[data];
           data++;
       }
    
}