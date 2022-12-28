#include <SDL.h>
#include <SDL_image.h>
#include "RenderWindow.h"
#include <iostream>

int main(int argc,char** argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    RenderWindow window("Chess v1.0",640,640);
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "best" );
    while(!window.shouldClose) {
        SDL_Event sdlEvent;
        while(SDL_PollEvent(&sdlEvent))
        {
            window.HandleEvent(&sdlEvent);
        }
        window.Clear();
        window.ShowBoard();

        window.Display();

    }
    window.Destroy();
    SDL_Quit();
    IMG_Quit();
    return 0;
}