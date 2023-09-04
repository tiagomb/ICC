CFLAGS = -Wall -g -O3 -mavx -march=native -DLIKWID_PERFMON -I/usr/local/include -L/usr/local/lib 
LIBS = -llikwid

all: perfEG

perfEG: perfEG.o metodos.o
	gcc -o perfEG perfEG.o metodos.o $(LIBS)

perfEG.o: perfEG.c
	gcc -c $(CFLAGS) perfEG.c  $(LIBS)

metodos.o: metodos.c metodos.h
	gcc -c $(CFLAGS) metodos.c $(LIBS)

removeObjects:
	-rm *.o

clean:
	-rm *.o perfEG