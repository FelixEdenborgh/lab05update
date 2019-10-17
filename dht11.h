
#ifndef dht11_h
#define dht11_h

#include "Io_Macros.h"

#include <util/delay.h>
#include <inttypes.h>
#include <avr/io.h>


#if defined(ARDUINO) && (ARDUINO >= 100)
#include <Arduino.h>
#endif

#define DHT11LIB_VERSION "0.4.1"
#define pin B, 0
#define DHT_Type DHT11


enum DHT_Satus_t
{
  DHTLIB_OK,
  DHTLIB_ERROR_CHECKSUM,
  DHTLIB_ERROR_TIMEOUT
};


#define CONFIG_LOG_ENABLE 0
int dht(uint8_t bits[5], int pin);
#endif
