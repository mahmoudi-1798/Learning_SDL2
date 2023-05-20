#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <iostream>
#include "object.h"

using namespace std;

class Game{
    private:
        SDL_Renderer* ren;
        SDL_Window* win;
        bool running;
        int count;
        int frameCount, timerFPS, lastFrame;
        Object star;

    public:
        Game();
        ~Game();
        void loop();
        void update();
        void input();
        void render();
        void draw(Object o);

};



#endif