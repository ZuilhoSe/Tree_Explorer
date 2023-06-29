#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 600

int main (int argc, char *argv[])
{
    //Init SDL2 video
    if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize the SDL video sub system: %s\n", SDL_GetError());
        return 1;
    }

    //Create window
    SDL_Window* window = SDL_CreateWindow("Test Window", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                              SCREEN_HEIGHT, 0);
    if (window == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window: %s\n", SDL_GetError());
        return 1;
    }

    //Create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create renderer: %s\n", SDL_GetError());
        return 1;
    }

    SDL_SetRenderDrawColor(renderer, 0, 30, 20, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

   printf("Drivers:\n %s;\n %s;\n %s.\n", info[0].name, info[1].name, info[2].name);

    //TODO: Figure out how to do textures. Unlock the power of the GPU.

    Uint64 prevTime, currTime, deltaTime;
    prevTime = SDL_GetTicks64();

    bool running = true;
    while (running)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
                break;
            }
        }

/*
        SDL_SetRenderDrawColor(renderer, 0, 30, 20, 255);
        SDL_RenderClear(renderer);

        currTime = SDL_GetTicks64();
        deltaTime = currTime-prevTime;
        prevTime = currTime;

        int x1 = (currTime/1)%SCREEN_WIDTH, y1 = (currTime/20)%SCREEN_HEIGHT;
        int x2 = (currTime/10)%SCREEN_WIDTH, y2 = (currTime/2)%SCREEN_HEIGHT;

        SDL_SetRenderDrawColor(renderer, 80, 200, 100, 255);
        SDL_RenderDrawLine(renderer, x1, y1, x2, y2);

        SDL_RenderPresent(renderer);
*/

    }
    printf("Ended main loop.\n");

    printf("Shutdown.\n");
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
