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
	./Convert/convertTreeList.o \
	-o menu -I include -L lib -lmingw32 -lSDL2main -lSDL2

DoubleList/doubleLinkedList: ./DoubleList/doubleLinkedList.cpp \
	./DoubleList/doubleLinkedList.h
	g++ -c ./DoubleList/doubleLinkedList.cpp -o ./DoubleList/doubleLinkedList.o

DoubleList/Sorters: ./DoubleList/Sorters.cpp \
	./DoubleList/Sorters.h
	g++ -c ./DoubleList/Sorters.cpp -o ./DoubleList/Sorters.o

SearchTree/binarySearchTree: ./SearchTree/binarySearchTree.cpp \
	./SearchTree/binarySearchTree.h
	g++ -c ./SearchTree/binarySearchTree.cpp -o ./SearchTree/binarySearchTree.o

Convert/convertTreeList: ./Convert/convertTreeList.cpp \
	./Convert/convertTreeList.h
	g++ -c ./Convert/convertTreeList.cpp -o ./Convert/convertTreeList.o

