Bard: main.o LinkedList.o
	gcc main.o LinkedList.o -o bard

main.o: main.c LinkedList.h
	gcc -c main.c

LinkedList.o: LinkedList.c LinkedList.h
	gcc -c LinkedList.c


clean:
	rm *.o
	rm bard

