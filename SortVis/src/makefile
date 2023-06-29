debug: doublelist.o bubblesorter.o insertsorter.o
	g++ sortvis.cpp doublelist.o bubblesorter.o insertsorter.o `sdl2-config --libs` -Werror -Wall -Og -g -o ../debug/sortvis

release:
	g++ sortvis.cpp doublelist.o bubblesorter.o insertsorter.o `sdl2-config --libs` -O2 -o ../release/sortvis

test: debug
	../debug/sortvis testfile.txt

bubblesorter.o: bubblesorter.cpp doublelist.o
	g++ bubblesorter.cpp -c

insertsorter.o: insertsorter.cpp doublelist.o
	g++ insertsorter.cpp -c

doublelist.o: doublelist.cpp
	g++ doublelist.cpp -c
