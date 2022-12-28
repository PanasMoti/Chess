//
// Created by juicylucy on 12/28/22.
//

#ifndef INC_3DRENDERING_BOARD_H
#define INC_3DRENDERING_BOARD_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <unordered_map>

#define COLOR_A     "#7c8a8f"
#define COLOR_B     "#27242f"
#include <string>

enum Piece :unsigned int{
    NONE    = 0,    // 00 000
    KING    = 1,    // 00 001
    QUEEN    = 2,    // 00 010
    BISHOP  = 3,    // 00 011
    KNIGHT  = 4,    // 00 100
    ROOK    = 5,    // 00 101
    PAWN   = 6,    // 00 110
    WHITE   = 8,    // 01 000
    BLACK   = 16    // 10 000
};


static const char* startFEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

static inline std::unordered_map<char,Piece> lookUpTable = {
        {'p',Piece::PAWN},
        {'k',Piece::KING},
        {'n',Piece::KNIGHT},
        {'b',Piece::BISHOP},
        {'r',Piece::ROOK},
        {'q',Piece::QUEEN},
};




class Board {
public:
    explicit Board(SDL_Renderer*);
    void display(int width,int height);
    void loadPositionFromFen(const char* fen);
    int sx,sy;
private:
    std::array<unsigned ,64> square{};
    std::pair<SDL_Texture*,std::array<int,2>> pieceTexture;
    SDL_Renderer* sdlRenderer;
};


#endif //INC_3DRENDERING_BOARD_H
