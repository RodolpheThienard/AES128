CFLAGS = -Wall -Wextra -pedantic -std=c99 -g -O3
OBJS = src/main.o src/decalelignes/decalelignes.o src/suboctet/suboctet.o src/addroundkey/addroundkey.o \
	src/melangecolonnes/melangecolonnes.o src/tools/tools.o src/key_extension/key_extension.o src/ctr/ctr.o src/aes/aes.o \
	src/attack/attack.o src/tools/command_line.o src/plaintext/plaintext.o src/tools/exec.o src/nonce/nonce.o src/key_reduction/key_reduction.o
BIN = src/main

run: $(BIN)
	./$(BIN) -h

nonce: $(BIN)
	./$(BIN) -nonce

enc: $(BIN)
	./$(BIN) "aes128 clemaitre" "azertyuiopqsdfgh" -e matrices.txt -out matrices.txt

att: $(BIN)
	./$(BIN) "aes128_clemaitre" "IUIIIIIIIIIIIIII" -a matrices.txt

test: $(BIN)
	time ./$(BIN) "aes128_clemaitre" "IUIIIIIIIIIIIIII" -a matrices.txt
	time ./$(BIN) "aes128 clemaitre" "IUIIIIIIIIIIIIII" -a matrices.txt
	time ./$(BIN) "aes128 0987aitre" "IUIIIIIIIIIIIIII" -a matrices.txt


valgrind:  $(BIN)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  ./$(BIN) "thats my kung fu" "IUIIIIIIIIIIIIII" -e matrices.txt -out matrices.txt

valgrind-att: $(BIN)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  ./$(BIN) "aes128_clemaitre" "IUIIIIIIIIIIIIII" -a matrices.txt

$(BIN): $(OBJS)

clean:
	$(RM) $(OBJS) $(BIN)
	$(RM) vgcore.*
	$(RM) -R .vscode
