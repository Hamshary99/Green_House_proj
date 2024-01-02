/* 
 * File:   HS1101.h
 * Author: Mohammed Bahey El-Deen
 * LinkedIn: https://www.linkedin.com/in/mohammed-bahey-el-deen-656095198/
 * Created on January 1, 2024, 5:45 PM
 */

#ifndef HS1101_H
#define	HS1101_H


/* ==================== Includes ==================== */
#include "../../mcc_generated_files/mcc.h"
#include "../UART_Debug/uart_debug.h"


/* ================== Macros Declaration ==================== */



/* ================== Macro Function Declaration ==================== */


/* ==================== Data Type Declaration ==================== */
typedef adc_result_t moisture;



/* ==================== Function Declaration ==================== */

/* Since it relies on the percentage of moisture, we convert the ADC input into Percentage*/
moisture read_HS1101_moist_percent(adc_channel_t AN_channel);

/* Print the value to UART */
void print_HS1101_uart(uint8_t value);

/* Print the value to LCD */
void print_HS1101_LCD(uint8_t value, uint8_t row, uint8_t column);


#endif	/* HS1101_H */

