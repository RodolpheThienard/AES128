CFLAGS = -Wall -Wextra -pedantic -std=c99
OBJS = main.o matrices.o decalelignes.o suboctet.o
BIN = main

run: $(BIN)
	./$(BIN) matrices.txt

valgrind: 
	./valgrind --leak-check=full --show-leak-kinds=all ./$(BIN)

$(BIN): $(OBJS)

clean:
	$(RM) $(OBJS) $(BIN)
