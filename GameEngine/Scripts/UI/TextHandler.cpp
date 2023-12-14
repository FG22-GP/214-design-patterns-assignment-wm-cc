#include "TextHandler.h"

#include <array>
#include <charconv>
#include <cstdio>
#include <sstream>
#include <string>

#include "../../Window.h"
#include "../Game/GameInstance.h"
#include "../Player/PlayerCharacter.h"


TextHandler::TextHandler(Window* window)
{
    GameWindow = window;
    BeginPlay();
}

void TextHandler::BeginPlay()
{
    GameInstance::Instance()->GetPlayerCharacter()->AddObserver(this);
}

void TextHandler::OnHealthChangeNotify(int i)
{
    std::string line1 = "Health: ";
    std::string totalLine = line1 + std::to_string(i);
    
    Texture = GameWindow->LoadFont(lazyFontPath, 64, textWidth, textHeight, totalLine.c_str());
}

void TextHandler::Tick()
{
    // render the text
    GameWindow->RenderTexture(Texture, 1, 1, textWidth, textHeight);

    // Render window
    GameWindow->Present();
}
