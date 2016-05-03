
#ifndef SPI_H
#define SPI_H

#include <stdint.h>

//SPI configuration OR mask
#define SPI_INTERRUPT_ENABLE 0x80
#define SPI_ENABLE           0x40
#define SPI_LSB_FIRST        0x20
#define SPI_MSB_FIRST        0x00
#define SPI_MODE_MASTER      0x10
#define SPI_CLK_INVERT       0x08
#define SPI_SAMPLE_1ST_EDGE  0x00
#define SPI_SAMPLE_2ND_EDGE  0x04
#define SPI_CLK_DIV4         0x00
#define SPI_CLK_DIV16        0x01
#define SPI_CLK_DIV64        0x02
#define SPI_CLK_DIV128       0x03

#define SPI_MODE_0           0x00
#define SPI_MODE_1           0x04
#define SPI_MODE_2           0x08
#define SPI_MODE_3           0x0C



/**
 *  \fn spi_init
 *  \brief initialize the spi device core
 *  
 *  \details The Function initializes the spi device core with a
 *  particular configuration (look at configuration OR mask).
 *  
 *  \param config configuration settings for the spi core
 */
void spi_init(uint8_t config);


/**
 *  \fn spi_transfer
 *  \brief invokes a single byte transfer between slave and master
 *  
 *  \details The SPI is specified as full duplex communication.
 *  Data is transmitting and on MISO and MOSI simultaneously.
 *  So there is a single function for both, receiving from and
 *  transmitting data to the slave.
 *  
 *  \param tx Byte to transmit to the slave. For receiving only it can be garbage data.
 *  \return Data received from the slave device. For transmitting only it can be discarded.
 */
uint8_t spi_transfer(uint8_t tx);

#endif
