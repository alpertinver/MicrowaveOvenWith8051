# MicrowaveOvenWith8051
the desired features of the microwave oven are as follows:
-2 buttons will be used to adjust how many seconds the microwave oven will work. One button is for
increasing and the other for decreasing. Each time the button is pressed, the working time will be determined 
in 5 second intervals.
- 1 button will be used to determine the operating power (watts) of the microwave oven. The power ratings 
are: 200, 300, 450, 600, 750, 800. 
(You can think of them as operating modes, not numerical values. Such as mod1=200, mod2=300 etc. 
According to the selected mode number, the leds arranged side by side will be turned on. For example; If 
mod3 is selected, 3 leds will be on, if mod4 is selected, the 4th led will also be on.)
- After the operating time and operating mode are set, the start button will be pressed and the microwave oven 
will be started. When the oven starts to work, the timer will count down and the motor that rotates the table 
inside will rotate at a constant speed.
- When the operation of the microwave oven is completed, a message should be sent from the serial port as 
"operation complete" and the buzzer connected to P1.0 should operate at 1 second intervals for 20 seconds.
