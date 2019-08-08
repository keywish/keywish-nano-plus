//Transmitter program

#include <SPI.h>
#include "Mirf.h"
#include "nRF24L01.h"
#include "MirfHardwareSpiDriver.h"
Nrf24l Mirf = Nrf24l(10, 9);
int value;
String vas;

void setup()
{
  Serial.begin(9600);
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
 // Mirf.SetOutputRF_PWR(3);             //Set tx power : 0dBm
//  Mirf.SetSpeedDataRates(2);          //Select between the high speed data rates:250Kbps
  Mirf.setRADDR((byte *)"ABCDE");//Set your own address (sender address) using 5 characters
  Mirf.payload = sizeof(value);
  Mirf.channel = 90;              //Set the channel used
  delay(100);
  Mirf.config();
}

void loop()
{
  vas = "asc";
  Mirf.setTADDR((byte *)"FGHIJ");           //Set the receiver address
  value = 32765;//random(255);                      //0-255 random number
  Mirf.send((byte *)"A");                //Send instructions, send random number value
  Serial.print("Wait for sending.....");
  while (Mirf.isSending())//Until you send successfully, exit the loop
  delay(1);        
  Serial.print("Send success:");
  Serial.println(value);
  delay(1000);
}
