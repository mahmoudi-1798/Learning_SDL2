#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class Object{
    private:
        SDL_Rect dest;
        SDL_Rect src;
        SDL_Texture* tex;

    public:
        Object();

        SDL_Rect getDest() const {return dest;}
        SDL_Rect getSource() const {return src;}
        SDL_Texture* getTex() const {return tex;}
        void setDest(int x, int y, int w, int h);
        void setSource(int x, int y, int w, int h);
        void setImage(std::string fileName, SDL_Renderer* ren);

};



#endif