F_CPU := 13000000
SOURCE := main.c



main.elf: ${SOURCE} 
	avr-gcc -DF_CPU=${F_CPU} -Os -mmcu=atmega328p ${SOURCE} -o main.elf

main.bin: main.elf
	avr-objcopy -O binary main.elf main.bin


install:  main.bin
	avrdude -c usbasp -P /dev/ttyACM0 -p m328p -U flash:w:main.bin
	
clean:
	rm  main.elf  main.bin	
