#ifndef SORTERS
#define SORTERS
#include "doubleLinkedList.h"



typedef class BubbleSorter
{

    private:
    public:
        DoubleList* list;
        bool IsSorted=false;

        BubbleSorter() {}
        BubbleSorter(DoubleList* base): list(base) {}
        ~BubbleSorter() {};

        void sort();

}BubbleSorter;


#endif


