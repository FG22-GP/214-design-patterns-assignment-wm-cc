#pragma once
#include <SDL_render.h>

#include "../Interfaces/IObserver.h"

class TextHandler : public IObserver
{
public:
    // Text Variables
    const char* lazyFontPath{ "font/lazy.ttf" };
    SDL_Texture* Text;
    int textWidth = 32;
    int textHeight = 32;

    void BeginPlay();
    void OnNotify(int i) override;
};
