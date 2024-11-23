COMMON=common.h

all: gpio_test

gpio_test: gpio.o main.o
	gcc -o gpio_test gpio.o main.o
 
gpio.o: gpio_driver.h gpio_driver.c $(COMMON)
	gcc -c -o gpio.o gpio_driver.c
 
main.o: main.c gpio_driver.h $(COMMON)
	gcc -c -o main.o main.c
 
clean:
	rm -f gpio_test *.o
