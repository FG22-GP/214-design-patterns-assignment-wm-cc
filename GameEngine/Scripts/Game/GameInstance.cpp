#include "GameInstance.h"

#include "../Player/PlayerCharacter.h"
#include "../UI/TextHandler.h"

GameInstance::GameInstance()
{
    // playerCharacter = new PlayerCharacter(10);
}

GameInstance::GameInstance(Window* window)
{
    GameWindow = window;
    playerCharacter = new PlayerCharacter(10);
    HealthText = new TextHandler(GameWindow);
    playerCharacter->AddObserver(HealthText);
}

GameInstance::~GameInstance()
{
}

bool GameInstance::Initialize(Window* window)
{
    printf("initalized");
    
    GameWindow = window;
    playerCharacter = new PlayerCharacter(10);
    HealthText = new TextHandler(GameWindow);
    playerCharacter->AddObserver(HealthText);
    
    
    if (playerCharacter == nullptr)
    {
        printf("player character is null");
        return false;
    }
    return true;

    
}

void GameInstance::Tick()
{
    if(HealthText != nullptr)
    {
        HealthText->Tick();
    }
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


