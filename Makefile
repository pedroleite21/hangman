OBJECTS = obj/main.o obj/hangman.o obj/game.o obj/word_select.o
CC = gcc -std=c99 -Wall
LIBS = `pkg-config --cflags --libs gtk+-3.0` -rdynamic

.PHONY: clean prepare

#############

bin/hangman: prepare ${OBJECTS}
	$(CC) -o bin/hangman ${OBJECTS} $(LIBS)

obj/main.o: src/main.c
	$(CC) -c src/main.c -o obj/main.o $(LIBS)

obj/hangman.o: src/hangman.c
	$(CC) -c src/hangman.c -o obj/hangman.o $(LIBS)

obj/game.o: src/game.c
	$(CC) -c src/game.c -o obj/game.o $(LIBS)

obj/word_select.o: src/word_select.c
	$(CC) -c src/word_select.c -o obj/word_select.o $(LIBS)

app: bin/hangman
	bin/hangman

test: bin/test
	bin/test

prepare: bin obj

bin:
	mkdir bin

obj:
	mkdir obj

clean:
	rm -f bin/* obj/*.o
