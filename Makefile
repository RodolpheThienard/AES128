CFLAGS = -Wall -Wextra -pedantic -std=c99 -g
OBJS = src/main.o src/matrices/matrices.o src/decalelignes/decalelignes.o src/suboctet/suboctet.o src/addroundkey/addroundkey.o \
	src/melangecolonnes/melangecolonnes.o src/tools/tools.o src/key_extension/key_extension.o src/ctr/ctr.o src/aes/aes.o src/attack/attack.o
BIN = src/main

run: $(BIN)
	./$(BIN) matrices.txt

valgrind: 
	valgrind --leak-check=full --show-leak-kinds=all  ./$(BIN) matrices.txt

$(BIN): $(OBJS)

clean:
	$(RM) $(OBJS) $(BIN)
	$(RM) vgcore.*
