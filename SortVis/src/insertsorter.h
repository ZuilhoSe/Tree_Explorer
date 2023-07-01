#ifndef INSERT_SORTER
#define INSERT_SORTER

#include "doublelist.h"

    typedef struct InsertSorter {
        Node* dlimNode = nullptr;
        Node* currNode = nullptr;
        List* list;
        bool swapped = false;
        bool sorted = false;

        InsertSorter(List* l): dlimNode(l->first), currNode(l->first->next), list(l) {}
    } InsertSorter;

void insertSort(InsertSorter*);

void iterInsert(InsertSorter*);

#endif
