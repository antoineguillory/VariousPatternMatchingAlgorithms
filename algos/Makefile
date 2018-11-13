CC= gcc
CFLAGS= -std=c11 -Wall -Wpedantic -Wextra -g
PRGS = morrispratt

all: $(PRGS)

morrispratt: morrispratt.o

morrispratt.o: morrispratt.c algos.h

clean: 
	rm *.o; rm morrispratt;