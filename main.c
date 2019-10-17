#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <string.h>
#include <util/delay.h>
#include <stdint.h>

#include "adc.h"
#include "gpio.h"
#include "i2c.h"
#include "serial.h"
#include "timer.h"
#include "util.h"

#include "dht11.h"
#include "Io_Macros.h"



void main (void) {
	uart_init(); //requird to wright out something
	//dht_init();
	uint8_t bits[5];
	int temperature;
	int humidity;


	while (1) {


		switch(dht(bits, 8))
		{
			case (DHTLIB_OK):
				temperature = bits[0];
				humidity = bits[2];
				printf_P(PSTR("Temperature: "));
				printf("%lf\n", temperature);
				printf_P(PSTR("Humidity: "));
				printf("%lf\n", humidity);
				break;
			case (DHTLIB_ERROR_CHECKSUM):
				printf("Error Checksum\n");
				break;
			case (DHTLIB_ERROR_TIMEOUT):
				printf("Error Timeout\n");
				break;
		}

		_delay_ms(1000);






	}
}
