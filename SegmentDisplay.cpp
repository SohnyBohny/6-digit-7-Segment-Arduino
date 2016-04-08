/*
   by NiklasM 2016-04-01
   GNU Public License
   for more information see DisplayHelper.h
*/

#include "SegmentDisplay.h"
#include <Arduino.h>

SegmentDisplay::SegmentDisplay (int latchPin,
                                int clockPin,
                                int dataPin,
                                int digit1,
                                int digit2,
                                int digit3,
                                int digit4,
                                int digit5,
                                int digit6,
                                int punkt) {

  this->latchPin   = latchPin;
  this->clockPin = clockPin;
  this->dataPin  = dataPin;

  this->digit1  = digit1;
  this->digit2  = digit2;
  this->digit3  = digit3;
  this->digit4  = digit4;
  this->digit5  = digit5;
  this->digit6  = digit6;

  this->punkt  = punkt;
	
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(digit4, OUTPUT);
  pinMode(digit5, OUTPUT);
  pinMode(digit6, OUTPUT);

  digitalWrite(digit1, HIGH); // Katohte is turned HEIGH -> all digits - off
  digitalWrite(digit2, HIGH);
  digitalWrite(digit3, HIGH);
  digitalWrite(digit4, HIGH);
  digitalWrite(digit5, HIGH);
  digitalWrite(digit6, HIGH);

  pinMode(punkt, OUTPUT);
}

void SegmentDisplay::showChar (char displayResorce[6][2], int delayTime) {
  while (delayTime > 0) {
    byte numberToShift = B0 ;

    for (int i = 0; i < 6; i++) {
      switch (displayResorce[i][0]) {
        case '1':
           numberToShift = B0110000;
          break;
        case '2':
           numberToShift = B1011101;
          break;
        case '3':
           numberToShift = B1111100;
          break;
        case '4':
           numberToShift = B0110110;
          break;
        case '5':
           numberToShift = B1101110;
          break;
        case '6':
           numberToShift = B1101111;
          break;
        case '7':
           numberToShift = B0111000;
          break;
        case '8':
           numberToShift = B11111111;
          break;
        case '9':
           numberToShift = B1111110;
          break;
        case '0':
           numberToShift = B1111011;
          break;
        case 'o':
           numberToShift = B0011110;
          break;
        case 'C':
           numberToShift = B1001011;
          break;
        case 'F':
           numberToShift = B0001111;
          break;
        case '-':
           numberToShift = B0000100;
          break;
        case 'X':
           numberToShift = B0;
          break;
      }

      updateShiftRegister(numberToShift) ;

      if (displayResorce[i][1] == '.') {
        digitalWrite(punkt, HIGH);
      }

      // "activate" Kathode - turn digit on
      int kathode = -1;

      switch (i) {
        case 0:
          kathode = digit1;
          break;
        case 1:
          kathode = digit2;
          break;
        case 2:
          kathode = digit3;
          break;
        case 3:
          kathode = digit4;
          break;
        case 4:
          kathode = digit5;
          break;
        case 5:
          kathode = digit6;
          break;
      }

      digitalWrite(kathode, LOW);

      // after a short delay - turn digit off
      delay(1);
      delayTime -= 1; // while condition
      if (displayResorce[i][1] == '.') {
        digitalWrite(punkt, LOW);
      }
      digitalWrite(kathode, HIGH);



    }
  }
}

void SegmentDisplay::updateShiftRegister(byte b)
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, b);
  digitalWrite(latchPin, HIGH);
}
