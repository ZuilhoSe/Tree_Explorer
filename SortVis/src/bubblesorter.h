#ifndef BUBBLE_SORTER
#define BUBBLE_SORTER

#include "doublelist.h"

typedef struct BubbleSorter {
    Node* currNode = nullptr;
    Node* dlimNode = nullptr;
    List* list = nullptr;
    bool sortedUpToCurr = true;
    bool sorted = false;

    BubbleSorter(List* l): currNode(l->first), dlimNode(l->last), list(l) {}
} BubbleSorter;

void bubbleSort (BubbleSorter*);

void iterBubble (BubbleSorter*);

#endif
