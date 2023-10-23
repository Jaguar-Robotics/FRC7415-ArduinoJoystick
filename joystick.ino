// NOTE: This sketch file is for use with Arduino Leonardo and
//       Arduino Micro only.
//
// originsl by Matthew Heironimus 
// 2015-11-20
//
// edited by 7415 Jaguar Robotics
// 2023-10-22
//--------------------------------------------------------------------

#include <Joystick.h>

Joystick_ Joystick;

void setup() {
  // Initialize Button Pins
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);

  Joystick.begin();
}


// Button state, change number and 0s to number of buttons
int lastButtonState[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void loop() {

  // Read pin values
  for (int index = 0; index < 14; index++) // index < [num of buttons]
  {
    
    int currentButtonState = !digitalRead(index);
    if (currentButtonState != lastButtonState[index])
    {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }

  delay(50);
}
