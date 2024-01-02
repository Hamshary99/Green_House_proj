/* 
 * File:   TC74.c
 * Author: Mohammed Bahey El-Deen
 * LinkedIn: https://www.linkedin.com/in/mohammed-bahey-el-deen-656095198/
 * Created on December 31, 2023, 5:33 PM
 */


#include "TC74.h"
#include "../UART_Debug/uart_debug.h"

/* @First Array is to print the value with measuring unit to UART byte by byte
 * @Second Array is to print the string of data to LCD
 */
static uint8_t temp_array[6], value_array[4];

temperature_t Read_TC74(i2c_address_t address){
    temperature_t value = 0;
    
    value = I2C_Read1ByteRegister(address, 0x00); //From TC74 Datasheet, it has no internal reg bits but 0x00
#if THIS_IS_AMERICA == YES
    value = (temperature_t)(value * 1.8 + 32);
#endif
    
    return value;
}

void print_temp_uart(uint8_t value){
    
    temp_array[0] = value / 100 + 0x30;     //For Hundreds if there's any
    temp_array[1] = value / 10 + 0x30;      //For Tens if there's any
    
    /* If value is higher than 100, when we divide it on 10 we may get incorrect numbers when converting to ASCII */
    if(temp_array[1] > '9'){
        temp_array[1] = temp_array[1] - 0x0A;
    }
    temp_array[2] = value % 10 + 0x30;      //For Ones
    temp_array[3] = ' ';                    // A space to separate the measuring unit from numbers
    
#if THIS_IS_AMERICA == YES
    temp_array[4] = 'F';                    //Measuring unit in Fahrenheit
#else
    temp_array[4] = 'C';                    //Measuring unit in Celsius
#endif
    
    temp_array[5] = '\r';                   //End of Line

    Send_String("Temp : ", 8);
    Send_String(temp_array, 6);             //Sending to UART digit by digit
}

void print_temp_LCD(uint8_t value, uint8_t row, uint8_t column){
    
    /* So the LCD can convert the input to ASCII properly*/
    convert_uint8_to_string(value, &value_array);
    
    /* Send String with a known Row and Column */
    lcd_4bits_send_string_data_pos(value_array, row, column);

    /* Estimating where should we put the measuring unit properly */
#if THIS_IS_AMERICA == YES
    lcd_4bits_send_char_data_pos('F', row, column + 4);
#else
    lcd_4bits_send_char_data_pos('C', row, column + 4);
#endif   
    
}