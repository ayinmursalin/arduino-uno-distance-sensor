This project is created as my journey on Learning IoT.

## Description
Things
- Arduino Uno
- LCD with i2c
- HY-SRF05 Module

HY-SRF05 is a module to read Distance with Ultrasonic,
This module has 5 pin:
- VCC
- GND
- Out (not used)
- Trigger (Digital) | Output
- Echo (Digital) | Input

![image](https://github.com/ayinmursalin/arduino-uno-distance-sensor/assets/9250558/ccbfafd4-d877-4040-899f-d3830e086804)

## How it Works
HY-SRF05 work based on Principle of Ultrasonic Echo-Ranging.

This module has 2 sensors, one to trigger an ultrasonic waves, and one to receive ultrasonic waves.

Trigger Sensor, send a short pulse to the trigger Pin (about 10 microseconds), then Trigger Sensor generate a burst of ultrasonic pulses.
The sound waves will travels through the air, then after hit an object, the waves will be reflected.
The reflected waves will be received by Echo Sensor.

We can calculate duration using method buildIn pulseIn
With the duration of ultrasonic waves traveled, we can count the distance with it.

```C++
  unsigned long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
```

What is 0.034? Where is it Come from?
As we all know, the speed of the sound is 340 m/s, then we need to change it as cm/microseconds
```C++
   340 * 100 / 1 * 1000000
```
Then, Because the duration that we get, is the duration of wave traveling from Trigger Sensor -> Object -> Back to Echo Sensor.
So it is a round-trip, to calculate only from Sensor to Object we can divided it by 2.

Then we get a distance in centimeters.

## Life Hacks
Instead of having to pulse, and calculate, there's an awesome library we can use to calculate distance with HY-SRF05 Module called [New Ping](https://bitbucket.org/teckel12/arduino-new-ping/src/master/).
Easy Peasy.


## Result
[![Ultrasonic Ranging Sensor](https://img.youtube.com/vi/g4Ai1kQoOP4/0.jpg)](https://www.youtube.com/watch?v=g4Ai1kQoOP4 "Ultrasonic Ranging Sensor")


## Libraries
- [LiquidCrystal_I2C](https://github.com/johnrickman/LiquidCrystal_I2C)
- [New Ping](https://bitbucket.org/teckel12/arduino-new-ping/src/master/)
