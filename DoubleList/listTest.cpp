#include <iostream>
#include "doubleLinkedList.h"
#include "Sorters.h"

int main()
{
    DoubleList testList;
    testList.pushLast(5);
    testList.pushLast(10);
    std::cout << testList.length() << std::endl;
    testList.printList();

    testList.pushFirst(-10);
    testList.pushLast(20);
    std::cout << testList.length() << std::endl;
    testList.printList();

    std::cout << testList.popFirst() << std::endl;
    testList.printList();

    std::cout << testList.popLast() << std::endl;
    testList.printList();

    testList.pushFirst(89);
    std::cout << testList.length() << std::endl;
    testList.pushFirst(12);
    testList.pushFirst(01);
    testList.printList();

    //Insertion test
    InsertionSorter insertionsorter;
    new (&insertionsorter) InsertionSorter();
    insertionsorter.list = &testList;
    insertionsorter.sort();
    testList.printList();

    testList.pushFirst(17);
    testList.pushFirst(13);
    testList.pushFirst(1);
    testList.pushFirst(27);
    testList.pushFirst(11);

    //Bubble test
    BubbleSorter bubblesorter;
    new (&bubblesorter) BubbleSorter();
    bubblesorter.list = &testList;
    bubblesorter.sort();
    testList.printList();

    testList.pushFirst(747);
    testList.pushFirst(861);
    testList.pushFirst(1);
    testList.pushFirst(1091);
    testList.pushFirst(511);

    //Selection test
    SelectionSorter selectionsorter;
    new (&selectionsorter) SelectionSorter();
    selectionsorter.list = &testList;
    selectionsorter.sort();
    testList.printList();



    return 0;
}
