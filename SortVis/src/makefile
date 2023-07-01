debug: doublelist.o bubblesorter.o insertsorter.o
	g++  sortvis.cpp doublelist.o -Iinclude -Llib  bubblesorter.o insertsorter.o -Werror -Wall -lmingw32 -lSDL2main -lSDL2 -Og -g -o ../debug/sortvis

release:
	g++ -I ./include -L ./lib  sortvis.cpp doublelist.o bubblesorter.o insertsorter.o -l SDL2main -l SDL2 -O2 -o ../release/sortvis

test: debug
	../debug/sortvis testfile.txt

bubblesorter.o: bubblesorter.cpp doublelist.o
	g++ bubblesorter.cpp -c

insertsorter.o: insertsorter.cpp doublelist.o
	g++ insertsorter.cpp -c

doublelist.o: doublelist.cpp
	g++ doublelist.cpp -c
