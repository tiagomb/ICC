# PROGRAMA
    PROG = perfEG

# Compilador
    CC     = gcc
    CFLAGS = -Wall -g -O3 -mavx -march=native -DLIKWID_PERFMON -I/usr/local/include -L/usr/local/lib 
    LIBS = -llikwid -lm

# Lista de arquivos para distribuição
    DISTFILES = *.c *.h LEIAME* Makefile
    DISTDIR = `basename ${PWD}`

.PHONY: all clean purge dist

all: perfEG

clean:
	@echo "Limpando sujeira ..."
	@rm -f *~ *.bak

perfEG: perfEG.o metodos.o utils.o
	gcc -o perfEG perfEG.o metodos.o utils.o $(LIBS)

perfEG.o: perfEG.c
	gcc -c $(CFLAGS) perfEG.c  $(LIBS)

metodos.o: metodos.c metodos.h
	gcc -c $(CFLAGS) metodos.c $(LIBS)

utils.o: utils.c utils.h
	gcc -c $(CFLAGS) utils.c $(LIBS)

removeObjects:
	-rm *.o

purge:  clean
	@echo "Limpando tudo ..."
	@rm -f $(PROG) *.o core a.out $(DISTDIR) $(DISTDIR).tar

dist: purge
	@echo "Gerando arquivo de distribuição ($(DISTDIR).tar) ..."
	@ln -s . $(DISTDIR)
	@tar -cvf $(DISTDIR).tar $(addprefix ./$(DISTDIR)/, $(DISTFILES))
	@rm -f $(DISTDIR)