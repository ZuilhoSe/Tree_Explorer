test: listTest
	./listTest

listTest: Sorters.o doubleLinkedList.o listTest.cpp
	g++ listTest.cpp doubleLinkedList.o Sorters.o -Wall -Werror -Og -g -o listTest

Sorters.o: doubleLinkedList.o Sorters.cpp Sorters.h
	g++ Sorters.cpp -c -I include -L lib -lmingw32 -lSDL2main -lSDL2

doubleLinkedList.o: doubleLinkedList.cpp doubleLinkedList.h
	g++ doubleLinkedList.cpp -c

clean:
	rm listTest doubleLinkedList.o Sorters.o
