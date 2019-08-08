//Transmitter program

#include <SPI.h>
#include "Mirf.h"
#include "nRF24L01.h"
#include "MirfHardwareSpiDriver.h"
Nrf24l Mirf = Nrf24l(10, 9);
int value;

void setup()
{
    Serial.begin(9600);
    Mirf.spi = &MirfHardwareSpi;
    Mirf.init();
    //Set your own address (sender address) using 5 characters
    Mirf.setRADDR((byte *)"ABCDE");
    Mirf.payload = sizeof(value);
    Mirf.channel = 10;              //Set the channel used
    Mirf.config();
}

void loop()
{
    Mirf.setTADDR((byte *)"FGHIJ");           //Set the receiver address
    value = 100;
    Mirf.send((byte *)&value);                //Send instructions, send random number value
    Serial.print("Wait for sending.....");
    while (Mirf.isSending()) delay(1);        //Until you send successfully, exit the loop
    Serial.print("Send success:");
    Serial.println(value);
    delay(1000);
}
