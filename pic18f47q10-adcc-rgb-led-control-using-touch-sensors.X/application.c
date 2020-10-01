// include files
#include "application.h"

void applicationTask(void) {
    // Add your application code
    MTOUCH_Service_Mainloop();
}

void processButtonTouch(enum mtouch_button_names button) {
    // feedback LEDs are active low
    switch(button) {
        case Button1:
            TMR1_StartTimer();
            gButton1Pressed = true;
            // give LED response when brightness is not maximum
            if(gBrightnessLevel != 8) {
               LED1_SetLow(); 
            }  
            if(gButton2Pressed) {
               LED2_SetLow();
               LED1_SetLow();
            }
            break;
        case Button2: 
            TMR3_StartTimer();
            gButton2Pressed = true;
            // give LED response when brightness is not minimum
            if(gBrightnessLevel != 0) {
                LED2_SetLow();
            }  
            if(gButton1Pressed) {
                LED1_SetLow();
                LED2_SetLow();
            }
            break;       
        default: 
            break;
    }    
}
 
void processButtonRelease(enum mtouch_button_names button) {
    uint16_t timerCount;
    // feedback LEDs are active low
    switch(button) {
        case Button1: 
            TMR1_StopTimer();
            timerCount = TMR1_ReadTimer();
            TMR1_WriteTimer(0x0000);
            gButton1Pressed = false;
            LED1_SetHigh();
            if(timerCount > TIMER_3s) {
                // timeout event, use the previous value
                updateLED(getBrightnessLevel(),getColorMask());                
                return;
            }
            // check if button 2 is also pressed, if yes make a flag high
            if(gButton2Pressed) {
                gWaitingForButton2Release = true;
            } else {
                // check if button 2 was waiting for button 1 release , if yes change the color
                if(gWaitingForButton1Release) {
                    gWaitingForButton1Release = false;
                    if(gColorMask == 6) {
                        gColorMask = 0;
                    } else {
                        gColorMask++;
                    }                                       
                } else {
                    // if button2 was not pressed , increase the brightness
                    if(gBrightnessLevel != 8) {
                        gBrightnessLevel++;
                    }
                }
                updateLED(getBrightnessLevel(),getColorMask());
            }                        
            break;
        case Button2:
            TMR3_StopTimer();
            timerCount = TMR3_ReadTimer();
            TMR3_WriteTimer(0x0000);
            gButton2Pressed = false;
            LED2_SetHigh();
            if(timerCount > TIMER_3s) {
                // timeout event, use the previous value
                updateLED(getBrightnessLevel(),getColorMask());
                return;
            }
            // check if button 1 is also pressed, if yes make a flag high
            if(gButton1Pressed) {
                gWaitingForButton1Release = true;
            } else {
                // check if button 1 was waiting for button 2 release , if yes change the color
                if(gWaitingForButton2Release) {
                    gWaitingForButton2Release = false;
                    if(gColorMask == 6) {
                        gColorMask = 0;
                    } else {
                        gColorMask++;
                    }            
                } else {
                    // if button1 was not pressed , decrease the brightness
                    if(gBrightnessLevel != 0) {
                        gBrightnessLevel--;
                    }
                }
                // send the new data to the 4x4 RGB click
                updateLED(getBrightnessLevel(),getColorMask());
            }
            break;        
        default: 
            break;
    }  
}

uint8_t getBrightnessLevel(void) {
    // return the corresponding brightness level
    switch (gBrightnessLevel) {
        case 0:
            return BRIGHTNESS_LEVEL_0;
        case 1:
            return BRIGHTNESS_LEVEL_1;
        case 2:
            return BRIGHTNESS_LEVEL_2;
        case 3:
            return BRIGHTNESS_LEVEL_3;
        case 4:
            return BRIGHTNESS_LEVEL_4;
        case 5:
            return BRIGHTNESS_LEVEL_5;
        case 6:
            return BRIGHTNESS_LEVEL_6;
        case 7:
            return BRIGHTNESS_LEVEL_7;
        case 8:
            return BRIGHTNESS_LEVEL_8;
        default:
            return BRIGHTNESS_LEVEL_1;            
    }
}

uint24_t getColorMask(void) {
    // return the corresponding color mask 
    switch (gColorMask) {
        case 0:
            return RED_COLOR_MASK;
        case 1:
            return GREEN_COLOR_MASK;
        case 2:
            return BLUE_COLOR_MASK;
        case 3:
            return YELLOW_COLOR_MASK;
        case 4:
            return CYAN_COLOR_MASK;
        case 5:
            return MAGENTA_COLOR_MASK;
        case 6:
            return WHITE_COLOR_MASK;    
        default:
            return RED_COLOR_MASK;            
    }
}

void updateLED(uint8_t brightnessLevel,uint24_t colorMask) {
    // replicate the brightness value to all colors and send data
    uint24_t replicateBrightness = ((uint24_t)brightnessLevel << 16) | (brightnessLevel << 8) | brightnessLevel;
    uint24_t color = replicateBrightness & colorMask;
    FillScreen(color);
}