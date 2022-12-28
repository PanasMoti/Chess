//
// Created by juicylucy on 12/28/22.
//

#ifndef INC_3DRENDERING_RENDERWINDOW_H
#define INC_3DRENDERING_RENDERWINDOW_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Board.h"
#include "Colors.h"


class RenderWindow {
    using RendererP = SDL_Renderer*;
    using WindowP = SDL_Window*;
public:
    RenderWindow(const char*,int,int);
    bool shouldClose;
    void Clear();
    void HandleEvent(SDL_Event* sdlEvent);
    void ShowBoard();
    void Display();
    void Destroy();

private:
    WindowP win;
    RendererP ren;
    Board* board;
    int width; int height;

};


#endif //INC_3DRENDERING_RENDERWINDOW_H
