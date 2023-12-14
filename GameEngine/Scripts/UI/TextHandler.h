#pragma once
#include <SDL_render.h>

#include "../Interfaces/IObserver.h"

class Window;

class TextHandler : public IObserver
{
    Window* GameWindow;
    
public:
    TextHandler(Window* window);
    // Text Variables
    const char* lazyFontPath{ "font/lazy.ttf" };
    SDL_Texture* Text;
    int textWidth = 32;
    int textHeight = 32;
    SDL_Texture* Texture;
    

    void BeginPlay();
    void OnHealthChangeNotify(int i) override;
    void Tick();
};
