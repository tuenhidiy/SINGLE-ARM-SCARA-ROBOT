#ifndef servo_h
#define servo_h

#include "grbl.h"

#define SERVO_MIN_PULSE_WIDTH       750     // the shortest pulse sent to a servo  
#define SERVO_MAX_PULSE_WIDTH      2250     // the longest pulse sent to a servo 
#define SERVO_DEFAULT_PULSE_WIDTH  1500     // default pulse width when servo is attached
#define SERVO_FRAME_SYNC_PERIOD   20000        // total frame duration in microseconds 

#define NBR_CHANNELS 8                   // the maximum number of channels, don't change this 

typedef struct  {
  uint8_t nbr        :5 ;             // a pin number from 0 to 31
  uint8_t isActive   :1 ;             // true if this channel is enabled, pin not pulsed if false 
} ServoPin_t   ;  

typedef struct {
  ServoPin_t Pin;
  uint16_t counter;
  uint16_t remainder;
}  servo_t;


void serattach();           // attach the given pin to the next free channel, sets pinMode, returns channel number or 0 if failure
void serwrite(int pulsewidth); // if value is < 200 its treated as an angle, otherwise as pulse width in microseconds 


#endif