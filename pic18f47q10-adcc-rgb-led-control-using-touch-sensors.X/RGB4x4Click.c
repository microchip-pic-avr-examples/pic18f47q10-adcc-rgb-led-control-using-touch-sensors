// include files
#include "RGB4x4Click.h"
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pin_manager.h"

#define RGBLed_OneBit() RGBLED_SetHigh(); \
_delay(10); \
RGBLED_SetLow();

#define RGBLed_ZeroBit() RGBLED_SetHigh(); \
_delay(5); \
RGBLED_SetLow(); \
_delay(4); 
        
uint8_t reverse(uint8_t b) {
   b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
   b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
   b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
   return b;
}

void FillScreen(uint32_t AColor) {
  uint8_t n;
  for (n=1; n<=16; n++) {
    RGBLed_SetDiode(n, AColor, DiodeArray);
  }
}

void RGBLed_SetDiode(uint8_t ANum, uint32_t AColor, uint32_t * AdiodeArray) {
  uint8_t i;
  RGBLed_InitDiode(AColor, &AdiodeArray[ANum - 1]);
  for (i = 0; i < MAX_SIZE; i++) {
      RGBLed_SetColor(&AdiodeArray[i]);
  }
  // dummy write to turn on 16th LED
  RGBLed_SetColor(&AdiodeArray[0]);
  RGBLed_ResetDelay();
}

void RGBLed_InitDiode(uint32_t ARGBColor, uint32_t *AdiodeArray) {
    // reverse the data and store it at appropriate array index
    *AdiodeArray = ((uint32_t)(reverse(ARGBColor & 0x000000FF)) << 16) |
           ((uint32_t)(reverse(ARGBColor >> 16)) << 8) | reverse(ARGBColor >> 8);
}

void RGBLed_SetColor(uint32_t *AdiodeArray) {
    // send the 24 bits of data
    // unrolled the loop to have proper timing for 4x4 click
    uint32_t tempData = *AdiodeArray;
    if(tempData & 1) {
        RGBLed_OneBit();
    } else {
        RGBLed_ZeroBit();
    }
    tempData >>= 1;
    if(tempData & 1) {
        RGBLed_OneBit();
    } else {
        RGBLed_ZeroBit();
    }
    tempData >>= 1;
    if(tempData & 1) {
        RGBLed_OneBit();
    } else {
        RGBLed_ZeroBit();
    }
    tempData >>= 1;
    if(tempData & 1) {
        RGBLed_OneBit();
    } else {
        RGBLed_ZeroBit();
    }
    tempData >>= 1;
    if(tempData & 1) {
        RGBLed_OneBit();
    } else {
        RGBLed_ZeroBit();
    }
    tempData >>= 1;
    if(tempData & 1) {
        RGBLed_OneBit();
    } else {
        RGBLed_ZeroBit();
    }
    tempData >>= 1;
    if(tempData & 1) {
        RGBLed_OneBit();
    } else {
        RGBLed_ZeroBit();
    }
    tempData >>= 1;
    if(tempData & 1) {
        RGBLed_OneBit();
    } else {
        RGBLed_ZeroBit();
    }
    tempData >>= 1;
    if(tempData & 1) {
        RGBLed_OneBit();
    } else {
        RGBLed_ZeroBit();
    }
    tempData >>= 1;
    if(tempData & 1) {
        RGBLed_OneBit();
    } else {
        RGBLed_ZeroBit();
    }
    tempData >>= 1;
    if(tempData & 1) {
        RGBLed_OneBit();
    } else {
        RGBLed_ZeroBit();
    }
    tempData >>= 1;
    if(tempData & 1) {
        RGBLed_OneBit();
    } else {
        RGBLed_ZeroBit();
    }
    tempData >>= 1;
    if(tempData & 1) {
        RGBLed_OneBit();
    } else {
        RGBLed_ZeroBit();
    }
    tempData >>= 1;
    if(tempData & 1) {
        RGBLed_OneBit();
    } else {
        RGBLed_ZeroBit();
    }
    tempData >>= 1;
    if(tempData & 1) {
        RGBLed_OneBit();
    } else {
        RGBLed_ZeroBit();
    }
    tempData >>= 1;
    if(tempData & 1) {
        RGBLed_OneBit();
    } else {
        RGBLed_ZeroBit();
    }
    tempData >>= 1;
    if(tempData & 1) {
        RGBLed_OneBit();
    } else {
        RGBLed_ZeroBit();
    }
    tempData >>= 1;
    if(tempData & 1) {
        RGBLed_OneBit();
    } else {
        RGBLed_ZeroBit();
    }
    tempData >>= 1;
    if(tempData & 1) {
        RGBLed_OneBit();
    } else {
        RGBLed_ZeroBit();
    }
    tempData >>= 1;
    if(tempData & 1) {
        RGBLed_OneBit();
    } else {
        RGBLed_ZeroBit();
    }
    tempData >>= 1;
    if(tempData & 1) {
        RGBLed_OneBit();
    } else {
        RGBLed_ZeroBit();
    }
    tempData >>= 1;
    if(tempData & 1) {
        RGBLed_OneBit();
    } else {
        RGBLed_ZeroBit();
    }
    tempData >>= 1;
    if(tempData & 1) {
        RGBLed_OneBit();
    } else {
        RGBLed_ZeroBit();
    }
    tempData >>= 1;
    if(tempData & 1) {
        RGBLed_OneBit();
    } else {
        RGBLed_ZeroBit();
    }
    tempData >>= 1;
}

void RGBLed_ResetDelay() {
  __delay_us(50);
  __delay_us(10);
}
