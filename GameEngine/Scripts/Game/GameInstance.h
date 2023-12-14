#pragma once
// #include "../../Window.h"

class PlayerCharacter;
class TextHandler;
class Window;

class GameInstance
{
protected:
    
    PlayerCharacter* playerCharacter;
    GameInstance();
    ~GameInstance();
    explicit GameInstance(Window* window);
    
    TextHandler* HealthText;

public:
    bool Initialize(Window* window);
    void Tick();
	PlayerCharacter* GetPlayerCharacter() const;
    Window* GameWindow;

    inline static GameInstance* instance = nullptr;
    static GameInstance* Instance();
};