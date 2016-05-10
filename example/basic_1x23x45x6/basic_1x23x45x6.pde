/* 
 * This is a basic example for the "six-digit-seven-segment" Library
 * for more information see https://6-digit-7-segment-arduino.readthedocs.org
 * by SohnyBohny
*/

#include <SegmentDisplay.h>
int latchPin = 10; // Shiftregister
int clockPin = 11;
int dataPin = 9;

int digit1 = 7; // cathode of the digits
int digit2 = 2;
int digit3 = 3;
int digit4 = 4;
int digit5 = 5;
int digit6 = 6;
int punkt = 8; // anode of the DP

SegmentDisplay segmentDisplay(latchPin, // tell the library the pins -> pinMode will be called
                              clockPin,
                              dataPin,
                              digit1,
                              digit2,
                              digit3,
                              digit4,
                              digit5,
                              digit6,
                              punkt);

void setup() {
}

void loop() {

  char tempTest[6][2] = {
    {'1', '.'},
    {'2', 'X'},
    {'3', '.'},
    {'4', 'X'},
    {'5', '.'},
    {'6', 'X'}
  };

  segmentDisplay.showChar(tempTest , 1000); // call display to show "1.23.45.6" for 1s

}
