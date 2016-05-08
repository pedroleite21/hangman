.PHONY: clean prepare objects

#############

bin/hangman: prepare objects
	gcc -Wall -O0 -g3 -o bin/hangman obj/*.o

objects: prepare
	gcc -Wall -O0 -g3 -c src/*.c
	mv *.o obj
	
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
