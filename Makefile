F_CPU := 13000000
SOURCE := bluetooth.c spi.c led.c main.c

DEP= bluetooth.o spi.o led.o main.o

ALL=main

all: $(ALL)


main: main.elf
	avr-objcopy -O binary main.elf main.bin

main.elf: $(DEP)
	avr-gcc  -g -mmcu=atmega328p -o $@ $^

%.o: %.c
	avr-gcc -g -mmcu=atmega328p -Os -c -DF_CPU=$(F_CPU) -o $@ $<


install:  main.bin
	avrdude -c usbasp -P /dev/ttyACM0 -p m328p -U flash:w:main.bin

clean:
	rm  main.elf  main.bin	 *.o