#pragma once
// #include "../../Window.h"

class PlayerCharacter;
class CollisionManager;
class TextHandler;
class Medkit;
class Window;

class GameInstance
{
protected:
    
    PlayerCharacter* playerCharacter;
    CollisionManager* collisionManager;
    Medkit* medKit;
    GameInstance();
    ~GameInstance();
    explicit GameInstance(Window* window);
    
    TextHandler* HealthText;

public:
    bool Initialize(Window* window);
    void Tick();
	PlayerCharacter* GetPlayerCharacter() const;
    CollisionManager* GetCollisionManager() const;
    Medkit* GetMedKit() const;
    Window* GameWindow;

    inline static GameInstance* instance = nullptr;
    static GameInstance* Instance();
};