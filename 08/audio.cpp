#include "audio.hpp"

Audio::~Audio(){
    SDL_CloseAudioDevice(deviceId);
    SDL_FreeWAV(wavBuffer);
}

void Audio::load(const char* fileName){
    SDL_LoadWAV(fileName, &wavSpec, &wavBuffer, &wavLenght);
    deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
}

void Audio::play(){
    SDL_QueueAudio(deviceId, wavBuffer, wavLenght);
    SDL_PauseAudioDevice(deviceId, 0);
}