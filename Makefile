.PHONY: clean prepare objects

#############

bin/hangman: prepare obj/main.o obj/hangman.o obj/word_select.o obj/conio.o
	gcc -std=c99 -Wall -O0 -g3 -o bin/hangman obj/main.o obj/hangman.o obj/word_select.o obj/conio.o `pkg-config --cflags --libs gtk+-3.0`

obj/main.o: src/main.c
	gcc -std=c99 -Wall -O0 -g3 -c src/main.c -o obj/main.o -Ithirdparty `pkg-config --cflags --libs gtk+-3.0`

obj/hangman.o: src/hangman.c
	gcc -std=c99 -Wall -O0 -g3 -c src/hangman.c -o obj/hangman.o -Ithirdparty `pkg-config --cflags --libs gtk+-3.0`

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
