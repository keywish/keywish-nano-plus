//Receiver program

#include "nRF24L01.h"

Nrf24l Mirf = Nrf24l(10, 9);

byte value[4];

void setup()
{
  Serial.begin(9600);
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  Mirf.setRADDR((byte *)"MotorDriver"); //Set your own address (receiver address) using 5 characters
  Mirf.payload = sizeof(value);
  Mirf.channel = 90;             //Set the used channel
  Mirf.config();
  Serial.println("Listening...");  //Start listening to received data
}

void loop()
{
  while (Mirf.dataReady()) { //When the program is received, the received data is output from the serial port
    Mirf.getData(value);
    Serial.println("Got MotorDriver data: ");
    Serial.println(value[0]);
    Serial.println(value[1]);
    Serial.println(value[2]);
    Serial.println(value[3]);
  }
}
