/* 
 * File:   HS1101.c
 * Author: Mohammed Bahey El-Deen
 * LinkedIn: https://www.linkedin.com/in/mohammed-bahey-el-deen-656095198/
 * Created on January 1, 2024, 5:45 PM
 */

#include "HS1101.h"

/* @First Array is to print the value with measuring unit to UART byte by byte
 * @Second Array is to print the string of data to LCD
 */
static uint8_t moist_array[5], value_array[4];

moisture read_HS1101_moist_percent(adc_channel_t AN_channel){
    moisture moist = 0;
    
    /* Read the value from the chosen ADC channel */
    moist = ADC_GetConversion (AN_channel);
    
    /* Mapping the ADC input, the sensor gave a range from 0 to 1023 ADC */
    moist = (uint8_t)(100 - (moist * 0.09775));
    
    return moist;
}


void print_HS1101_uart(uint8_t value){
    
    moist_array[0] = value / 100 + 0x30;        //For Hundreds if there's any
    moist_array[1] = value / 10 + 0x30;         //For Tens if there's any
    
    /* If value is higher than 100, when we divide it on 10 we may get incorrect numbers when converting to ASCII */
    if(moist_array[1] > '9'){
        moist_array[1] = moist_array[1] - 0x0A;
    }
    
    moist_array[2] = value % 10 + 0x30;         //For Ones
    moist_array[3] = '%';                       //For Percentage
    moist_array[4] = '\r';
    
    Send_String("Moist : ", 9);
    Send_String(moist_array, 5);                //Sending to UART digit by digit
}

void print_HS1101_LCD(uint8_t value, uint8_t row, uint8_t column){
    
    /* So the LCD can convert the input to ASCII properly*/
    convert_uint8_to_string(value, &value_array);
    
    /* Send String with a known Row and Column */
    lcd_4bits_send_string_data_pos(value_array, row, column);
    
    /* Estimating where should we put the measuring unit properly */
    lcd_4bits_send_char_data_pos('%', row, column + 3);
}