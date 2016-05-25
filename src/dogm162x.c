#include "dogm162x.h"

#define CMD_WAIT_US  27
#define CMD_WAIT_MS  200

//DOGM162x COMMANDS

#define DOGM162_CMD_CLEAR_DISPLAY       0x01
#define DOGM162_CMD_RETURN_HOME         0x02

#define DOGM162_CMD_ENTRY_MODE          0x04
#define DOGM162_ENTRY_SHIFT_UP          0x01
#define DOGM162_ENTRY_SHIFT_DOWN        0x00
#define DOGM162_ENTRY_MOVE_LEFT         0x00
#define DOGM162_ENTRY_MOVE_RIGHT        0x02

#define DOGM162_CMD_DIPLAY_ON_OFF       0x08
#define DOGM162_ENTIRE_DISPLAY_ON       0x04
#define DOGM162_ENTIRE_DISPLAY_OFF      0x00
#define DOGM162_CURSOR_ON               0x02
#define DOGM162_CURSOR_OFF              0x00
#define DOGM162_CURSOR_POSITION_ON      0x01
#define DOGM162_CURSOR_POSITION_OFF     0x00

#define DOGM162_CMD_SET_DDRAM_ADDRESS   0x80
#define DOGM162_DDRAM(x)                (x & 0x7F)


//Commands have to be completed with a RS line toggle!!!


static const char init_sequence[] = {0x39, 0x1C, 0x52, 0x69, 0x71, 
    0x3C, 0x0F, 0x01, 0x06};


void dogm162x_init(void)
{
    EXT_DELAY_200_MS();
    EXT_SPI_TRANSFER(init_sequence[0]);
    EXT_DELAY_24_US();
    EXT_SPI_TRANSFER(init_sequence[1]);
    EXT_DELAY_24_US();
    EXT_SPI_TRANSFER(init_sequence[2]);
    EXT_DELAY_24_US();
    EXT_SPI_TRANSFER(init_sequence[3]);
    EXT_DELAY_24_US();
    EXT_SPI_TRANSFER(init_sequence[4]);
    EXT_DELAY_24_US();
    EXT_SPI_TRANSFER(init_sequence[5]);
    EXT_DELAY_24_US();
    EXT_SPI_TRANSFER(init_sequence[6]);
    EXT_DELAY_24_US();
    EXT_SPI_TRANSFER(init_sequence[7]);
    EXT_DELAY_200_MS();
    EXT_SPI_TRANSFER(init_sequence[8]);
    EXT_DELAY_24_US();

}

void dogm162x_puts(char* s)
{

}

void dogm162x_putsPos(uint8_t x, uint8_t y, char* s)
{

}

void dogm162x_gotoPos(uint8_t x, uint8_t y)
{
    uint8_t cmd = DOGM162_CMD_SET_DDRAM_ADDRESS |
		  ((y << 2) + x);
    EXT_SPI_TRANSFER(cmd);
}


