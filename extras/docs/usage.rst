How to use the library
======================
Class Dokumentation
-------------------

.. doxygenclass:: SegmentDisplay
   :project: SegmentDisplay
   :members:
   
----

This documentation was built using ArduinoDocs_.

.. _ArduinoDocs: http://arduinodocs.readthedocs.org

----

What's about displayResorce[6][2]
---------------------------------

===== ========
First dimension 
--------------
Call  Output
===== ========
0     |digit0|
1     |digit1|
2     |digit2|
3     |digit3|
4     |digit4|
5     |digit5|
6     |digit6|
7     |digit7|
8     |digit8|
9     |digit9|
C     |digitC|
F     |digitF|
o     |digit°|
===== ========

.. |digit0| image:: https://upload.wikimedia.org/wikipedia/commons/4/49/7-segment_abcdef.svg
   :width: 50pt
   :height: 50pt

.. |digit1| image:: https://upload.wikimedia.org/wikipedia/commons/b/be/7-segment_bc.svg
   :width: 50pt
   :height: 50pt

.. |digit2| image:: https://upload.wikimedia.org/wikipedia/commons/f/f8/7-segment_abdeg.svg
   :width: 50pt
   :height: 50pt

.. |digit3| image:: https://upload.wikimedia.org/wikipedia/commons/b/be/7-segment_abcdg.svg
   :width: 50pt
   :height: 50pt

.. |digit4| image:: https://upload.wikimedia.org/wikipedia/commons/b/b0/7-segment_bcfg.svg
   :width: 50pt
   :height: 50pt

.. |digit5| image:: https://upload.wikimedia.org/wikipedia/commons/9/9b/7-segment_acdfg.svg
   :width: 50pt
   :height: 50pt

.. |digit6| image:: https://upload.wikimedia.org/wikipedia/commons/0/03/7-segment_acdefg.svg
   :width: 50pt
   :height: 50pt

.. |digit7| image:: https://upload.wikimedia.org/wikipedia/commons/6/62/7-segment_abc.svg
   :width: 50pt
   :height: 50pt

.. |digit8| image:: https://upload.wikimedia.org/wikipedia/commons/a/ab/7-segment_abcdefg.svg
   :width: 50pt
   :height: 50pt

.. |digit9| image:: https://upload.wikimedia.org/wikipedia/commons/7/7a/7-segment_abcdfg.svg
   :width: 50pt
   :height: 50pt

.. |digitC| image:: https://upload.wikimedia.org/wikipedia/commons/2/2d/7-segment_adef.svg
   :width: 50pt
   :height: 50pt

.. |digitF| image:: https://upload.wikimedia.org/wikipedia/commons/a/a6/7-segment_aefg.svg
   :width: 50pt
   :height: 50pt

.. |digit°| image:: pic°.svg
   :width: 50pt
   :height: 50pt

Example
-------
.. code-block:: c

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
