CC= gcc
CFLAGS= -std=c11 -Wall -Wpedantic -Wextra -g
PRGS = naive

all: $(PRGS)

naivesentinelle: naivesentinelle.o

naiverapide: naiverapide.o

naive: naive.o 

naivesentinelle.o: naivesentinelle.c naive.h

naiverapide.o: naiverapide.c naive.h

naive.o: naive.c naive.h

clean: 
	rm *.o; rm naive; rm naiverapide; rm naivesentinelle
