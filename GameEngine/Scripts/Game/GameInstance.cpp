#include "GameInstance.h"

#include "../Player/PlayerCharacter.h"
#include "../Physics/CollisionManager.h"
#include "../../Medkit.h"
#include "../UI/TextHandler.h"

GameInstance::GameInstance()
{
    
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
    GameWindow = window;
    playerCharacter = new PlayerCharacter(10);
    HealthText = new TextHandler(GameWindow);
    playerCharacter->AddObserver(HealthText);
    medKit = new Medkit();
    
    if (playerCharacter == nullptr)
    {
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

CollisionManager* GameInstance::GetCollisionManager() const
{
    return collisionManager;
}

Medkit* GameInstance::GetMedKit() const 
{
    return medKit;
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


