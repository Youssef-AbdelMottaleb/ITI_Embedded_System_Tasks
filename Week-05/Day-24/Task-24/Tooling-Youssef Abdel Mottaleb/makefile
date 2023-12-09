

DIO_Test.elf : main.o DIO.o startup.o linkerScript.ld
	avr-ld -T linkerScript.ld main.o DIO.o startup.o -o DIO_Test.elf

main.o : main.c
	avr-gcc -c -mmcu=atmega32 main.c -o main.o

startup.o : startup.c
	avr-gcc -c -mmcu=atmega32 startup.c -o startup.o

DIO.o : DIO.c
	avr-gcc -c -mmcu=atmega32 DIO.c -o DIO.o



clean:
	rm *.o *.elf