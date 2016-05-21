OBJECTS = obj/main.o obj/hangman.o obj/game.o obj/word_select.o obj/conio.o

.PHONY: clean prepare

#############

bin/hangman: prepare ${OBJECTS}
	gcc -std=c99 -Wall -O0 -g3 -o bin/hangman ${OBJECTS} `pkg-config --cflags --libs gtk+-3.0` -rdynamic

obj/main.o: src/main.c
	gcc -std=c99 -Wall -O0 -g3 -c src/main.c -o obj/main.o -Ithirdparty `pkg-config --cflags --libs gtk+-3.0` -rdynamic

obj/hangman.o: src/hangman.c
	gcc -std=c99 -Wall -O0 -g3 -c src/hangman.c -o obj/hangman.o -Ithirdparty `pkg-config --cflags --libs gtk+-3.0` -rdynamic

obj/game.o: src/game.c
	gcc -std=c99 -Wall -O0 -g3 -c src/game.c -o obj/game.o -Ithirdparty `pkg-config --cflags --libs gtk+-3.0` -rdynamic

obj/word_select.o: src/word_select.c
	gcc -std=c99 -Wall -O0 -g3 -c src/word_select.c -o obj/word_select.o

obj/conio.o: thirdparty/conio.c
	gcc -std=c99 -Wall -O0 -g3 -c thirdparty/conio.c -o obj/conio.o

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
