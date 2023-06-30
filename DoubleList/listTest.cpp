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

    InsertionSorter sorter;
    new (&sorter) InsertionSorter();
    sorter.list = &testList;
    sorter.sort();
    testList.printList();

    return 0;
}
