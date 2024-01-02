/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F46K20
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set channel_AN0 aliases
#define channel_AN0_TRIS                 TRISAbits.TRISA0
#define channel_AN0_LAT                  LATAbits.LATA0
#define channel_AN0_PORT                 PORTAbits.RA0
#define channel_AN0_ANS                  ANSELbits.ANS0
#define channel_AN0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define channel_AN0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define channel_AN0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define channel_AN0_GetValue()           PORTAbits.RA0
#define channel_AN0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define channel_AN0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define channel_AN0_SetAnalogMode()      do { ANSELbits.ANS0 = 1; } while(0)
#define channel_AN0_SetDigitalMode()     do { ANSELbits.ANS0 = 0; } while(0)

// get/set channel_AN1 aliases
#define channel_AN1_TRIS                 TRISAbits.TRISA1
#define channel_AN1_LAT                  LATAbits.LATA1
#define channel_AN1_PORT                 PORTAbits.RA1
#define channel_AN1_ANS                  ANSELbits.ANS1
#define channel_AN1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define channel_AN1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define channel_AN1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define channel_AN1_GetValue()           PORTAbits.RA1
#define channel_AN1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define channel_AN1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define channel_AN1_SetAnalogMode()      do { ANSELbits.ANS1 = 1; } while(0)
#define channel_AN1_SetDigitalMode()     do { ANSELbits.ANS1 = 0; } while(0)

// get/set LED_1 aliases
#define LED_1_TRIS                 TRISCbits.TRISC0
#define LED_1_LAT                  LATCbits.LATC0
#define LED_1_PORT                 PORTCbits.RC0
#define LED_1_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define LED_1_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define LED_1_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define LED_1_GetValue()           PORTCbits.RC0
#define LED_1_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define LED_1_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)

// get/set Pump aliases
#define Pump_TRIS                 TRISCbits.TRISC1
#define Pump_LAT                  LATCbits.LATC1
#define Pump_PORT                 PORTCbits.RC1
#define Pump_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define Pump_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define Pump_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define Pump_GetValue()           PORTCbits.RC1
#define Pump_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define Pump_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)

// get/set D4 aliases
#define D4_TRIS                 TRISDbits.TRISD0
#define D4_LAT                  LATDbits.LATD0
#define D4_PORT                 PORTDbits.RD0
#define D4_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define D4_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define D4_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define D4_GetValue()           PORTDbits.RD0
#define D4_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define D4_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)

// get/set D5 aliases
#define D5_TRIS                 TRISDbits.TRISD1
#define D5_LAT                  LATDbits.LATD1
#define D5_PORT                 PORTDbits.RD1
#define D5_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define D5_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define D5_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define D5_GetValue()           PORTDbits.RD1
#define D5_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define D5_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)

// get/set D6 aliases
#define D6_TRIS                 TRISDbits.TRISD2
#define D6_LAT                  LATDbits.LATD2
#define D6_PORT                 PORTDbits.RD2
#define D6_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define D6_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define D6_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define D6_GetValue()           PORTDbits.RD2
#define D6_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define D6_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)

// get/set D7 aliases
#define D7_TRIS                 TRISDbits.TRISD3
#define D7_LAT                  LATDbits.LATD3
#define D7_PORT                 PORTDbits.RD3
#define D7_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define D7_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define D7_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define D7_GetValue()           PORTDbits.RD3
#define D7_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define D7_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)

// get/set RS aliases
#define RS_TRIS                 TRISDbits.TRISD4
#define RS_LAT                  LATDbits.LATD4
#define RS_PORT                 PORTDbits.RD4
#define RS_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define RS_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define RS_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define RS_GetValue()           PORTDbits.RD4
#define RS_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define RS_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)

// get/set E aliases
#define E_TRIS                 TRISDbits.TRISD5
#define E_LAT                  LATDbits.LATD5
#define E_PORT                 PORTDbits.RD5
#define E_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define E_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define E_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define E_GetValue()           PORTDbits.RD5
#define E_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define E_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)

// get/set Fan_1 aliases
#define Fan_1_TRIS                 TRISDbits.TRISD6
#define Fan_1_LAT                  LATDbits.LATD6
#define Fan_1_PORT                 PORTDbits.RD6
#define Fan_1_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define Fan_1_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define Fan_1_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define Fan_1_GetValue()           PORTDbits.RD6
#define Fan_1_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define Fan_1_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)

// get/set Fan_2 aliases
#define Fan_2_TRIS                 TRISDbits.TRISD7
#define Fan_2_LAT                  LATDbits.LATD7
#define Fan_2_PORT                 PORTDbits.RD7
#define Fan_2_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define Fan_2_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define Fan_2_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define Fan_2_GetValue()           PORTDbits.RD7
#define Fan_2_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define Fan_2_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/