#include "object.hpp"

void Object::setDest(int x, int y, int w, int h){
    dest.x = x;
    dest.y = y;
    dest.w = w;
    dest.h = h;
}

void Object::setSource(int x, int y, int w, int h){
    src.x = x;
    src.y = y;
    src.w = w;
    src.h = h;
}
void Object::setImage(std::string fileName, SDL_Renderer* ren){
    SDL_Surface* surf;
    if(IMG_Load(fileName.c_str()) < 0){
        std::cout << "Failed at IMG_load(), error: " << IMG_GetError() << std::endl;
    } else {
        surf = IMG_Load(fileName.c_str());
    }
    
    tex = SDL_CreateTextureFromSurface(ren, surf);
    //tex = IMG_LoadTexture(ren, fileName.c_str());

}