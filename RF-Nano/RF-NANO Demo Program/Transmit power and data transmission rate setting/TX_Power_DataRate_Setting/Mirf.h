#ifndef _MIRF_H_
#define _MIRF_H_
#include <Arduino.h>
#include "nRF24L01.h"
#include "MirfSpiDriver.h"
// Nrf24l settings
#define mirf_ADDR_LEN	5                        //Device addrees length:3~5 bytes 
#define mirf_CONFIG ((1<<EN_CRC) | (0<<CRCO) ) //enable CRC and CRC data len=1;mirf_CONFIG ==1000B

class Nrf24l {
  public:
    Nrf24l(uint8_t cs_pin, uint8_t csn_pin);
    void init();
    void config();
    void send(uint8_t *value);
    void setRADDR(uint8_t * adr);
    void setTADDR(uint8_t * adr);
    bool dataReady();
    bool isSending();
    bool rxFifoEmpty();
    bool txFifoEmpty();
    void getData(uint8_t * data);
    uint8_t getStatus();
    void transmitSync(uint8_t *dataout, uint8_t len);
    void transferSync(uint8_t *dataout, uint8_t *datain, uint8_t len);
    void configRegister(uint8_t reg, uint8_t value);
    void readRegister(uint8_t reg, uint8_t * value, uint8_t len);
    void writeRegister(uint8_t reg, uint8_t * value, uint8_t len);
    void powerUpRx();
    void powerUpTx();
    void powerDown();
    void SetOutputRF_PWR(uint8_t val);
    void SetSpeedDataRates(uint8_t val);
    void csnHi();
    void csnLow();
    void ceHi();
    void ceLow();
    void flushRx();
    uint8_t PTX;  //In sending mode.
    uint8_t cePin;// CE Pin controls RX / TX, default 8.
    uint8_t csnPin;//CSN Pin Chip Select Not, default 7.
    uint8_t channel;//Channel 0 - 127 or 0 - 84 in the US.
    uint8_t payload;// Payload width in bytes default 16 max 32.
    MirfSpiDriver *spi;//Spi interface (must extend spi).
};
#endif 
