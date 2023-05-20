#include <SDL2/SDL.h>
#include <iostream>

#define WIDTH 1280
#define HEIGHT 720

bool running;
bool fullscreen;

SDL_Renderer* renderer;
SDL_Window* window;

int frameCount;
int timerFPS;
int lastFrame;
int fps;

void update(){
    if(fullscreen) SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    if(!fullscreen) SDL_SetWindowFullscreen(window, 0);
}
void input(){
    SDL_Event e;
    while(SDL_PollEvent(&e)){
        if(e.type == SDL_QUIT) running = false;
    }

    const Uint8 *keysate = SDL_GetKeyboardState(NULL);
    if (keysate[SDL_SCANCODE_ESCAPE]) running = false;
    if (keysate[SDL_SCANCODE_F11]) fullscreen = !fullscreen;
}
void draw(){
    SDL_SetRenderDrawColor(renderer, 40, 43, 200, 255);
    SDL_Rect rect;
    rect.x = rect.y = 0;
    rect.w = WIDTH;
    rect.h = HEIGHT;
    SDL_RenderFillRect(renderer, &rect);

    frameCount ++;
    int timerFPS = SDL_GetTicks() - lastFrame;
    if (timerFPS< (1000/60)){
        SDL_Delay((1000/60)-timerFPS);
    }

    SDL_RenderPresent(renderer);
}

int main(){
    running = 1;
    fullscreen = 0;

    static int lastTime = 0;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) std::cout << "Failed at SDL_Init()" << std::endl;
    // create window and renderer by passing width and height and window flag = 0 that we will use to fullscreen mode. and passing pointer to window and renderer
    if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) < 0) std::cout << "Failed at CreateWindowAndRenderer()" << std::endl;
    SDL_SetWindowTitle(window, "SDL2 my window");
    SDL_ShowCursor(1); // one means show the cursor in the window
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2"); // to scale up quality of pixels ?!


    while(running){
        lastFrame = SDL_GetTicks();
        if (lastFrame >= (lastFrame+1000)){
            lastTime = lastFrame;
            fps = frameCount;
            frameCount = 0;

        }
        std::cout << fps << std::endl;

        update();
        input();
        draw();
    }

    // free everything
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}