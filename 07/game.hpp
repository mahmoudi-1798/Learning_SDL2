#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "object.hpp"
#include "entity.hpp"

using namespace std;

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
private:
  SDL_Renderer* ren;
  SDL_Window* win;
  TTF_Font *font;
  bool running;
  int count;
  int frameCount, timerFPS, lastFrame;
  Object star;
  int mousex, mousey;
  Entity player;
  int idol, shield;
};



#endif