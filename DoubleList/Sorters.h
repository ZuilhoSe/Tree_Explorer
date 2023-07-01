#ifndef SORTERS
#define SORTERS
#include "doubleLinkedList.h"
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 600

#define COLUMN_MAX_HEIGHT_RATIO 100
#define COLUMN_MIN_HEIGHT_RATIO 0

#define FPS 144
#define IPS 144
typedef class BubbleSorter
{
    private:
        DoubleList* list;

        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;

        bool hasVisualization;
        bool IsSorted=false;
    public:
        BubbleSorter(DoubleList* base, bool hV);
        ~BubbleSorter() {};

        void sort();
}BubbleSorter;

typedef class InsertionSorter
{

    private:
    public:
        DoubleList* list;
        bool IsSorted=false;

        InsertionSorter() {}
        InsertionSorter(DoubleList* base): list(base) {}
        ~InsertionSorter() {};

        void sort();

}InsertionSorter;

typedef class SelectionSorter
{
    private:
    public:
        DoubleList* list;
        bool IsSorted=false;

        SelectionSorter() {}
        SelectionSorter(DoubleList* base): list(base) {}
        ~SelectionSorter() {};

        void sort();
}SelectionSorter;

typedef class ShellSorter
{
    public:
    DoubleList* list;
    bool IsSorted=false;

    ShellSorter() {}
    ShellSorter(DoubleList* base): list(base) {}
    ~ShellSorter() {};

    void sort();
}ShellSorter;

#endif


