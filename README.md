ece382_lab07
============

[Lab 7 - A/D Conversion - "Robot Sensing"](http://ece382.com/labs/lab7/index.html)

##Prelab

The first thing that I am going to do for my prelab is remove the IR sensor that I used for the last lab. I will then use the DMM to verify that all of the sensors are working correctly. Following this I will be ready to begin wiring and coding and all kinds of fun stuff.

###Code
Most of the neaccesary code is already provided [here](http://ecse.bd.psu.edu/cmpen352/lecture/code/lec36.c), so I will mostly just use that. I plan on making very nice methods so that I can incorporate it into a library. Doing that should grant an easier time during Lab 8.

###Making it "For Realz"
First, yes, I checked all of my sensors and wiring and they work pristinely.

For required functionality, I want my LED to turn on when the robot is roughly a fist length away from the wall. This is definitely subject to change, but it seems like a good distance to begin with. When I placed the robot in the maze I came up with the following table:

These yield an average of _2.538_ and _1.2768_ for HIGH and LOW, respectively. As such, I want to make my threshold half way between these two values: _CENTER THRESHOLD VOLTAGE = 1.9 V_.

Yes, this is somewhat coarse. For one, I did all of these in the maze closest to the lockers; the other mazes are likely different due to ambient light. I will deal with that an finer calibration later. What would be super cool is if I wrote a program to calibrate the sensors automatically... hmmm...

For turning the LED on or off, having a threshold voltage is critical. The code that I mentioned earlier already is configured to toggle 1.0 based on analog input on 1.4. That means that all there really is left to do is change the if statement to reflect 1.9 V. I have to do a little math to do this, but it isn't too bad.

###ADC Math