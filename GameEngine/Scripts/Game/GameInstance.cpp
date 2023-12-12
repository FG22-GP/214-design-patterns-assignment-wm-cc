#include "GameInstance.h"

#include "../Player/PlayerCharacter.h"

GameInstance::GameInstance()
{
    playerCharacter = new PlayerCharacter(10);
}

GameInstance::~GameInstance()
{
}

bool GameInstance::Initialize()
{
    printf("initalized");
    
    if (playerCharacter == nullptr)
    {
        printf("player character is null");
        return false;
    }
    return true;
}

void GameInstance::Tick()
{
    
}

PlayerCharacter* GameInstance::GetPlayerCharacter() const
{
    return playerCharacter;
}

GameInstance* GameInstance::Instance()
{
    if (instance == nullptr)
    {
        instance = new GameInstance();
        return instance;
    }
    return instance;
}

// GameInstance* GameInstance::instance = 0 ;


