#include <SoftwareSerial.h>
#include <Wire.h>
#include <MPU6050.h>

SoftwareSerial ESPserial(2, 4); // RX | TX

MPU6050 sensor ;
int16_t ax, ay, az ;
int16_t gx, gy, gz ;

const int analogInPin = A0;
const int analogInPin1 = A1;
int sensorValue = 0;        // value read from the pot
int flex = 0;
int flex1 = 0;


void setup() {

  Serial.begin(115200);
  Wire.begin ( );
  //Serial.println  ( "Initializing the sensor" ); 
  sensor.initialize ( ); 
  //Serial.println (sensor.testConnection ( ) ? "Successfully Connected" : "Connection failed"); 
   delay (1000); 
  //Serial.println ( "Taking Values from the sensor" );
  delay (1000);
}

void loop() {
    sensor.getMotion6 (&ax, &ay, &az, &gx, &gy, &gz);
    ax = map (ax, -17000, 17000, 180, 0) ;
    ay = map (ay, -17000, 17000, 0, 180) ;

    sensorValue = analogRead(analogInPin);
    flex = map(sensorValue, 650, 550, 0, 180);
   
    sensorValue = analogRead(analogInPin1);
    flex1 = map(sensorValue, 880, 720, 0, 180);
    
    flex1 = map(flex1, 0, 180, 180, 0);
    
   
    Serial.println(ax);
    Serial.println(ay);
    Serial.println(flex1);
    Serial.println(flex); 
     
    delay(200);
}
