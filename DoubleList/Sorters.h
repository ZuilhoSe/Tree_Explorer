#ifndef SORTERS
#define SORTERS
#include "doubleLinkedList.h"

typedef class BubbleSorter
{
    public:
        DoubleList* list;

        BubbleSorter() {}
        BubbleSorter(DoubleList* base): list(base) {}

        bool isSorted=false;

        void sort();
}BubbleSorter;

typedef class InsertionSorter
{
    public:
        DoubleList* list;

        InsertionSorter() {}
        InsertionSorter(DoubleList* base): list(base) {}

        bool isSorted=false;

        void sort();

}InsertionSorter;

typedef class SelectionSorter
{
    public:
        DoubleList* list;  

        SelectionSorter() {}
        SelectionSorter(DoubleList* base): list(base) {}

        bool IsSorted=false;

        void sort();
}SelectionSorter;

typedef class ShellSorter
{
    public:
        DoubleList* list;

        ShellSorter() {}
        ShellSorter(DoubleList* base): list(base) {}

        bool IsSorted=false;

        void sort();
}ShellSorter;

#endif


