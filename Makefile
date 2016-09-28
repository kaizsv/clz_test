CC = gcc
CFLAGS = -O0 -std=gnu99 -Wall
EXEC = \
	recursive iteration binary_search \
	byte_shift harley_algorithm

default: clz.o
	$(CC) $(CFLAGS) clz.o clz_test.c -DRECURSIVE -o recursive
	$(CC) $(CFLAGS) clz.o clz_test.c -DITERATION -o iteration
	$(CC) $(CFLAGS) clz.o clz_test.c -DBINARY_SEARCH -o binary_search
	$(CC) $(CFLAGS) clz.o clz_test.c -DBYTE_SHIFT -o byte_shift
	$(CC) $(CFLAGS) clz.o clz_test.c -DHARLEY_ALGORITHM -o harley_algorithm

.PHONY: clean default

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

check: default
	time ./recursive
	time ./iteration
	time ./binary_search
	time ./byte_shift
	time ./harley_algorithm

plot : check
	gnuplot ./scripts/runtime.gp

clean:
	rm -f $(EXEC) *.o *.s txt_*.txt runtime.png
