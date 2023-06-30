
test: treeTest
	./treeTest

treeTest: binarySearchTree.o ../DoubleList/doubleLinkedList.o treeTest.cpp
	g++ treeTest.cpp binarySearchTree.o ../DoubleList/doubleLinkedList.o -Wall -Werror -Og -g -o treeTest

binarySearchTree.o: \
	binarySearchTree.cpp binarySearchTree.h \
	../DoubleList/doubleLinkedList.h
	g++ binarySearchTree.cpp -c

../DoubleList/doubleLinkedList.o: ../DoubleList/doubleLinkedList.h ../DoubleList/doubleLinkedList.cpp
	g++ -I ../DoubleList ../DoubleList/doubleLinkedList.cpp -c

clean:
	rm treeTest binarySearchTree.o
