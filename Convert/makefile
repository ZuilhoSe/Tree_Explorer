test: testConvert tree1.txt
	./testConvert

testConvert: convertTreeList.o \
			../SearchTree/binarySearchTree.o \
			../DoubleList/doubleLinkedList.o
	g++ testConvert.cpp convertTreeList.o ../SearchTree/binarySearchTree.o ../DoubleList/doubleLinkedList.o -o testConvert

convertTreeList.o: convertTreeList.h testConvert.cpp
	g++ convertTreeList.cpp -c

clean:
	rm testConvert
