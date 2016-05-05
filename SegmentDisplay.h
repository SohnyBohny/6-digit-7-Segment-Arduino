#ifndef __SegmentDisplay__
#define __SegmentDisplay__

#include <Arduino.h>


/*!
    \brief     Pretty nice class.
    \details   This class is used to demonstrate a number of section commands.
    \author    SohnyBohny
    \version   1.0.0
    \date      2016-04-02
    \warning   Not tested yet
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
