//
// Created by juicylucy on 12/28/22.
//

#include "Board.h"
#include "Colors.h"

Board::Board(SDL_Renderer* sdlRenderer) {
    this->sdlRenderer = sdlRenderer;
    this->pieceTexture.first = IMG_LoadTexture(sdlRenderer,"../assets/chess.png");
    SDL_QueryTexture(this->pieceTexture.first, nullptr, nullptr,&pieceTexture.second[0],&pieceTexture.second[1]);
    this->square = {0};
    for(int i = 1; i <= 7; i++) {square[i-1] = i | 16;}
    this->loadPositionFromFen(startFEN);
}

void Board::display(int width, int height) {
    SDL_Rect dstRect,srcRect;
    dstRect.w = width / 8; srcRect.w = this->pieceTexture.second[0] / 6;
    dstRect.h = height / 8; srcRect.h = this->pieceTexture.second[1] / 2 ;
    int mouseX,mouseY;
    SDL_GetMouseState(&mouseX,&mouseY);
    for(int y = 0; y < 8; y++) {
        dstRect.y = y * dstRect.h;
        for(int x = 0; x < 8; x++) {
            dstRect.x = x * dstRect.w;
            if((x+y)%2) {
                SetRenderColor(sdlRenderer,COLOR_A);
            } else {
                SetRenderColor(sdlRenderer,COLOR_B);
            }
            if(x == mouseX/(dstRect.w) && mouseY/(dstRect.h) == y) {
                SetRenderColor(sdlRenderer,"#00ff00");
                sx = x; sy = y;
            }
            SDL_RenderFillRect(sdlRenderer,&dstRect);
            unsigned piece = square[y*8 + x];
            if(piece) {
                if(piece & Piece::WHITE){
                    srcRect.y = 0;
                    piece &= ~Piece::WHITE;
                }
                else {
                    srcRect.y = srcRect.h;
                    piece &= ~Piece::BLACK;
                }

                piece--;
                srcRect.x = srcRect.w * (int)piece;
                SDL_RenderCopy(sdlRenderer,pieceTexture.first,&srcRect,&dstRect);
            }


        }
    }
}



void Board::loadPositionFromFen(const char* fen) {
    std::string fen_board(fen);
    fen_board = fen_board.substr(0, fen_board.find(' '));
    int file = 0,rank = 7;
    for(char symbol : fen_board) {
        if(symbol == '/') {
            file = 0;
            rank--;
        } else {
            if(isdigit(symbol)) {
                file += (int)symbol;
            } else {
                Piece piece_color = (isupper(symbol)) ? Piece::WHITE : Piece::BLACK;
                Piece piece_type = lookUpTable[(char)tolower(symbol)];
                square[rank * 8 + file] = piece_type | piece_color;
                file++;
            }
        }
    }
}


