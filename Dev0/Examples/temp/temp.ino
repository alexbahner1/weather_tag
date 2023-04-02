#include <Wire.h>
#include <math.h>
int16_t data = 0;
uint16_t temp = 0;
int16_t humdi = 0;

// ADDR_PIN = 0x44;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  

// Wire.beginTransmission(0x44);
// Wire.write(0x24);
// Wire.write(0x00);
// Wire.endTransmission();

}

void loop() {
  Wire.beginTransmission(0x44); //
  Wire.write(0x24); //
  Wire.write(0x00); //
  Wire.endTransmission();

//  Wire.beginTransmission(0x44);
//  Wire.write(0x21); // MSB Data snpa shot 
//  Wire.write(0x30); // LSB
  
  delay(100);
  Wire.requestFrom(0x44,6,true);
  temp = (Wire.read() << 8 | Wire.read());// & 0b0000111111111111;
  data = Wire.read();
  humdi = (Wire.read() | Wire.read() << 8) & 0b0000111111111111;
  data = Wire.read();
  Wire.endTransmission();
  
  uint16_t T = -49 + 315*(temp/(pow(2,16)-1));
  Serial.print("Temp :");
  Serial.println(T);
//   int tempR = (-49 + 315 *(temp /(65536-1)));
//   Serial.println(tempR);
  //Serial.println(humdi);

  delay(1000);

}
