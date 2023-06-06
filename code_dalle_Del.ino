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

const int ledPin1A =  2;
const int ledPin2A =  3; 
const int ledPin3B =  4; 
const int ledPin4B =  5; 

int ledStateA = LOW;
int ledStateB = LOW;

int slidePin = 0;
int slideState = LOW;


long previousMillis = 0;
long ledInterval = 1000;

ezButton limitSwitchA(7);  // create limitSwitch object that attach to pin 7

int points = 0;
const int limitSwitchAPointBonus = 1;
const int slidePointBonus = 10;


void setup() {
  pinMode(slidePin, INPUT_PULLUP);

  pinMode(ledPin1A, OUTPUT);
  pinMode(ledPin2A, OUTPUT);
  pinMode(ledPin3B, OUTPUT);
  pinMode(ledPin4B, OUTPUT);

  display.clear();
  display.setBrightness(7);
  Serial.begin(9600);
  limitSwitchA.setDebounceTime(50); // set debounce time to 50 milliseconds
}


void loop() {
  unsigned long currentMillis = millis();
  
  slideState = analogRead(slidePin);

  if(currentMillis - previousMillis > ledInterval){
    previousMillis = currentMillis;

    if(ledStateA == LOW){
      ledStateA = HIGH;
      ledStateB = LOW;
    }else{
      ledStateA = LOW;
      ledStateB = HIGH;
    }

    updateLeds();
  }

  limitSwitchA.loop(); // MUST call the loop() function first

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
    if(slideState == HIGH){
      points = points + slidePointBonus;
    }
}

void updateLeds(){
  digitalWrite(ledPin1A,ledStateA);
  digitalWrite(ledPin2A,ledStateA);
  digitalWrite(ledPin3B,ledStateB);
  digitalWrite(ledPin4B,ledStateB);
}
