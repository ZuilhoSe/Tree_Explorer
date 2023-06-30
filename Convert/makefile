test: testConvert
	./testConvert

testConvert: convertTreeList.o
	g++ testConvert.cpp convertTreeList.o ../SearchTree/binarySearchTree.o ../DoubleList/doubleLinkedList.o -o testConvert

convertTreeList.o: convertTreeList.h testConvert.cpp tree1.txt \
		  ../SearchTree/binarySearchTree.o \
	      ../DoubleList/doubleLinkedList.o
	g++ convertTreeList.cpp ../SearchTree/binarySearchTree.o ../DoubleList/doubleLinkedList.o -c

clean:
	rm testConvert
