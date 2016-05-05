#ifndef __SegmentDisplay__
#define __SegmentDisplay__

#include <Arduino.h>


/*!
    \brief     6-digit-7-Segment-Arduino-Library
    \details   A Arduino-Library that allows you to easily controll a 6-digit 7-Segment Multiplex Matrix (e.g. E60301-L-O-0-W) with a 8-Bit-Shiftregister (e.g. M74HC595)
    \author    SohnyBohny
    \version   2.0.0
    \date      2016-05-05
    \copyright GNU GENERAL PUBLIC LICENSE Version 3
*/
class SegmentDisplay {
  private:
    int latchPin;
    int clockPin;
    int dataPin;

    int digit1;
    int digit2;
    int digit3;
    int digit4;
    int digit5;
    int digit6;
    int punkt;

  public:

    // --------------------------------------------

    //! Constructor: all Pins will be set
    /*!
      \param latchPin this int saves the latchPin used for ShiftRegister
      \param clockPin this int saves the clockPin used for ShiftRegister
      \param dataPin this int saves the dataPin used for ShiftRegister

      \param digit1 this int saves the kathote of digit1 of the display
      \param digit2 this int saves the kathote of digit2 of the display
      \param digit3 this int saves the kathote of digit3 of the display
      \param digit4 this int saves the kathote of digit4 of the display
      \param digit5 this int saves the kathote of digit5 of the display
      \param digit6 this int saves the kathote of digit6 of the display

      \param punkt this int saves the anothe of the punkt of the display
    */
    SegmentDisplay (int latchPin,
                    int clockPin,
                    int dataPin,
                    int digit1,
                    int digit2,
                    int digit3,
                    int digit4,
                    int digit5,
                    int digit6,
                    int punkt);

    // --------------------------------------------
    
    //! show a String on Display
    /*! 
     \param string String showing on the Display   
    */
    void showString (String string);
    
    // --------------------------------------------
    
    //! check if charakter is legal
    /*! 
     \param char to check
     \return bool - true if legal
    */
    bool isLegal (char check);
    
    // --------------------------------------------

    //! to talk with the display
    /*!
      \param displayResorce[6][2] the char array contains the numbers showing on the Display
      \param delayTime this int contains the time while the numbers are showed
    */
    void showChar (char displayResorce[6][2], int delayTime);

    // --------------------------------------------

    //! update the 8-Bit ShiftRegister
    /*!
      \param b this byte contains the information: state of the pins
    */
    void updateShiftRegister(byte b);
};

#endif
