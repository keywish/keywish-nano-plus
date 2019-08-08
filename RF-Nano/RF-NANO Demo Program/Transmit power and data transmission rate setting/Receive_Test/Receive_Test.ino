//Receiver program
#include <SPI.h>
#include "Mirf.h"
#include "nRF24L01.h"
#include "MirfHardwareSpiDriver.h"
Nrf24l Mirf = Nrf24l(10, 9);

int value;
//String 

void setup()
{
  Serial.begin(9600);
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
 // Mirf.SetOutputRF_PWR(3);             //Set tx power : 0dBm
 //  Mirf.SetSpeedDataRates(2);          //Select between the high speed data rates:250Kbps
  Mirf.setRADDR((byte *)"FGHIJ"); //Set your own address (receiver address) using 5 characters
  Mirf.payload = sizeof(value);
  Mirf.channel = 90;             //Set the used channel
  delay(100);
  Mirf.config();
  Serial.println("Listening...");  //Start listening to received data
}

void loop()
{
  if (Mirf.dataReady()) { //When the program is received, the received data is output from the serial port
    Mirf.getData((byte *) &value);
    Serial.print("Got data: ");
    Serial.println(value);
  }
}
