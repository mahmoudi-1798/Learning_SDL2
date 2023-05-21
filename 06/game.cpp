#include "game.hpp"

Game::Game(){
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(720, 480, 0, &win, &ren);
    SDL_SetWindowTitle(win, "First Game!!!");
    TTF_Init();
    running = true;
    count = 0;
    star.setDest(250, 250, 200, 200);
    star.setSource(0, 0, 75, 75);
    star.setImage("image.png", ren);
    font = TTF_OpenFont("sans.ttf", 50);
    effect.load("audio.wav");
    loop();
}

Game::~Game(){
    TTF_Quit();
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

void Game::loop(){
    while(running){
        lastFrame = SDL_GetTicks();
        static int lastTime;
        if(lastFrame >= (lastTime+1000)){
            lastTime = lastFrame;
            frameCount = 0;
        }

        //cout << mouseX << ", " << mouseY << endl;

        render();
        input();
        update();

    }
}

void Game::render(){
    SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
    SDL_Rect rect;
    rect.x = rect.y = 0;
    rect.w = 720;
    rect.h = 480;
    SDL_RenderFillRect(ren, &rect);

    draw(star);
    draw("Learning SDL2 !", 25, 100, 0, 255, 0);

    frameCount++;
    int timerFPS = SDL_GetTicks() - lastFrame;
    if(timerFPS < (1000/60)){
        SDL_Delay((1000/60) - timerFPS);
    }

    SDL_RenderPresent(ren);
}

void Game::draw(Object o){
    SDL_Rect dest = o.getDest();
    SDL_Rect src = o.getSource();
    SDL_RenderCopyEx(ren, o.getTex(), &src, &dest, 0, NULL, SDL_FLIP_NONE);

}

void Game::draw(const char* msg, int x, int y, int r, int g, int b){
    SDL_Surface* surf;
    SDL_Texture* tex;
    SDL_Color color;
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = 255;
    SDL_Rect rect;
    surf = TTF_RenderText_Solid(font, msg, color);
    tex = SDL_CreateTextureFromSurface(ren, surf);
    rect.x = x;
    rect.y = y;
    rect.w = surf->w;
    rect.h = surf->h;
    SDL_FreeSurface(surf);
    SDL_RenderCopy(ren, tex, NULL, &rect);
    SDL_DestroyTexture(tex);

}

void Game::input(){
    SDL_Event e;
    while(SDL_PollEvent(&e)){
        if(e.type == SDL_QUIT){
            running = false;
            cout << "Quiting" << endl;
        }
        if(e.type == SDL_KEYDOWN){
            // W A S D 
            if(e.key.keysym.sym == SDLK_ESCAPE) running = false;
            if(e.key.keysym.sym == SDLK_w) {cout << "w down" << endl;}
            if(e.key.keysym.sym == SDLK_d) {cout << "d down" << endl;}
            if(e.key.keysym.sym == SDLK_a) {cout << "a down" << endl;}
            if(e.key.keysym.sym == SDLK_s) {cout << "s down" << endl;}

            // play audio
            if(e.key.keysym.sym == SDLK_1) {cout << "playing audio" << endl; effect.play();}

        }
        if(e.type == SDL_KEYUP){
            if(e.key.keysym.sym == SDLK_w) {cout << "w up" << endl;} 
            if(e.key.keysym.sym == SDLK_d) {cout << "d up" << endl;}
            if(e.key.keysym.sym == SDLK_a) {cout << "a up" << endl;}
            if(e.key.keysym.sym == SDLK_s) {cout << "s up" << endl;}
        }
        SDL_GetMouseState(&mouseX, &mouseY);
    }
}