/* EasyRFID, an Arduino RFID wrapper library
By Daniel Giovannelli
This library wraps around the low-level SoftwareSerial access to RFID antennas to provide convenience methods for users. 
It allows users to easily instantiate and use an RFID reader on a serial port without having to worry about the details of the serial communication itself */

 // Header:
#ifndef easyRFID_h
#define easyRFID_H

#include <SoftwareSerial.h>
#include "Arduino.h"
class easyRFID
{
  public:
    easyRFID(int pin1, int baudRate, int uartOrWiegand); // ensure this is all that's needed
    String waitUntilSwipe();
    String [] waitForTime(int msToWait);
  private:
    int _pin1
    String _msg;
    char _charIn;
    SoftwareSerial _RFID;
};

#endif

// Implementation:

#include "easyRFID.h"

easyRFID::easyRFID(int pin1, int baudRate)
{
  // Serial.begin(baudRate); May be necessary
  _RFID = SoftwareSerial(pin1, pin1 + 1); // ENSURE THIS WORKS FOR SECOND ARGUMENT
  _RFID.begin(baudRate);
}

String easyRFID::waitUntilSwipe()
{
  _RFID.flush();
  _msg = "";
  boolean _tapped = false;
  while (_tapped = false) {
    if (_RFID.available()>0){
      _charIn = _RFID.read();
      _msg += _charIn;
      if(msg.length() == 14){
        msg=msg.substring(1,13);
        _tapped = true;
      }
    }
  }
  _RFID.flush();
  return _msg;
}

