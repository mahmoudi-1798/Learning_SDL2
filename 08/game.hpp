#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <fstream>
#include <vector>

#include "object.hpp"
#include "entity.hpp"

using namespace std;

#define WIDTH 1000
#define HEIGHT 750
#define TILE_SIZE 25

class Game {
    public:
        Game();
        ~Game();
        void loop();
        void update();
        void input();
        void render();
        void draw(Object o);
        void draw(const char* msg, int x, int y, int r, int g, int b);
        void loadMap(const char* fileName);
        void drawMap();
    private:
        SDL_Renderer* ren;
        SDL_Window* win;
        TTF_Font *font;
        bool running;
        int count;
        int frameCount, timerFPS, lastFrame;
        int mousex, mousey;
        Entity player;
        vector<Object> map;
};



#endif