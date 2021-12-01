#ifndef SPI_H
#define SPI_H

void SPI_MasterInit(void);
void SPI_MasterTransmit(char cData);
void Allume_Led(char data1, char data2);
void Eteint_Led();

#endif