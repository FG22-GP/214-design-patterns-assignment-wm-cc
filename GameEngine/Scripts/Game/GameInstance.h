#pragma once

class PlayerCharacter;

class GameInstance
{
protected:
    
    PlayerCharacter* playerCharacter;
    GameInstance();
    ~GameInstance();
    

public:
    bool Initialize();
    void Tick();
	PlayerCharacter* GetPlayerCharacter() const;

    inline static GameInstance* instance = nullptr;
    static GameInstance* Instance();
};