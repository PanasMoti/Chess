//
// Created by juicylucy on 12/28/22.
//

#include "RenderWindow.h"



RenderWindow::RenderWindow(const char *title, int width, int height)
: ren(nullptr),win(nullptr){
    this->width = width;
    this->height = height;
    this->win = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_SHOWN);
    this->ren = SDL_CreateRenderer(this->win,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    this->shouldClose = false;
    this->board = new Board(this->ren);
}

void RenderWindow::Destroy() {
    SDL_DestroyWindow(this->win);
    SDL_DestroyRenderer(this->ren);
    delete this->board;
}

void RenderWindow::Clear() {
    SDL_SetRenderDrawColor(ren,0,0,0,0);
    SDL_RenderClear(ren);
}

void RenderWindow::ShowBoard() {
    this->board->display(width,height);
}

void RenderWindow::Display() {
    SDL_RenderPresent(ren);
}

void RenderWindow::HandleEvent(SDL_Event *sdlEvent) {

    switch(sdlEvent->type) {
        case SDL_QUIT:
            shouldClose = true;
            break;
        case SDL_MOUSEBUTTONDOWN:
            fprintf(stdout,"selected cell: %d %d\n",board->sx,board->sy);
            break;
    }

}
