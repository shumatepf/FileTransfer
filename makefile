all: transfer main hw

main: main.c
	gcc -c main.c

transfer: transfer.c
	gcc -c transfer.c

hw: main.o transfer.o
	gcc -o hw main.o transfer.o
	
clean:
	rm hw main.o transfer.o
