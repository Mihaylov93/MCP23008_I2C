#include <Wire.h>
//------
//8 Relay Board module 10 Pins VCC, GND, IN1 - IN7 to I2C 2 wires with MCP23008
//------
//The address of MCP23016 is 0 1 0 0 A2 A1 A0 R/W
//The wire library ignores R/W bit when addressing, other libs don´t.

//0x20 + ( a2 * 4) + ( a1 * 2) + ( a0 )
#define MCP23_ADDR B0100000
#define IN8 B01111111 
#define IN7 B10111111 
#define IN6 B11011111
#define IN5 B11101111
#define IN4 B11110111 
#define IN3 B11111011 
#define IN2 B11111101 
#define IN1 B11111110 

void setup(){
  Wire.begin();
  sendBits(0x00,0xFF); //sets the IODIR to High impedance 
  
}
void sendBits(const int operation, const int pins){
  Wire.beginTransmission(MCP23_ADDR);
  Wire.write(operation);//sets the operation
  Wire.write(pins);//on which pins
  Wire.endTransmission();
}
  
  
void loop(){
  sendBits(0x00,0x00); // 1-Input 0-Output
  sendBits(0x09,0xFF);
  delay(2000);
  sendBits(0x09,IN1);
  delay(200);
  sendBits(0x09,IN2);
  delay(200);
  sendBits(0x09,IN3);
  delay(200);
  sendBits(0x09,IN4);
  delay(200);
  sendBits(0x09,IN5);
  delay(200);
  sendBits(0x09,IN6);
  delay(200);
  sendBits(0x09,IN7);
  delay(200);
  sendBits(0x09,IN8);
  delay(200);
  
  sendBits(0x09,0xFF);
  delay(2000);
    
  sendBits(0x09,IN1);
  delay(200);
  sendBits(0x09,IN2&IN1);
  delay(200);
  sendBits(0x09,IN3&IN2&IN1);
  delay(200);
  sendBits(0x09,IN4&IN3&IN2&IN1);
  delay(200);
  sendBits(0x09,IN5&IN4&IN3&IN2&IN1);
  delay(200);
  sendBits(0x09,IN6&IN5&IN4&IN3&IN2&IN1);
  delay(200);
  sendBits(0x09,IN7&IN6&IN5&IN4&IN3&IN2&IN1);
  delay(200);
  sendBits(0x09,IN8&IN7&IN6&IN5&IN4&IN3&IN2&IN1);
  delay(200);

  sendBits(0x09,0xFF);
  delay(2000);
}
