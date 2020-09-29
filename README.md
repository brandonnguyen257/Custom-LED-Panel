<b>Project Inspiration:</b>

   This project was inspired through my DJing hobby. To add more value for future gigs, I wanted to purchase
   LED lights to decorate my DJ set up. However there were many options that were either too expensive or
   doesn't have custom effects. I wanted to build my own LED panel so that I can create my own custom effects
   at half the cost of the other options out there.

<b>Project Materials:</b>

  1. BTF-LIGHTING WS2812B RGB(300 pixel) LED Strip  
  2. Arduino Mega  
  3. 5V Power Supply
  4. Bread Board
  5. Jumper Wires
  
<b>Project Timeline:</b>

  1. Connecting the single LED strip to power
  2. Reading and figuring out the FASTLed library
  3. Creating Custom Effects using a single LED strip through Arduino
  4. Cutting LED stip into 10x30 strips
  
      4a.Soldering Jumper Wires to each indivual strip
    
      4b.Connect each strip to an Arduino pin
      
  5. Realized using a computer for the Arduino and LED strips as a power supply is not sufficient enough
  
      5a.Connected an external 5V power supply to a breadboard
    
      5b.Arduino and LED strips are now powered seperately
      
  6. Creating Custom 2D LED panel effects

<b>Future Features:</b>

For future features, I want to be able to control the the LED panel through a MIDI keyboard. This would utilize
a seperate Ardunio to take inputs from the MIDI and outputting that data to the LED panel's Arduino.

In addition, I want to improve the wire managment to be more minimal and secure. This will allow the system
to fit inside a diffuser for a more sleek look.

LED Panel System
![](demo/LEDSystem.jpg)


<b>Below are GIFS of some of the implemented effects</b>

Iterate Through Color Wheel

![](demo/ScrollColorWheel.gif)

Pulse Effect

![](demo/PulseEffect.gif)

Moving Wave

![](demo/MovingWave.gif)

Moving Eye

![](demo/MovingEye.gif)

Strobe Preset

![](demo/StrobePreset.gif)

Personal Logo Moving Animation

![](demo/MovingAnimation.gif)
