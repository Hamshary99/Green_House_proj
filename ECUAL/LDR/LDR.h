/* 
 * File:   LDR.h
 * Author: Mohammed Bahey El-Deen
 * LinkedIn: https://www.linkedin.com/in/mohammed-bahey-el-deen-656095198/
 * Created on December 31, 2023, 5:41 PM
 */

#ifndef LDR_H
#define	LDR_H

/* ==================== Includes ==================== */
#include "../../mcc_generated_files/mcc.h"
#include "../UART_Debug/uart_debug.h"

/* ================== Macros Declaration ==================== */


/* ================== Macro Function Declaration ==================== */


/* ==================== Data Type Declaration ==================== */
typedef adc_result_t brightness_t;


/* ==================== Function Declaration ==================== */
/* Read the value of the LDR on its suited ADC channel */
brightness_t LDR_reading(adc_channel_t AN_channel);

/* Print the value to UART */
void print_bright_uart(uint8_t value);

/* Print the value to LCD */
void print_bright_LCD(uint8_t value, uint8_t row, uint8_t column);


#endif	/* LDR_H */

