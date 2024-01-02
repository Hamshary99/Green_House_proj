/* 
 * File:   LDR.h
 * Author: Mohammed Bahey El-Deen
 * LinkedIn: https://www.linkedin.com/in/mohammed-bahey-el-deen-656095198/
 * Created on December 31, 2023, 5:41 PM
 */

#include "LDR.h"

/* @First Array is to print the value with measuring unit to UART byte by byte
 * @Second Array is to print the string of data to LCD
 */
static uint8_t brightness_array[5], value_array[4];

brightness_t LDR_reading(adc_channel_t AN_channel){
    brightness_t bright = 0;
    
    /* Read the value from the chosen ADC channel */
    bright = ADC_GetConversion (AN_channel);
    
    /* Mapping the ADC input, the ldr gave a range from 1023 to 49 ADC */
    bright = (uint8_t)(100 - ((bright - 49) * 0.102));
    
    return bright;
}

void print_bright_uart(uint8_t value){
    
    brightness_array[0] = value / 100 + 0x30;   //For Hundreds if there's any
    brightness_array[1] = value / 10 + 0x30;    //For Tens if there's any
    
    /* If value is higher than 100, when we divide it on 10 we may get incorrect numbers when converting to ASCII */
    if(brightness_array[1] > '9'){
        brightness_array[1] = brightness_array[1] - 0x0A;
    }
    
    brightness_array[2] = value % 10 + 0x30;    //For Ones
    brightness_array[3] = '%';                  //For Percentage
    brightness_array[4] = '\r';
    
    Send_String("Bright : ", 10);
    Send_String(brightness_array, 5);           //Sending to UART digit by digit
}

void print_bright_LCD(uint8_t value, uint8_t row, uint8_t column){
    
    /* So the LCD can convert the input to ASCII properly*/
    convert_uint8_to_string(value, &value_array);
    
    /* Send String with a known Row and Column */
    lcd_4bits_send_string_data_pos(value_array, row, column);
    
    /* Estimating where should we put the measuring unit properly */
    lcd_4bits_send_char_data_pos('%', row, column + 3);
}