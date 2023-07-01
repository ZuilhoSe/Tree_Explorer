test: listTest
	./listTest

listTest: Sorters.o doubleLinkedList.o listTest.cpp
	g++ listTest.cpp doubleLinkedList.o Sorters.o -Wall -Werror -Og -g -o listTest

Sorters.o: doubleLinkedList.o Sorters.cpp Sorters.h
	g++ Sorters.cpp -c

doubleLinkedList.o: doubleLinkedList.cpp doubleLinkedList.h
	g++ doubleLinkedList.cpp -c

clean:
	rm listTest doubleLinkedList.o Sorters.o
