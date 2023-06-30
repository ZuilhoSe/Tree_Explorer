
test: menu
	./menu
menu: ./DoubleList/doubleLinkedList.o \
		./DoubleList/Sorters.o \
		./SearchTree/binarySearchTree.o \
		./Convert/convertTreeList.o \
		menu.cpp
	g++ menu.cpp ./DoubleList/doubleLinkedList.o \
	./SearchTree/binarySearchTree.o \
	./DoubleList/Sorters.o \
	./Convert/convertTreeList.o -o menu