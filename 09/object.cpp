#include "object.hpp"

void Object::setDest(int x, int y, int w, int h){
    dest.x = x;
    dest.y = y;
    dest.w = w;
    dest.h = h;
}

void Object::setDest(int x, int y){
    dest.x = x;
    dest.y = y;
}

void Object::setSource(int x, int y, int w, int h){
    src.x = x;
    src.y = y;
    src.w = w;
    src.h = h;
}
void Object::setImage(std::string fileName, SDL_Renderer* ren){
    SDL_Surface* surf = IMG_Load(fileName.c_str());
    tex = SDL_CreateTextureFromSurface(ren, surf);
    //tex = IMG_LoadTexture(ren, fileName.c_str());

}

int Object::getDX(){
    return dest.x;
}

int Object::getDY(){
    return dest.y;
}