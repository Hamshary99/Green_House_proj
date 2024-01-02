/* 
 * File:   uart_debug.h
 * Author: Mohammed Bahey El-Deen
 * LinkedIn: https://www.linkedin.com/in/mohammed-bahey-el-deen-656095198/
 * Created on December 31, 2023, 8:50 PM
 */

#include "uart_debug.h"

/* Sending string of bytes to UART one by one*/
void Send_String(uint8_t *str, uint8_t length){
    uint8_t l_String_Length = 0;
    for(l_String_Length = 0; l_String_Length < length; ++l_String_Length){
        EUSART_Write(*str++);
    }
}