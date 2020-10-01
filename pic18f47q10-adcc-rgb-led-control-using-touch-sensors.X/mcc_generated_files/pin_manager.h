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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.5
        Device            :  PIC18F47Q10
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.20 and above
        MPLAB 	          :  MPLAB X 5.40	
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

// get/set RA2 procedures
#define RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()              PORTAbits.RA2
#define RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetPullup()             do { WPUAbits.WPUA2 = 1; } while(0)
#define RA2_ResetPullup()           do { WPUAbits.WPUA2 = 0; } while(0)
#define RA2_SetAnalogMode()         do { ANSELAbits.ANSELA2 = 1; } while(0)
#define RA2_SetDigitalMode()        do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set RGBLED aliases
#define RGBLED_TRIS                 TRISAbits.TRISA7
#define RGBLED_LAT                  LATAbits.LATA7
#define RGBLED_PORT                 PORTAbits.RA7
#define RGBLED_WPU                  WPUAbits.WPUA7
#define RGBLED_OD                   ODCONAbits.ODCA7
#define RGBLED_ANS                  ANSELAbits.ANSELA7
#define RGBLED_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define RGBLED_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define RGBLED_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define RGBLED_GetValue()           PORTAbits.RA7
#define RGBLED_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define RGBLED_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define RGBLED_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define RGBLED_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define RGBLED_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define RGBLED_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define RGBLED_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define RGBLED_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set LED2 aliases
#define LED2_TRIS                 TRISBbits.TRISB2
#define LED2_LAT                  LATBbits.LATB2
#define LED2_PORT                 PORTBbits.RB2
#define LED2_WPU                  WPUBbits.WPUB2
#define LED2_OD                   ODCONBbits.ODCB2
#define LED2_ANS                  ANSELBbits.ANSELB2
#define LED2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define LED2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define LED2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define LED2_GetValue()           PORTBbits.RB2
#define LED2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define LED2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define LED2_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define LED2_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define LED2_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define LED2_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define LED2_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define LED2_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set LED1 aliases
#define LED1_TRIS                 TRISDbits.TRISD5
#define LED1_LAT                  LATDbits.LATD5
#define LED1_PORT                 PORTDbits.RD5
#define LED1_WPU                  WPUDbits.WPUD5
#define LED1_OD                   ODCONDbits.ODCD5
#define LED1_ANS                  ANSELDbits.ANSELD5
#define LED1_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define LED1_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define LED1_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define LED1_GetValue()           PORTDbits.RD5
#define LED1_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define LED1_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define LED1_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define LED1_SetPushPull()        do { ODCONDbits.ODCD5 = 0; } while(0)
#define LED1_SetOpenDrain()       do { ODCONDbits.ODCD5 = 1; } while(0)
#define LED1_SetAnalogMode()      do { ANSELDbits.ANSELD5 = 1; } while(0)
#define LED1_SetDigitalMode()     do { ANSELDbits.ANSELD5 = 0; } while(0)

// get/set RD7 procedures
#define RD7_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define RD7_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define RD7_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define RD7_GetValue()              PORTDbits.RD7
#define RD7_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define RD7_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define RD7_SetPullup()             do { WPUDbits.WPUD7 = 1; } while(0)
#define RD7_ResetPullup()           do { WPUDbits.WPUD7 = 0; } while(0)
#define RD7_SetAnalogMode()         do { ANSELDbits.ANSELD7 = 1; } while(0)
#define RD7_SetDigitalMode()        do { ANSELDbits.ANSELD7 = 0; } while(0)

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