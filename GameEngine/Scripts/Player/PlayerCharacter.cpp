#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter(int Health)
{
    CurrentHealth = Health;
}

 void PlayerCharacter::TakeDamage(int damageTaken)
 {
     IHealth::TakeDamage(damageTaken);
 }

void PlayerCharacter::GainHealth(int HealthGained)
{
    IHealth::GainHealth(HealthGained);
}
