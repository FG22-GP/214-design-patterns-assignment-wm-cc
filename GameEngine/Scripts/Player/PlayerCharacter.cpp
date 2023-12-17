#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter(int Health)
{
    CurrentHealth = Health;
}

SDL_Rect PlayerCharacter::GetPlayerCollider()
{
    SDL_Rect playerBoundingBox = { pik_x, pik_y, pik_w, pik_h };
    return playerBoundingBox;
}

 void PlayerCharacter::TakeDamage(int damageTaken)
 {
     IHealth::TakeDamage(damageTaken);
 }

void PlayerCharacter::GainHealth(int HealthGained)
{
    IHealth::GainHealth(HealthGained);
}
