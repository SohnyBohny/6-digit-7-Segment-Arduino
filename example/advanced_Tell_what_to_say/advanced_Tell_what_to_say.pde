/*
   This is a advanced example for the "six-digit-seven-segment" Library
   for more information see https://6-digit-7-segment-arduino.readthedocs.org
   by SohnyBohny
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

String input = "5tArt";

void setup() {
  Serial.begin(9600);
  Serial.println("Welcome - please tell me what I should say");
  Serial.println("Legal charakters are:");
  Serial.println("0\t1\t2\t3\t4\t5\t6\t7\t8\t9\t0");
  Serial.println("o(°)\tC\tF\tA\tb\tC\td\tE\tF\tG\tH");
  Serial.println("I\tJ\tL\tU\tc\th\tn\tO(o)\t0(O)\tr\tt");
  Serial.println("u\tp\ty\t\tX(for SPACE)");

  Serial.flush();
}

void loop() {
  if (Serial.available() > 0) {
    input = "";
    bool corectChars = true;
    char inChar;
    while (Serial.available() > 0) {
      inChar = Serial.read();
      if (!segmentDisplay.isLegal(inChar)) {
        Serial.println("ERROR ------ " + String(inChar) + "is not legal");
        corectChars = false;
      }
      input += inChar;
    }

    if (!corectChars) {
      input = "tryXAGAIn";
    }
  }

  while (Serial.available() == 0) {
    segmentDisplay.showString(input);
  }

}
