run: principal
	./main matrices.txt

principal: main.o matrices.o decalelignes.o
	gcc -Wall main.o matrices.o decalelignes.o -o main -g

matrices.o: matrices.c matrices.h
	gcc -Wall -c matrices.c -g

decalelignes.o: decalelignes.c decalelignes.h
	gcc -Wall -c decalelignes.c -g

main.o: main.c matrices.h decalelignes.h
	gcc -Wall -c main.c -g

valgrind: principal
	valgrind --leak-check=full --show-leak-kinds=all ./main


clean:
	rm -f *.o
	rm -f main
	ls -l