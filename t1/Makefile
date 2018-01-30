CC=gcc
CFLAGS= -ansi -pedantic -g -Wall -O3 -I.

# -g adds debugging information on the executable file
# -ansi
LIBS=-lm

NAME=tetris

DEPS = tetris.h engine.h screen.h sequence.h 
OBJ = tetris.o engine.o screen.o sequence.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *.o $(NAME) 
