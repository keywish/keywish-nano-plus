//Transmitter program

#include <SPI.h>
#include "Mirf.h"
#include "nRF24L01.h"
#include "MirfHardwareSpiDriver.h"
Nrf24l Mirf = Nrf24l(10, 9);
int value1,value2;

void setup()
{
    Serial.begin(9600);
    Mirf.spi = &MirfHardwareSpi;
    Mirf.init();
    //Set your own address (sender address) using 5 characters
    Mirf.setRADDR((byte *)"ABCDE"); 
}

void loop()
{
    Mirf.payload = sizeof(value1);
    Mirf.channel = 10;              //Set the channel used
    Mirf.config();
    if(Mirf.channel == 10)
    {
    Mirf.setTADDR((byte *)"FGHIJ");           //Set the receiver address
    value1 = 100;
    Mirf.send((byte *)&value1);                //Send instructions, send random number value
    Serial.print("Wait for sending.....");
    while (Mirf.isSending()) delay(1);        //Until you send successfully, exit the loop
    Serial.print("value1 Send success:");
    Serial.println(value1);
    delay(500);
    }
    Mirf.payload = sizeof(value2);
    Mirf.channel = 20;              //Set the channel used
    Mirf.config();
    if(Mirf.channel == 20)
    { 
    Mirf.setTADDR((byte *)"KLMNO");           //Set the receiver address
    value2 = 200;
    Mirf.send((byte *)&value2);                //Send instructions, send random number value
    Serial.print("Wait for sending.....");
    while (Mirf.isSending()) delay(1);        //Until you send successfully, exit the loop
    Serial.print("value2 Send success:");
    Serial.println(value2);
    delay(500);
    }
}
