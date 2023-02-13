CC		 = gcc
EXEC	 = hangman
CFLAGS = -Wall -ansi -pedantic
OBJ 	 = hangman.o word.o gameFunctions.o

ifdef DEBUG
CFLAGS += -D DEBUG
DEBUG : clean $(EXEC)
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

hangman.o : hangman.c 
	$(CC) $(CFLAGS) hangman.c -c

word.o : word.c word.h
	$(CC) $(CFLAGS) word.c -c

gameFunctions.o : gameFunctions.c gameFunctions.h
	$(CC) $(CFLAGS) gameFunctions.c -c



clean:
	rm -f $(EXEC) $(OBJ)


