#include <Wire.h>

//The address of MCP23016 is 0 1 0 0 A2 A1 A0 R/W
//The wire library ignores R/W bit when addressing, other libs don´t.

//0x20 + ( a2 * 4) + ( a1 * 2) + ( a0 )
#define MCP23_ADDR B0100001

#define IODIR 0x00 //Controls the I/O 1=Output 0=Input
#define IPOL 0x01  //Input Polarity
#define GPINTEN 0x02
#define DEFVAL 0x03
#define INTCON 0x04
#define IOCON 0x05
#define GPPU 0x06 //Pull-up configuration(when configured as input) 1=PU enabled 0=PU Disabled
#define INTF 0x07
#define INTCAP 0x08
#define GPIO 0x09 //GPIO pins logic level 1=H 0=L
#define OLAT 0x0A

void setup(){
  Wire.begin();
  sendBits(IODIR,0xFF); //sets the IODIR to High impedance 
  
}
void sendBits(const byte reg, const int gpio){
  Wire.beginTransmission(MCP23_ADDR);
  Wire.write(reg);//sets the register
  Wire.write(gpio);//on which gpio pins
  Wire.endTransmission();
}
  
  
void loop(){
  sendBits(IODIR,0x00); // 1-Input 0-Output
  sendBits(GPIO,0xFF);
  delay(2000);
  sendBits(GPIO,0x00);
  delay(2000);

}
