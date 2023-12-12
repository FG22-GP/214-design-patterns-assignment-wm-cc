#include "PlayerCharacter.h"
#include <cstdio> // used for printf

PlayerCharacter::PlayerCharacter(int Health)
{
    CurrentHealth = Health;
}

 void PlayerCharacter::TakeDamage(int damageTaken)
 {
     IHealth::TakeDamage(damageTaken);
     printf("AIEEEEEEE\n %d", CurrentHealth);

 }

 int PlayerCharacter::GetCurrentHealth() {
     return CurrentHealth;
 }


void PlayerCharacter::BeginPlay()
{
}

void PlayerCharacter::Tick()
{
     //printf("Tick");
}

void PlayerCharacter::RenderPlayer()
{
}
