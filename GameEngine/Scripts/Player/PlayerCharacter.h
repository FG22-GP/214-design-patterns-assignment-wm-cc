#pragma once
#include <SDL_render.h>

#include "../Interfaces/IHealth.h"

class PlayerCharacter : public IHealth
{
    
public:
    
    PlayerCharacter(int Health);

    void TakeDamage(int damageTaken) override;
    void BeginPlay();
    void Tick();
    void RenderPlayer();

protected:
    // Player Character Variables
    const char* pikachuImagePath{ "img/pikachu.png" };
    SDL_Texture* Pikachu;
    bool pikachuMoveRight = false;
    int pik_x = 0;
    int pik_y = 0;
    int pik_w = 200;
    int pik_h = 200;
};
