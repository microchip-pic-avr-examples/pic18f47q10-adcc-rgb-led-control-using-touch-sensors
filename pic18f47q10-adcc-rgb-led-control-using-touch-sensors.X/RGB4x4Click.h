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

#ifndef RGB4X4CLICK_H
#define	RGB4X4CLICK_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <stdint.h>

#define TIMER_1s   0x3C8C
#define TIMER_2s   0x7918
#define TIMER_3s   0xB5A4
#define TIMER_4s   0xF230
    
#define MAX_SIZE  16 // total number of RGB LEDs
    
#define BRIGHTNESS_LEVEL_0   0x00
#define BRIGHTNESS_LEVEL_1   0x05
#define BRIGHTNESS_LEVEL_2   0x0A
#define BRIGHTNESS_LEVEL_3   0x0F
#define BRIGHTNESS_LEVEL_4   0x14
#define BRIGHTNESS_LEVEL_5   0x19
#define BRIGHTNESS_LEVEL_6   0x1E
#define BRIGHTNESS_LEVEL_7   0x23
#define BRIGHTNESS_LEVEL_8   0x28

#define RED_COLOR_MASK       0xFF0000 
#define GREEN_COLOR_MASK     0x00FF00
#define BLUE_COLOR_MASK      0x0000FF
#define YELLOW_COLOR_MASK    0xFFFF00
#define CYAN_COLOR_MASK      0x00FFFF
#define MAGENTA_COLOR_MASK   0xFF00FF
#define WHITE_COLOR_MASK     0xFFFFFF
    
uint32_t DiodeArray[MAX_SIZE];

/**
 * @Param
    8 bit color value
 * @Returns
    reversed character
 * @Description
    This routine reverse the given 8 bit data 
 */
uint8_t reverse(uint8_t AColor);

/**
 * @Param
 pass 24 bit RGB color & brightness value
 * @Returns
    none
 * @Description
    This routine sets the color and brightness of each of the 16 RGB leds in the matrix
 * one by one to the parameter specified by the 24 bit RGB color and brightness value 
 */
void FillScreen(uint32_t AColor);

/**
 * @Param
 * char ANum:RGB LED number 
 * AColor : 24 bit RGB color & brightness value
 * *AdiodeArray: address of the array containing the RGB color and brightness value for the particular RGB LED 
 * @Returns
    none
 * @Description
    This routine sets the color and brightness of the specified RGB led in the matrix
 * to the parameter specified by the 24 bit RGB color and brightness value 
  */
void RGBLed_SetDiode(uint8_t ANum, uint32_t AColor, uint32_t * AdiodeArray);

/**
 * @Param
 * ARGBColor : 24 bit RGB color & brightness value
 * *AdiodeArray: address of the array containing the RGB color and brightness value for the particular RGB LED 
 * @Returns
    none
 * @Description
    This routine changes the value of the diode array corresponding to the RGB led in the matrix
 * to the c specified by the 24 bit RGB color and brightness value 
  */
void RGBLed_InitDiode(uint32_t ARGBColor, uint32_t *AdiodeArray);

/**
 * @Param
 * *AdiodeArray: address of the array containing the RGB color and brightness value for the particular RGB LED 
 * @Returns
    none
 * @Description
    This routine sends 24 bit color and brightness value in terms of  zeros and ones as specified in the diode array  
  */
void RGBLed_SetColor(uint32_t *AdiodeArray);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    This routine maintains the reset delay of 50us after sending new 24 bit color and brightness value
*/
void RGBLed_ResetDelay(void);

#ifdef	__cplusplus
}
#endif

#endif	/* RGB4X4CLICK_H */

