#include <Wire.h>
#include <Servo.h>   
#include <string.h>
Servo sg90x;
Servo sg90y;          
Servo sflexthumb;
Servo sflexgrip;
int servo_pin_x = 2;
int servo_pin_y = 4;
int servo_flex_thumb = 3;
int servo_flex_grip = 9;

unsigned long serialdata;
int inbyte;


void setup ( ) {
  sg90x.attach ( servo_pin_x );
  sg90y.attach ( servo_pin_y );
  sflexthumb.attach ( servo_flex_thumb );
  sflexgrip.attach (servo_flex_grip);
  Serial.begin  (115200); 
}

void loop()
{
    
    sg90x.write (getSerial());
    sg90y.write (getSerial());
    sflexthumb.write (getSerial());
    sflexgrip.write(getSerial());
    
}

long getSerial()
{
  serialdata = 0;
  while (inbyte != '/')
  {
    inbyte = Serial.read(); 
    if (inbyte > 0 && inbyte != '/')
    {
     
      serialdata = serialdata * 10 + inbyte - '0';
    }
  }
  inbyte = 0;
  return serialdata;
}

