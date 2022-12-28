//
// Created by juicylucy on 12/28/22.
//

#ifndef INC_3DRENDERING_COLORS_H
#define INC_3DRENDERING_COLORS_H
#include <SDL2/SDL.h>
#include <string>

struct Color {
    std::string hexCode;
    Color() {
        this->hexCode = "#000000";
    }
    explicit Color(const char* hexCode) {
        this->hexCode = hexCode;
    }

};

static void SetRenderColor(SDL_Renderer* sdlRenderer,const Color& color) {
    const char* format = (color.hexCode.find('#') != std::string::npos)?  "#%02hhx%02hhx%02hhx" : "%02hhx%02hhx%02hhx";
    Uint8 r,g,b;
    sscanf(color.hexCode.c_str(),format,&r,&g,&b);
    SDL_SetRenderDrawColor(sdlRenderer,r,g,b,255);

}

static void SetRenderColor(SDL_Renderer* sdlRenderer,const std::string& hexCode) {
    const char* format = (hexCode.find('#') != std::string::npos)?  "#%02hhx%02hhx%02hhx" : "%02hhx%02hhx%02hhx";
    Uint8 r,g,b;
    sscanf(hexCode.c_str(),format,&r,&g,&b);
    SDL_SetRenderDrawColor(sdlRenderer,r,g,b,255);

}

#endif //INC_3DRENDERING_COLORS_H
