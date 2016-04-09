How to use the library
======================
Class Dokumentation
-------------------

.. doxygenclass:: SegmentDisplay
   :project: SegmentDisplay
   :members:

Example
-------
.. highlight:: c

   #include <SegmentDisplay.h>

  int latchPin = 9; // Shiftregister
  int clockPin = 10;
  int dataPin = 8;

  int digit1 = 6; // cathode of the digits
  int digit2 = 1;
  int digit3 = 2;
  int digit4 = 3;
  int digit5 = 4;
  int digit6 = 5;
  int punkt = 7; // anode of the DP

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
      { '1', '.'},
      {'2', 'X'},
      {'3', '.'},
      {'4', 'X'},
      {'5', '.'},
      {'6', 'X'
    };

    segmentDisplay.showChar(tempTest , 1000); // call display to show "1.23.45.6" for 1s

  }

----

This documentation was built using ArduinoDocs_.

.. _ArduinoDocs: http://arduinodocs.readthedocs.org
