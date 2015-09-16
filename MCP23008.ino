#include <Wire.h>

//The address of MCP23016 is 0 1 0 0 A2 A1 A0 R/W
//The wire library ignores R/W bit when addressing, other libs don´t.

//0x20 + ( a2 * 4) + ( a1 * 2) + ( a0 )
#define MCP23_ADDR B0100001


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
  sendBits(0x09,0x00);
  delay(2000);

}
