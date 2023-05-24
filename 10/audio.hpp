#ifndef AUDIO_H
#define AUDIO_H

#include <SDL2/SDL.h>

class Audio{
    public:
        Audio() {};
        ~Audio();
        void load(const char* fileName);
        void play();
    private:
        SDL_AudioSpec wavSpec;
        Uint32 wavLenght;
        Uint8 *wavBuffer;
        SDL_AudioDeviceID deviceId;

};

#endif