test: listTest
	./listTest

listTest: doubleLinkedList.o listTest.cpp
	g++ listTest.cpp doubleLinkedList.o -Wall -Werror -Og -g -o listTest

doubleLinkedList.o: doubleLinkedList.cpp doubleLinkedList.h
	g++ doubleLinkedList.cpp -c
