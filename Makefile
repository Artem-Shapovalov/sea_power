all: tests

tests: test_malloc
	./test_malloc

test_malloc: malloc.h malloc.c tests/malloc.c
	$(CC) malloc.c tests/malloc.c -o test_malloc -ansi -g3 -ggdb -I.

clean:
	rm -rf test_*
