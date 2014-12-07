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

##Documentation
Other than the brief comment about the resistor that I mentioned, I knocked this one out all by myself.