# motioncontrol-joysticks
A basic project using 2 Arduinos and 2 MPU6050 to make motion controlled joysticks. They were tested on the retro game 'Super mario bros'.
## Tools used:
  * Arduino UNO microcontroller
  * MPU 6050 IMU modeules 
  * Processing.js
  * Mesen Emulator to run NES games on PC.
## Working overview
The joysticks were made out of PVC pipes with the IMU sensors attached at the end of the pipes. As the accelerometer on the IMU crossed a certain threshold on moving it either 'UP' or "DOWN', a signal was sent through the serial port of the Arduino to the processing code running in the background. This code then simulated a key press from the keyboard, which made appropriate movements to Mario in the game that ran on the screen.
