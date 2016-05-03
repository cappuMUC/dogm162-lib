
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "spi.h"
#include "dogm162x.h"





#define SPI_PORT  PORTB
#define SPI_DDR   DDRB
#define SPI_SCK   1
#define SPI_MISO  3
#define SPI_MOSI  2
#define SPI_SS    7
#define SPI_RS    6

#define DOGM_SELECT() (SPI_PORT &= ~(1 << SPI_SS));
#define DOGM_RELEASE() (SPI_PORT |= (1 << SPI_SS));

#define DOGM_RS_LO() (SPI_PORT &= ~(1 << SPI_RS));
#define DOGM_RS_HI() (SPI_PORT |= (1 << SPI_RS));

#define LED_DDR   DDRE
#define LED_PORT  PORTE
#define LED_PIN   3


#define LED_SET(x) (LED_PORT |=  (1 << x))
#define LED_CLR(x) (LED_PORT &= ~(1 << x))
#define LED_TOGGLE(x) (LED_PORT ^= (1 << x))

uint8_t dogm162x_spi(uint8_t c);
void dogm162xx_puts(uint8_t* c);


void main(void)
{

  //set LED outputs
  LED_DDR |= (1 << LED_PIN);

  LED_PORT = 0x00;

  SPI_DDR  |= (1 << SPI_SCK)  |
              (1 << SPI_MOSI) |
              (1 << SPI_SS)   |
              (1 << SPI_RS);
  
  DOGM_RELEASE();
  
  spi_init(SPI_ENABLE          |
           SPI_MSB_FIRST       |
           SPI_MODE_MASTER     |
           SPI_MODE_3          |
           SPI_CLK_DIV64);

  _delay_ms(400);
  
  dogm162x_init();
  
  dogm162xx_puts("    RATC[OS]   ");
    
  while(1)
  {
    LED_TOGGLE(LED_PIN);
    _delay_ms(500);
  }
}

uint8_t dogm162x_spi(uint8_t c)
{
    DOGM_SELECT();
    _delay_us(50);
    DOGM_RS_LO();
    spi_transfer(c);
    DOGM_RELEASE();
    
    DOGM_RS_HI();
    _delay_us(5);
    DOGM_RS_LO();
    return 0;
}

void dogm162xx_puts(uint8_t* c)
{
    DOGM_RS_HI();
    DOGM_SELECT();

    while(*c) {
      spi_transfer(*c);
      _delay_us(27);
      c++;
    }
    DOGM_RELEASE();
    DOGM_RS_LO();
    return 0;
}


