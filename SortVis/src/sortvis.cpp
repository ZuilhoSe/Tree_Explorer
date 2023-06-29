#include "doublelist.h"
#include "bubblesorter.h"
#include "insertsorter.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <fstream>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 600

#define COLUMN_MAX_HEIGHT_RATIO 100
#define COLUMN_MIN_HEIGHT_RATIO 0

#define FPS 60
#define IPS 6000

using std::cout;
using std::endl;
using std::ifstream;

int main(int argc, char* argv[]) {
    // ==== Check inputs ====
    if (argc < 2) {
        cout << "Usage: sortvis FILE SORTER" << endl;
        return 1;
    }

    ifstream valuesFile;
    valuesFile.open(argv[1]);
    if (valuesFile.fail()) {
        cout << "Failed to open file" << endl;
        return 1;
    }

    // ==== List setup ====
    List valuesList;
    int value;

    valuesFile >> value;
    while (valuesFile.good()) {
        Node* newNode = new Node(value);
        newNode->prev = valuesList.last;

        if (valuesList.last != nullptr) {
            valuesList.last->next = newNode;
        }
        else {
            valuesList.first = newNode;
        }
        valuesList.last = newNode;

        valuesFile >> value;
    }

    if (!valuesFile.eof()) {
        cout << "Found an invalid entry in file" << endl;
        return 1;
    }

    // ==== SDL2 shenanigans ====
    // Init SDL2 video
    if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize the SDL video sub system: %s\n", SDL_GetError());
        return 1;
    }

    //Create window
    SDL_Window* window = SDL_CreateWindow("Test Window", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                              SCREEN_HEIGHT, 0);
    if (window == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window: %s\n", SDL_GetError());
        return 1;
    }

    //Create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create renderer: %s\n", SDL_GetError());
        return 1;
    }

    // == TODO: FINISH THE SWITCH OR IT WON'T WORK == //
    /*
    void (*sorter)(&valuesList) = nullptr;
    switch(argv[2]) {
        case 'b':
            BubbleSorter* sorter = new BubbleSorter(&valuesList);
            break;

        case 'i':
            InsertSorter* sorter = new InsertSorter(&valuesList);
            break;

        default:
            cout << "Invalid sorter identifier" << endl;
            return 1;
    }
    */

    //bubbleSort(sorter);
    //insertSort(sorter);

    InsertSorter* sorter = new InsertSorter(&valuesList);

    int listLength = getListLength(valuesList);
    int columnWidth = SCREEN_WIDTH/listLength;
    int minColVal = getListMin(valuesList);
    int maxColVal = getListMax(valuesList);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    Uint64 currTime;
    Uint64 lastFrameTime, deltaFrameTime;
    Uint64 lastIterTime, deltaIterTime;
    currTime = SDL_GetTicks64();
    lastFrameTime = currTime;
    lastIterTime = currTime;
    Uint64 millisPerFrame = 1000/FPS;
    Uint64 millisPerIter = 1000/IPS;

    bool running = true;
    while (running)
    {
        //check events
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
                break;
            }
        }
        
        currTime = SDL_GetTicks64();
        deltaFrameTime = currTime - lastFrameTime;
        deltaIterTime = currTime - lastIterTime;

        //Iterate sorter
        if (deltaIterTime > millisPerIter) {
            //update time
            lastIterTime = currTime;

            //sort step
            //if (!sorter->sorted) iterBubble(sorter);
            if (!sorter->sorted) iterInsert(sorter);
        }

        //Render a frame
        if (deltaFrameTime > millisPerFrame) {
            //update time
            lastFrameTime = currTime;

            //clear screen
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);

            //render columns
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

            Node* currNode = valuesList.first;
            int count = 0;
            while (currNode != nullptr) {
                int columnHeight = (SCREEN_HEIGHT*(100 - COLUMN_MIN_HEIGHT_RATIO))/100 - ((currNode->val - minColVal)*(COLUMN_MAX_HEIGHT_RATIO - COLUMN_MIN_HEIGHT_RATIO)*SCREEN_HEIGHT)/((maxColVal - minColVal)*100);

                SDL_Rect columnRect = {(SCREEN_WIDTH - (listLength*columnWidth))/2 + count*columnWidth,
                                      columnHeight,
                                      columnWidth,
                                      SCREEN_HEIGHT-columnHeight};

                //Different color for the sorter's current node
                if (currNode == sorter->currNode) {
                    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                    SDL_RenderFillRect(renderer, &columnRect);
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                }
                else {
                    SDL_RenderFillRect(renderer, &columnRect);
                }

                currNode = currNode->next;
                count++;
            }

            SDL_RenderPresent(renderer);
        }
    }

    valuesFile.close();

    return 0;
}
