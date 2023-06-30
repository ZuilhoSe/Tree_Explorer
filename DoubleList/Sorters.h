#ifndef SORTERS
#define SORTERS
#include "doubleLinkedList.h"



typedef class BubbleSorter
{

    private:
        bool comparison(int a, int b) {return a > b;}
    public:
        DoubleList* list;
        bool IsSorted=false;

        BubbleSorter() {}
        BubbleSorter(DoubleList* base): list(base) {}
        ~BubbleSorter() {};

        void sort(){}

};
BubbleSorter;


#endif


