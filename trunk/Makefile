CC = gcc

all: utf8.o utf7.o ucs4.o euc.o convertions.o
	$(CC) src/main.c -o src/exec/main lib/utf8.o
	
utf8.o:
	$(CC) -c src/utf8.c -o lib/utf8.o

utf7.o:
	$(CC) -c src/utf7.c -o lib/utf7.o

ucs4.o:
	$(CC) -c src/ucs4.c -o lib/ucs4.o

euc.o:
	$(CC) -c src/euc.c -o lib/euc.o

convertions.o:
	$(CC) -c src/convertions.c -o lib/convertions.o

clean:
	rm -f src/exec/main
	rm -f lib/utf8.o
	rm -f lib/utf7.o
	rm -f lib/ucs4.o
	rm -f lib/euc.o
	rm -f lib/convertions.o
