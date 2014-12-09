ece382_lab07
============

[Lab 7 - A/D Conversion - "Robot Sensing"](http://ece382.com/labs/lab7/index.html)

##Prelab

The first thing that I am going to do for my prelab is remove the IR sensor that I used for the last lab. I will then use the DMM to verify that all of the sensors are working correctly. Following this I will be ready to begin wiring and coding and all kinds of fun stuff.

###Code
Most of the necessary code is already provided [here](http://ecse.bd.psu.edu/cmpen352/lecture/code/lec36.c), so I will mostly just use that. I plan on making very nice methods so that I can incorporate it into a library. Doing that should grant an easier time during Lab 8.

###Making it "For Realz"
First, yes, I checked all of my sensors and wiring and they work pristinely.

For required functionality, I want my LED to turn on when the robot is roughly a fist length away from the wall. This is definitely subject to change, but it seems like a good distance to begin with. When I placed the robot in the maze I came up with the following table:

These yield an average of _2.538_ and _1.2768_ for HIGH and LOW, respectively. As such, I want to make my threshold half way between these two values: _CENTER THRESHOLD VOLTAGE = 1.9 V_.

Yes, this is somewhat coarse. For one, I did all of these in the maze closest to the lockers; the other mazes are likely different due to ambient light. I will deal with that an finer calibration later. What would be super cool is if I wrote a program to calibrate the sensors automatically... hmmm...

For turning the LED on or off, having a threshold voltage is critical. The code that I mentioned earlier already is configured to toggle 1.0 based on analog input on 1.4. That means that all there really is left to do is change the if statement to reflect 1.9 V. I have to do a little math to do this, but it isn't too bad.

###ADC Math
The converter uses ten bits. That means that I have 2^10, or 1024 quantization levels. Thus, each level accounts for 5V/1024 = _4.89 mV per level_. From this, I can determine my expected level to be: (input - min)/dV. So, for my threshold voltage of 1.9 V, I am looking at 388.5, or 0x185. Let's throw that in the program and try it out! 

###And the verdict is....
Success! Or, temporary success that is. While sitting on my desk, the single light worked with the front sensor just fine. When I brought it over to the maze however, it stopped working. What?!?!?

Well, I took it back to my desk, reconnected the DMM to verify that the signals were being read properly, and it worked!. Then I disconnected the DMM to take it back to the maze and wait just one minute! The LED stopped working! From this I realized that it only worked while I was measuring DC voltage with the multimeter. I voiced my problem and H mentioned that someone else had used a resistor to fix the problem. I connected a DMM set to measure resistance connected to one measuring DC voltage and got ~ 11 M ohms. Putting a 10 M resistor between the signal and ground modeled the DMM enough that my LED started working again. This is actually a cool connection to ECE 321, where we have had some issues with internal resistances of scopes messing with data.

####Moving Average
While I was in the 321 lab, I also grabbed some 1 nF capacitors and stuck them between the signal and ground. I think that a little extra hardware to smooth the analog signal is worth not having to program a moving average function. This will hopefully help smooth out weird voltage fluctuations.

##B Functionality
From here I just had to make all three sensors work simultaneously. I realized that to do this I might as well make a library, which I did. It contains its own header and implementation file, as well as a Readme that details its functions. I used it to implement the required functionality, and plan on using it for the maze as well.

##A Functionality
The first time I attempted to characterizet the sensors, I got a funny linear relationship. So I added some electirc tape blinders to the sensors and tried again.
I characterized the three sensors according to these tables and charts.

__FRONT SENSOR__

| Distance | Value 1 | Value 2 | Average | Convert | Hex |
|:--------:|:-------:|:-------:|---------|---------|-----|
| 12       |  0.251  |  0.260  | 0.256   | 80      | 50  |
| 11       |  0.266  |  0.275  | 0.271   | 84      | 54  |
| 10       |  0.287  |  0.293  | 0.290   | 90      | 5A  |
| 9        | 0.324   | 0.333   | 0.329   | 102     | 66  |
| 8        | 0.369   | 0.371   | 0.370   | 115     | 73  |
| 7        | 0.439   | 0.439   | 0.439   | 137     | 89  |
| 6        | 0.519   | 0.526   | 0.523   | 163     | A3  |
| 5        | 0.619   | 0.630   | 0.625   | 194     | C2  |
| 4        | 0.759   | 0.773   | 0.766   | 238     | EE  |
| 3        | 0.806   | 0.889   | 0.848   | 263     | 107 |
| 2        | 0.543   | 0.670   | 0.607   | 189     | BD  |
| 1        | 0.124   | 0.154   | 0.139   | 44      | 2C  |

![alt text](https://raw.githubusercontent.com/byarbrough/ece382_lab07/master/Images/front_chart.PNG "Fronnt")

__RIGHT SENSOR__

| Distance | Value 1 | Value 2 | Average | Convert | Hex |
|:--------:|:-------:|:-------:|---------|---------|-----|
| 12       |   0.90  |   0.87  | 0.885   | 275     | 113 |
| 11       |   1.00  |   0.91  | 0.954   | 297     | 129 |
| 10       |   1.03  |   1.02  | 1.025   | 319     | 13F |
| 9        | 1.16    | 1.16    | 1.160   | 360     | 168 |
| 8        | 1.36    | 1.34    | 1.350   | 419     | 1A3 |
| 7        | 1.68    | 1.55    | 1.615   | 502     | 1F6 |
| 6        | 1.99    | 2.00    | 1.995   | 620     | 26C |
| 5        | 2.60    | 2.52    | 2.560   | 795     | 31B |

![alt text](https://raw.githubusercontent.com/byarbrough/ece382_lab07/master/Images/right_chart.PNG "Right")

__LEFT SENSOR__

| Distance | Value 1 | Value 2 | Average | Convert | Hex |
|:--------:|:-------:|:-------:|---------|---------|-----|
| 12       |  0.412  |  0.429  | 0.421   | 131     | 83  |
| 11       |  0.428  |  0.432  | 0.430   | 134     | 86  |
| 10       |  0.475  |  0.481  | 0.478   | 149     | 95  |
| 9        | 0.548   | 0.539   | 0.544   | 169     | A9  |
| 8        | 0.663   | 0.609   | 0.636   | 198     | C6  |
| 7        | 0.765   | 0.741   | 0.753   | 234     | EA  |
| 6        | 0.948   | 0.877   | 0.913   | 284     | 11C |
| 5        | 1.23    | 1.25    | 1.240   | 385     | 181 |
| 4        | 1.75    | 1.81    | 1.778   | 552     | 228 |
| 3        | 2.74    | 2.65    | 2.695   | 837     | 345 |

![alt text](https://raw.githubusercontent.com/byarbrough/ece382_lab07/master/Images/left_chart.PNG "Left")

There are a couply of things worth noting from these table. First, different walls and ambient lighting definitely have an effect on values. Second, the readings become unreliable closer than 3 inches or so because either the sensors max our at 0x3FF or the numbers drop off because the sleeve on the sensor blocks too much light.
Also, note that the lines of best fit are most likely logrithmic, but they can be approximated well with an second order polynomial. Because the MSP430 cannot do floating point or natural log, having these equations are much more useful for calculating exact distances than ln() would be.

Also, the right sensor is much more sensitive than the other two sesnors. This means that I will have to do some extra calibration if I want to directly compare the two sensor readings... or I might just try a voltage divider. 

##Documentation
Other than the brief comment about the resistor that I mentioned, I knocked this one out all by myself.
