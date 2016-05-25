#ifndef DOGM162X_H
#define DOGM162X_H

#include <stdint.h>

#define EXT_SPI_TRANSFER dogm162x_spi
#define EXT_DELAY_200_MS dogm_delay_ms
#define EXT_DELAY_24_US  dogm_delay_us

extern uint8_t EXT_SPI_TRANSFER(uint8_t c);
extern void EXT_DELAY_200_MS(void);
extern void EXT_DELAY_24_US(void);

void dogm162x_init(void);

void dogm162x_puts(char* s);

void dogm162x_putsPos(uint8_t x, uint8_t y, char* s);

void dogm162x_gotoPos(uint8_t x, uint8_t y);

#endif //DOGM162X_H 

