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

ezButton limitSwitch(7);  // create ezButton object that attach to pin 7;
int points = 0;
void setup() {
  display.clear();
  display.setBrightness(7);
  Serial.begin(9600);
  limitSwitch.setDebounceTime(50); // set debounce time to 50 milliseconds
}

void loop() {
  limitSwitch.loop(); // MUST call the loop() function first
  if(limitSwitch.isPressed()){
      display.clear();
      points ++;
  }


  display.showNumberDec(points);
}
