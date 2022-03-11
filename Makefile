run: principal
	./main matrices.txt

principal: main.o matrices.o SubOctet.o decalelignes.o
	gcc -Wall main.o matrices.o SubOctet.o decalelignes.o -o main -g

compile: main.o suboctet.o 
	gcc -o main main.o SubOctet.o

decalelignes.o: decalelignes.c decalelignes.h
	gcc -Wall -c decalelignes.c -g

SubOctet.o: SubOctet.c SubOctet.h
	gcc -Wall -c SubOctet.c -g

main.o: main.c matrices.h decalelignes.h
	gcc -Wall -c main.c -g

valgrind: principal
	valgrind --leak-check=full --show-leak-kinds=all ./main


clean:
	rm -f *.o
	rm -f main
	ls -l
