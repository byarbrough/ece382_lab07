Robot9_IR_Readme
Brian Yarbrough
---------------------------

This Library is designed specifically for USAFA DFEC ECE382 Robot #9, using a TI MSP430G2553.
While the methods will be similar for other robots, specific values will not be exact.

The header file contains the defined functions and threshold values for each IR sensor.
The .c file is an implementation of these methods.
The get methods return the digital value that each respective sensor is reading as an unsigned short.

Recommended use of this file is to compare the get methods to the thresholds and respond accordingly.

-----------------
IR Sensors Vcc = +5 V
Resolution: 4.89 mV/ level
Left Sensor: P1.3
Right Sensor: P1.5
Front Sensor: P1.4