#include <stdio.h>
#include <SDL2/SDL.h>
#include "../headers/errors.h"
#include "../headers/constants.h"
//initialize constants declared in constants.h
const char* GAME_TITLE = "Snake";
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;
int main(int argc, char** argv) {
    //initalize all the SDL subsystems that will be needed (video, audio, keyboard input)
    if(SDL_Init(SDL_INIT_VIDEO) != 0  &&  SDL_Init(SDL_INIT_AUDIO) != 0 && 
    SDL_Init(SDL_INIT_EVENTS) != 0 && SDL_Init(SDL_INIT_TIMER) != 0) {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return SDL_INITIALIZATION_FAILED;
    }


    //Create the SDL window and renderer
    SDL_Window* window = SDL_CreateWindow(
    GAME_TITLE,
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
    0);
    if(!window) {
        SDL_Log("Failed to create a window: %s", SDL_GetError());
        return SDL_WINDOW_CREATION_FAILED;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED
    );
    if(!renderer) {
        SDL_Log("Failed to create a renderer: %s", SDL_GetError());
        return SDL_RENDERER_CREATION_FAILED;
    }

    //draw a black screen
    if(SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255) != 0) {
        SDL_Log("Failed to set renderer's draw color: %s", SDL_GetError());
        return SDL_DRAW_COLOR_SETTING_FAILED;
    }
    if(SDL_RenderClear(renderer) != 0) {
        SDL_Log("Failed to clear the screen: %s", SDL_GetError());
        return SDL_CLEARING_FAILED;
    }
    SDL_RenderPresent(renderer);

    SDL_Delay(10000);
    
    return SUCCESSFUL;
}