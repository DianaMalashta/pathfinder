CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

LIB_NAME = libmx.a

.PHONY: clean uninstall test clean_test

$(LIB_NAME):
	mkdir -p ./obj
	mkdir -p ./temp
	cp ./inc/* ./temp/
	cp ./src/* ./temp/
	clang $(CFLAGS) ./temp/*.c -include ./temp/*.h -c
	rm -rf ./temp
	mv *.o ./obj
	ar rcs $(LIB_NAME) ./obj/*.o

clean:
	rm -rf ./obj

uninstall:
	rm -rf ./obj $(LIB_NAME) test

