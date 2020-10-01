/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

#ifndef MAIN_H
#define	MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif

// include files    
#include "mcc_generated_files/mcc.h"
    
// global variables
volatile uint8_t gBrightnessLevel = 1;
volatile uint8_t gColorMask;
volatile bool gButton1Pressed;
volatile bool gButton2Pressed;
volatile bool gWaitingForButton1Release;
volatile bool gWaitingForButton2Release;
/**
   @Param
    none
   @Returns
    none
   @Description
    main application task
   @Example
    applicationTask();
 */
void applicationTask(void);

/**
   @Param
    none
   @Returns
    button number
   @Description
    callback function for button press
   @Example
    
 */
void processButtonTouch(enum mtouch_button_names button);

/**
   @Param
    none
   @Returns
    button number
   @Description
    callback function for button release
   @Example
    
 */
void processButtonRelease(enum mtouch_button_names button);

#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

