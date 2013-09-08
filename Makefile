CC = gcc

tasm: tasm.c
	$(CC) $^ -o $@

debug: tasm.c
	$(CC) $^ -g -o $@
