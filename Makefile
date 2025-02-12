CC=gcc
CFLAGS=-I.
DEPS = threadrace.h bicho.h
OBJ = main.o threadrace.o bicho.o
EXEC = bicho_exe

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(EXEC) *.o *~ core