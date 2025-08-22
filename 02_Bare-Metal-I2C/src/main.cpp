#include <Arduino.h>
#include <Wire.h>

// I2C ADDRESS of the DS3231 chip (FIXED)
#define DS3231_I2C_ADDRESS 0x68

//regs addresess inside chip
#define SECONDS_7BITADDR 0x00 // seconds reg
#define MINUTES_7BITADDR 0x01 // minutes reg
#define HOURS_7BITADDR 0x02 // hours reg
#define TEMP_15BITADDR 0x11 // upper bits 
#define TEMP_7BITADDR 0x12 // lower bits


int BCD_DEC_CONV(byte b) {
  // This function takes a BCD byte and converts it to a decimal number
  // Example: Input  (b) = 0x37 (which is 55 in decimal)
  // Example: Output = 37 (which is the intended number)

  struct unit // unit to read the byte and convert it from BCD to DEC
  {
    unsigned int low : 4;  // Lower 4 bits (units place)
    unsigned int high : 4; // Higher 4 bits (tens place)
  };

  // Create a struct and point it to the incoming byte 'b'
  // This overlays the struct onto the byte, splitting it automatically
  unit* converter = (unit*)&b;

  // The decimal value is (high * 10) + low
  int decimal_value = (converter->high * 10) + converter->low;
  return decimal_value;
} 

void setup(){
Serial.begin(9600);
Wire.begin();
}


void loop() {
  //read second regs  
  Wire.beginTransmission(DS3231_I2C_ADDRESS); // Start talking to the CHIP
  Wire.write(SECONDS_7BITADDR);                    // Point to the REGISTER inside the chip
  Wire.endTransmission(false);                // "False" keeps the connection open for reading
  Wire.requestFrom(DS3231_I2C_ADDRESS,1); //get one byte
  byte val_sec = Wire.read(); //value of seconds
  int seconds_decimal = BCD_DEC_CONV(val_sec); // Convert it
  Serial.print("SECONDS: ");
  Serial.println(seconds_decimal);

  //read min regs  
  Wire.beginTransmission(DS3231_I2C_ADDRESS); 
  Wire.write(MINUTES_7BITADDR);                    
  Wire.endTransmission(false);               
  Wire.requestFrom(DS3231_I2C_ADDRESS,1); 
  byte val_min = Wire.read(); //value of minutes
  int mins_decimal = BCD_DEC_CONV(val_min); 
  Serial.print(" MINUSTES: ");
  Serial.println(mins_decimal);

  //read hours regs  
  Wire.beginTransmission(DS3231_I2C_ADDRESS); 
  Wire.write(HOURS_7BITADDR);                   
  Wire.endTransmission(false);                
  Wire.requestFrom(DS3231_I2C_ADDRESS,1); 
  byte val_hrs = Wire.read(); //value of hours
  Serial.print("HOUR: ");
  int hrs_decimal = BCD_DEC_CONV(val_hrs); // Convert it
  Serial.println(hrs_decimal);  

  //read temp regs
  Wire.beginTransmission(DS3231_I2C_ADDRESS); 
  Wire.write(TEMP_15BITADDR);          // point to first reg          
  Wire.endTransmission(false);                
  Wire.requestFrom(DS3231_I2C_ADDRESS,2); // it is two bytes (upper and lower)
  byte tempMSB = Wire.read();
  byte tempLSB = Wire.read();
  int tmpsMSB_decimal = BCD_DEC_CONV(tempMSB); 
  int tmpsLSB_decimal = BCD_DEC_CONV(tempLSB); 
  Serial.print("Temp Bytes: ");
  Serial.print(tmpsMSB_decimal);
  Serial.print(" ");
  Serial.println(tmpsLSB_decimal);

  delay(2000);
}


