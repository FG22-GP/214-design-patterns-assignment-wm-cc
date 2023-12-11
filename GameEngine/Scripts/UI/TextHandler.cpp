#include "TextHandler.h"

#include <cstdio>

#include "../Game/GameInstance.h"
#include "../Player/PlayerCharacter.h"


void TextHandler::BeginPlay()
{
    // GameInstance::Instance()->GetPlayerCharacter()->AddObserver(GetObserver());
}

void TextHandler::OnNotify(int i)
{
    printf("Health is : %d", i);
}
