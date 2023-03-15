/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-limit-switch
 */

#include <ezButton.h>
#include <TM1637Display.h>

// define the connections pins
#define CLK 9
#define DIO 10

// create a display object of type TM1637Display
TM1637Display display = TM1637Display(CLK, DIO);

ezButton limitSwitchA(7);  // create ezButton object that attach to pin 7;
ezButton limitSwitchB(4);  // create ezButton object that attach to pin 7;

int points = 0;
const int limitSwitchAPointBonus = 1;
const int limitSwitchBPointBonus = 5;


void setup() {
  display.clear();
  display.setBrightness(7);
  Serial.begin(9600);
  limitSwitchA.setDebounceTime(0); // set debounce time to 50 milliseconds
  limitSwitchA.setDebounceTime(0); // set debounce time to 50 milliseconds
}


void loop() {
  
  limitSwitchA.loop(); // MUST call the loop() function first
  limitSwitchB.loop(); // MUST call the loop() function first

  UpdatePoints();
  display.showNumberDec(points);
}

void UpdatePoints()
{
    //limitSwitchA check
    if(limitSwitchA.isPressed()){
      display.clear();
      points = points + limitSwitchAPointBonus;
  }

    //limitSwitchB check
    if(limitSwitchB.isPressed()){
      display.clear();
      points = points + limitSwitchBPointBonus;
  }
}
