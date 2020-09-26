<!-- Please do not change this html logo with link -->
<a href="https://www.microchip.com" rel="nofollow"><img src="images/microchip.png" alt="MCHP" width="200"/></a>

## RGB LED Control using Touch

## Introduction
  
The PIC18FxxQ10 family of devices have advanced ADCC module, which supports hardware CVD feature for seamless integration of capacitive touch sensing capability to the applications.

This demo illustrates usage of ADC with computation (ADCC) and capacitive voltage division (CVD) modules present in Q10 family of MCUs, to control a 4x4 RGB LED click board using Microchip’s Curiosity HPC development board and QT7 Xplained Pro extension kit.

## Useful Links

- [PIC18F47Q10 Product Page](https://www.microchip.com/wwwproducts/en/PIC18F47Q10 "PIC18F47Q10 Product Page")
- [PIC18F47Q10 Code Examples on GitHub](https://github.com/microchip-pic-avr-examples?q=PIC18F47Q10&type=&language= "PIC18F47Q10 Code Examples on GitHub")
- [mTouch® Capacitive Sensing Library Module for Mplab® X Code Configurator User’s Guide.](http://ww1.microchip.com/downloads/en/DeviceDoc/40001852A.pdf "mTouch® Capacitive Sensing Library Module for Mplab® X Code Configurator User’s Guide.")


## Description

In this demo,

* PIC18F25Q10 (28-pin, SPDIP package) MCU is used to demonstrate peripheral features of the Q10 family of MCUs.
* The curiosity HPC development board is used as it supports two mikroBUS slots for MikroElektronika™ click boards and has got on-chip programmer and debugger.
* The QT7 Xplained PRO extension kit is used as it has got two touch buttons and a slider to detect the touch events to control 4x4 RGB click. The library support for touch is present in MCC (Microchip Code Configurator), which is intuitive and can be configured in few clicks.

The MCC library for PIC18F25Q10 MCU provides support for touch buttons and proximity sensors. The two buttons present on QT7 Xplained kit are configured to control the brightness and change the colors of RGB click. The buttons on QT7 has feedback LEDs to indicate the button press event, which can be controlled by the microcontroller.


## Software  Tools

- [MPLAB X IDE v5.40](https://www.microchip.com/mplab/mplab-x-ide "MPLAB X IDE v5.40")
- [XC8 Compiler v2.30](https://www.microchip.com/mplab/compilers "XC8 Compiler v2.20")
- [MCC Core v5.0.1](https://www.microchip.com/mplab/mplab-code-configurator "MPLAB Code Configurator")
- [mTouch Capacitive Sensing Library v2.90]()

**Note: For running the demo, the installed tool versions should be the same or later. This example is not tested with the previous versions.**

## Hardware connections

The following connections should be done between the Curiosity HPC board and QT7 Xplained PRO extension kit

|QT7 Xplained Pro | PIC18F47Q10 | 
|:---------:|:----------:|
| PIN4   - Y-LINE-1 |  RA2 |
| PIN6   - LED6     |  RD5 |
| PIN10  - Y-LINE-0 |  RD7 |
| PIN11  - LED7     |  RB2 |
| PIN19  - GND      |  GND |
| PIN20  - VCC      |  VDD |

<p align="center">
  <img width=auto height=auto src="images/hardwaresetup.png">
</p>

## Demo Hardware Setup

Plugin the 4x4 RGB click in mikroBUS slot1 of the curiosity HPC board. Additionally, RC0 should be shorted to RD0 via jumper for the working of 4x4 RGB LED click board. This is required as PIC18F25Q10 (28 pin device) doesn't have PORTD and the bit banging pin on the curiosity board for RGB click is present on RD0 pin.

## MCC settings

This section shows the settings used in the demo/example for various MCU modules configuration. These settings were done using the Microchip Code Configurator (MCC). Open MCC to look at the settings of the modules.

### System module settings:

In “Registers” view, RSTOSC is configured as HFINTOSC with HFFRQ = 64 MHz and CDIV = 1:1

<p align="center">
  <img width=auto height=auto src="images/clock.png">
</p>

### Pin manager settings:

Selected pins RB1 and RB3 as touch buttons, pins RB0 and RB2 to drive the feedback LEDs of touch buttons and RC0 to control RGB click.

<p align="center">
  <img width=auto height=auto src="images/pinManager.png">
  <br>Figure 2: System Configuration <br>
</p>

Customized the names of I/O pins as below. Configured the pins RD5 and RB2 as output and renamed them as LED1 and LED2 respectively. Also, configured RA7 as output and renamed the pin as RGBLED.

<p align="center">
  <img width=auto height=auto src="images/pinModule.png">
</p>

## mTouch settings:

### Hardware sensors:

<p align="center">
  <img width=auto height=auto src="images/mtouch1.png">
</p>

### Buttons:

<p align="center">
  <img width=auto height=auto src="images/button1.png">
</p>

### Sensor settings:

<p align="center">
  <img width=auto height=auto src="images/mtouch2.png">
</p>

### Button Settings:

<p align="center">
  <img width=auto height=auto src="images/button2.png">
</p>

## Timer 1 settings:

<p align="center">
  <img width=auto height=auto src="images/timer1.png">
</p>

## Timer 3 settings:

<p align="center">
  <img width=auto height=auto src="images/timer3.png">
</p>

## Operation

1. After making the above hardware connections, power on the board with micro USB cable.

2. Build demo firmware and load the generated hex file onto the PIC18F25Q10 MCU. When the demo firmware is loaded, red LEDs are turned on with lowest brightness.

<p align="center">
  <img width=auto height=auto src="images/intialsetup.png">
</p>

3. Pressing touch button 1 will increase the brightness.

<p align="center">
  <img width=auto height=auto src="images/speedincrease.png">
</p>

4. Pressing touch button 2 will decrease the brightness.

<p align="center">
  <img width=auto height=auto src="images/decreasingspeed.png">
</p>

5. When both the buttons are pressed together the color will change.

<p align="center">
  <img width=auto height=auto src="images/color1.png">
</p>


6. The state of buttons (i.e. finger touch/release event) can be visualized through the feedback LEDs present on the QT7 xplained pro kit.

7. The brightness levels can be adjusted by changing the macro values in the RGB4x4Click.h header file.

<p align="center">
  <img width=auto height=auto src="images/color2.png">
</p>

**Note:**

*1. Two timers are used to detect the duration of button press to handle various operations.*
2. If the buttons are pressed and released within 3 seconds , the necessary actions are taken (i.e. brightness control and color change).
3. If the buttons are pressed for more than 3 seconds, it will be detected as fault condition and no action will be taken.
4. This time out can be configured from 1 sec to 3 secs in the firmware using appropriate macro.
5. Don’t drive the LEDs to maximum brightness. Because it will generate excessive heat and draw more current than advisable (up to 0.7A), which could potentially damage the main board.
6. Do not touch the board when it is in use.

## Conclusion

This example shows how easy it is to enable capacitive touch interface by configuring ADCC and CVD modules of PIC18FxxQ10 MCUs through MCC wizard. Also, demonstrates usage of capacitive touch interface of Q10 MCUs for command and control applications.

