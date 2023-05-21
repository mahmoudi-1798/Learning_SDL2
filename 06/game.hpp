#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "object.hpp"
#include "audio.hpp"

using namespace std;

class Game{
    private:
        SDL_Renderer* ren;
        SDL_Window* win;
        bool running;
        int count;
        int frameCount, timerFPS, lastFrame;
        Object star;
        TTF_Font * font;
        int mouseX, mouseY;
        Audio effect;

    public:
        Game();
        ~Game();
        void loop();
        void update() {};
        void input();
        void render();
        void draw(Object o);
        void draw(const char* msg, int x, int y, int r, int g, int b);

};



#endif