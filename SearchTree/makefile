
test: treeTest
	./treeTest

treeTest: binarySearchTree.o treeTest.cpp
	g++ treeTest.cpp binarySearchTree.o -Wall -Werror -Og -g -o treeTest

binarySearchTree.o: binarySearchTree.cpp binarySearchTree.h
	g++ binarySearchTree.cpp -c

clean:
	rm treeTest SearchTree.o