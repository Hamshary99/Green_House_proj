/* 
 * File:   TC74.h
 * Author: Mohammed Bahey El-Deen
 * LinkedIn: https://www.linkedin.com/in/mohammed-bahey-el-deen-656095198/
 * Created on December 31, 2024, 11:45 PM
 */

#ifndef TC74_H
#define	TC74_H


/* ==================== Includes ==================== */
#include "../../mcc_generated_files/mcc.h"


/* ================== Macros Declaration ==================== */
#define YES                   1
#define NO                    0

/* Pick YES if you need to measure and code in Fahrenheit, keep in mind that the TC74 in the proteus uses Celsius */
#define THIS_IS_AMERICA      NO


/* ================== Macro Function Declaration ==================== */


/* ==================== Data Type Declaration ==================== */
typedef uint8_t temperature_t;



/* ==================== Function Declaration ==================== */

/* Read Temperature from I2C by TC74 Device */
temperature_t Read_TC74(i2c_address_t address);

/* Print the value to UART */
void print_temp_uart(uint8_t temperature);

/* Print the value to LCD */
void print_temp_LCD(uint8_t value, uint8_t row, uint8_t column);



#endif	/* TC74_H */

