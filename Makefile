.PHONY: clean prepare

#############

prepare:
	mkdir -p bin
	mkdir -p obj

clean:
	rm -f bin/* obj/*.o