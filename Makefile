CFLAGS = -Wall -Wextra -pedantic -std=c99
OBJS = src/main.o src/matrices/matrices.o src/decalelignes/decalelignes.o src/suboctet/suboctet.o src/addroundkey/addroundkey.o src/melangecolonnes/melangecolonnes.o 
BIN = src/main

run: $(BIN)
	./$(BIN) matrices.txt

valgrind: 
	valgrind --leak-check=full --show-leak-kinds=all ./$(BIN) matrices.txt

$(BIN): $(OBJS)

clean:
	$(RM) $(OBJS) $(BIN)
	$(RM) vgcore.*
