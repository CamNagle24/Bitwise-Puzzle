CC = gcc
CFLAGS = -O -Wall -m32
LIBS = -lm

all: btest fshow ishow

btest: btest.c bits.c decl.c tests.c btest.h bits.h
	$(CC) $(CFLAGS) $(LIBS) -o btest bits.c btest.c decl.c tests.c

fshow: fshow.c
	$(CC) $(CFLAGS) -o fshow fshow.c

ishow: ishow.c
	$(CC) $(CFLAGS) -o ishow ishow.c

test: all
	@chmod u+x dlc
	@chmod u+x check_bitwise
	./check_bitwise

clean:
	rm -f *.o btest fshow ishow *~

zip:
	@echo "Error: Do not run make zip in the bitwise subdirectory. Run it in the project's top-level directory."
