CC = gcc

tasm: tasm.c instructs.c
	$(CC) $^ -o $@

debug: tasm.c instructs.c
	$(CC) $^ -g -o $@
