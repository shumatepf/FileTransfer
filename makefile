all: transfer main ftransfer

main: main.c
	gcc -c main.c

transfer: transfer.c
	gcc -c transfer.c

ftransfer: main.o transfer.o
	gcc -o ftransfer main.o transfer.o
	
clean:
	rm ftransfer main.o transfer.o
