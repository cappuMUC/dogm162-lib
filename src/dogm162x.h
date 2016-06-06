#ifndef DOGM162X_H
#define DOGM162X_H

#include <stdint.h>

void dogm162x_init(void);

void dogm162x_puts(char* s);

void dogm162x_putsPos(uint8_t x, uint8_t y, char* s);

void dogm162x_gotoPos(uint8_t x, uint8_t y);

#endif //DOGM162X_H 

