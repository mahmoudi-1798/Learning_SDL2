#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

class Game{
    private:
        SDL_Renderer* ren;
        SDL_Window* win;
        bool running;
        int count;
        int frameCount, timerFPS, lastFrame;

    public:
        Game();
        ~Game();
        void loop();
        void update();
        void input();
        void render();

};



#endif