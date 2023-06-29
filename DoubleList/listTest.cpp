#include <iostream>
#include "doubleLinkedList.h"

int main()
{
    DoubleList testList;
    testList.appendValue(5);
    testList.appendValue(10);
    testList.prependValue(-10);
    testList.appendValue(20);
    testList.printList();

    return 0;
}
