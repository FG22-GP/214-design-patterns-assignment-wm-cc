#pragma once
#include <SDL.h>
#include "../Interfaces/IHealth.h"
#include <stdio.h>
#include <random>

class PlayerCharacter : public IHealth
{
    
public:
    
    PlayerCharacter(int Health);

    SDL_Rect GetPlayerCollider();

    void TakeDamage(int damageTaken) override;
    void GainHealth(int HealthGained) override;

    SDL_Texture* Pikachu;

    int pik_x = 0;
    int pik_y = 0;
    int pik_w = 200;
    int pik_h = 200;

protected:
    // Player Character Variables
    const char* pikachuImagePath{ "img/pikachu.png" };
    bool pikachuMoveRight = false;
};
