CC= gcc
CFLAGS= -std=c11 -Wall -Wpedantic -Wextra -g
PRGS = naive naiverapide naivesentinelle naivestrncmp naivestrncmprapide

all: $(PRGS)

naivestrncmp: naivestrncmp.o

naivestrncmprapide: naivestrncmprapide.o

naivesentinelle: naivesentinelle.o

naiverapide: naiverapide.o

naive: naive.o 

naivestrncmp.o: naivestrncmp.c naive.h

naivestrncmprapide.o: naivestrncmprapide.c naive.h

naivesentinelle.o: naivesentinelle.c naive.h

naiverapide.o: naiverapide.c naive.h

naive.o: naive.c naive.h

clean: 
	rm *.o; rm naive; rm naiverapide; rm naivesentinelle; rm naivestrncmp; rm naivestrncmprapide
