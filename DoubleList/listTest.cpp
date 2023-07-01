#include <iostream>
#include "doubleLinkedList.h"
#include "Sorters.h"

int main(int argc, char** argv)
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

    testList.pushFirst(22);
    testList.pushFirst(1);
    testList.pushFirst(41);
    testList.pushFirst(11);
    testList.pushFirst(22);
    testList.pushFirst(16);
    testList.pushFirst(61);
    testList.pushFirst(9);
    testList.pushFirst(21);
    testList.pushFirst(22);
    testList.pushFirst(43);
    testList.pushFirst(7);
    testList.printList();

    //Insertion test
    {
        InsertionSorter insertionsorter(&testList, true);
        insertionsorter.sort();
        testList.printList();
    }

    testList.pushFirst(17);
    testList.pushFirst(13);
    testList.pushFirst(1);
    testList.pushFirst(27);
    testList.pushFirst(11);
    testList.pushFirst(22);
    testList.pushFirst(910);
    testList.pushFirst(91);
    testList.pushFirst(9);
    testList.pushFirst(7);
    //Bubble test
    BubbleSorter bubblesorter(&testList, true);
    bubblesorter.sort();
    testList.printList();

    testList.pushFirst(747);
    testList.pushFirst(861);
    testList.pushFirst(1);
    testList.pushFirst(1091);
    testList.pushFirst(511);

    //Selection test
    SelectionSorter selectionsorter(&testList, true);
    selectionsorter.sort();
    testList.printList();

    testList.pushFirst(172);
    testList.pushFirst(12);
    testList.pushFirst(122);
    testList.pushFirst(22);
    testList.pushFirst(910);
    testList.pushFirst(91);
    testList.pushFirst(9);
    testList.pushFirst(7);
    testList.pushFirst(8);
    testList.pushFirst(0);
    testList.pushFirst(13);


    //Shell test
    ShellSorter shellsorter;
    new (&shellsorter) ShellSorter();
    shellsorter.list = &testList;
    testList.printList();
    shellsorter.sort();
    testList.printList();

    return 0;
}
