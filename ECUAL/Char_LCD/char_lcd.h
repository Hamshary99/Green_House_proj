/* 
 * File:   char_lcd.h
 * Author: Mohammed Bahey El-Deen
 * LinkedIn: https://www.linkedin.com/in/mohammed-bahey-el-deen-656095198/
 * Created on December 31, 2023, 6:28 PM
 */

#ifndef CHAR_LCD_H
#define	CHAR_LCD_H

/* ====================== Includes ========================== */
#include "../../mcc_generated_files/mcc.h"


/* ================== Macros Declaration ==================== */
/*Commands*/
#define LCD_CLEAR                    0x01
#define LCD_RETURN_HOME              0x02
#define LCD_ENTRY_MODE               0x06
#define LCD_RETURN_HOME              0x02
#define LCD_DISPLAY_ON_CURSOR_OFF    0x0C
#define LCD_DISPLAY_OFF_CURSOR_OFF   0x08
#define LCD_CURSOR_ON_BLINK_ON       0x0F
#define LCD_CURSOR_ON_BLINK_OFF      0x0E
#define LCD_DISPLAY_SHIFT_RIGHT      0x1C
#define LCD_DISPLAY_SHIFT_LEFT       0x18
#define LCD_8BITS_2_LINE             0x38
#define LCD_4BITS_2_LINE             0x28
#define LCD_CGRAM_START              0x40
#define LCD_DDRAM_START              0x80 

/* Rows */
#define ROW1                          1
#define ROW2                          2
#define ROW3                          3
#define ROW4                          4

/* Columns */
#define Column1                       1
#define Column2                       2
#define Column3                       3
#define Column4                       4
#define Column5                       5
#define Column6                       6
#define Column7                       7
#define Column8                       8
#define Column9                       9
#define Column10                      10
#define Column11                      11
#define Column12                      12
#define Column13                      13
#define Column14                      14
#define Column15                      15
#define Column16                      16
#define Column17                      17
#define Column18                      18
#define Column19                      19
#define Column20                      20


/* ================== Macro Function Declaration ==================== */



/* ==================== Data Type Declaration ==================== */



/* ==================== Function Declaration ==================== */

/* Initializing the LCD to 4-bits mode */
void lcd_4bits_initialize (void);

/* Sends the needed command to LCD */
void lcd_4bits_send_command(uint8_t command);

/* Send character to LCD */
void lcd_4bits_send_char_data(uint8_t chr);

/* Send string of characters to LCD */
void lcd_4bits_send_string(uint8_t *str);

/* Send character with given location of where to put it */
void lcd_4bits_send_char_data_pos(uint8_t chr, uint8_t row, uint8_t col);

/* Send string of characters with given location of where to put it */
void lcd_4bits_send_string_data_pos(uint8_t *str, uint8_t row, uint8_t col);

/*Converts the string of numbers that are sent to its suitable ASCII form */
void convert_uint8_to_string(uint8_t value, uint8_t* str);

#endif	/* CHAR_LCD_H */

