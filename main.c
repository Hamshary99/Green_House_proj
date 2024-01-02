/**
 * Generated Main Source File
 *
 * Company:
    Microchip Technology Inc.
 *
 * File Name:
    main.c
 *
 * Author: 
    Mohammed Bahey El-Deen
 *
 * LinkedIn: 
    https://www.linkedin.com/in/mohammed-bahey-el-deen-656095198/
 * 
 * Created on December 31, 2024, 1:30 PM
*/

#include "mcc_generated_files/mcc.h"
#include "ECUAL/TC74/TC74.h"
#include "ECUAL/LDR/LDR.h"
#include "ECUAL/HS1101/HS1101.h"
#include "ECUAL/UART_Debug/uart_debug.h"


/*
                         Main application
 */
temperature_t temperature = 0;
adc_result_t bright = 0, moist = 0;

//Making the signals looking more pleasing to the eyes
void uart_draw_borders (void); 


void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    
    lcd_4bits_send_command(LCD_DDRAM_START);
    lcd_4bits_send_string_data_pos("Loading Device", ROW2, Column4);
    __delay_ms(1000);
    lcd_4bits_send_command(LCD_CLEAR);
    
    /* LCD variables menu */
    lcd_4bits_send_string_data_pos("Temp = ", ROW1, Column1);
    lcd_4bits_send_string_data_pos("Bright = ", ROW2, Column1);
    lcd_4bits_send_string_data_pos("Moist = ", ROW3, Column1);
    
    while (1)
    {
        temperature = Read_TC74(0x4D);
        bright = LDR_reading (channel_AN0);
        moist = read_HS1101_moist_percent(channel_AN1);
        
        /* Print to UART */
        uart_draw_borders();        
        print_temp_uart(temperature);
        print_bright_uart(bright);
        print_HS1101_uart(moist);
        
        /* Print into LCD */
        print_temp_LCD(temperature, ROW1, Column9);
        print_bright_LCD(bright, ROW2, Column11);
        print_HS1101_LCD(moist, ROW3, Column10);
        
        /* Actuators */
        /* Dual Fans, activated when temperature rises under the following conditions */

        //For Coding in Fahrenheit or Celsius values
#if THIS_IS_AMERICA == YES
        if ((temperature > 77) && (temperature < 122)) {
            Fan_1_SetHigh();
            Fan_2_SetLow();
        } else if (temperature > 122) {
            Fan_1_SetHigh();
            Fan_2_SetHigh();
        } else {
            Fan_1_SetLow();
            Fan_2_SetLow();
        }
#else
        if ((temperature > 25) && (temperature < 50)) {
            Fan_1_SetHigh();
            Fan_2_SetLow();
        } else if (temperature > 50) {
            Fan_1_SetHigh();
            Fan_2_SetHigh();
        } else {
            Fan_1_SetLow();
            Fan_2_SetLow();
        }
#endif
        
        /* Lamp is on when brightness falls under the following conditions */
        if(bright < 50){
            LED_1_SetHigh();
        }
        else {
            LED_1_SetLow();
        }
        
        /* Water Pump is on when soil moisture falls under the following conditions */
        if(moist < 50){
            Pump_SetHigh();
        }
        else {
            Pump_SetLow();
        }

        __delay_ms(1000);
    }
}

void uart_draw_borders (void){
    Send_String("----------------\r", 17);
}


/**
 End of File
*/