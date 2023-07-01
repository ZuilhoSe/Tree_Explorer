#ifndef SORTERS
#define SORTERS
#include "doubleLinkedList.h"
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 600

#define COLUMN_MAX_HEIGHT_RATIO 100
#define COLUMN_MIN_HEIGHT_RATIO 0

#define FPS 144
#define IPS 10
typedef class BubbleSorter
{
    private:
        DoubleList* list;

        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;

        bool hasVisualization;
    public:
        BubbleSorter(DoubleList* base, bool hV);
        ~BubbleSorter();

        bool isSorted=false;

        void sort();
}BubbleSorter;

typedef class InsertionSorter
{
    private:
        DoubleList* list;

        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;

        bool hasVisualization;
    public:
        InsertionSorter(DoubleList* base, bool hV);
        ~InsertionSorter();

        bool isSorted=false;

        void sort();

}InsertionSorter;

typedef class SelectionSorter
{
    private:
        DoubleList* list;

        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;

        bool hasVisualization;
    public:
        SelectionSorter(DoubleList* base, bool hV);
        ~SelectionSorter();

        bool IsSorted=false;

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


