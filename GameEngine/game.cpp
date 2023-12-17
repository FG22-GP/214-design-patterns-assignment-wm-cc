//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "Window.h"
#include "Scripts/Game/GameInstance.h"
#include "Scripts/Player/PlayerCharacter.h"
#include "Scripts/Physics/CollisionManager.h"
#include <random>
#include "Medkit.h"

void TickGame();
void HandleInput();

//Screen dimension constants
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

// Time
float DeltaTime;
float TimeInSeconds;

// Input Events
SDL_Event e;
bool quit = false;

// Player Image
const char* pikachuImagePath{ "img/Garfield.png" };

// MedKit Image
const char* medKitImagePath{ "img/medkit.png" };

// Singletons/Entities in the world
CollisionManager* collisionManager;
Medkit* medKit;
PlayerCharacter* PlayerCharacter;


int main(int argc, char* args[])
{
	//The window we'll be rendering to
	Window WindowRenderer = Window(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!WindowRenderer.WasSuccessful())
	{
		// quits the game if the initialization of window was unsuccessful
		return 0;
	}

	GameInstance* gameInstance = GameInstance::Instance();
	gameInstance->Initialize(WindowRenderer.GetWindow());

	// Access the PlayerCharacter instance
	PlayerCharacter = gameInstance->GetPlayerCharacter();
	collisionManager = gameInstance->GetCollisionManager();
	medKit = gameInstance->GetMedKit();

	//Load image at specified path
	PlayerCharacter->Pikachu = WindowRenderer.LoadTexture(pikachuImagePath);
	if (PlayerCharacter->Pikachu == nullptr) return 0;

	//Create a Medkit
	medKit->medKitTexture = WindowRenderer.LoadTexture(medKitImagePath);
	if (medKit->medKitTexture == nullptr) return 0;

	// while the user doesn't want to quit
	while (quit == false) // This is tick
	{
		gameInstance->Tick();
		TickGame();

		// clear the screen
		WindowRenderer.Clear();

		// render Pikachu
		WindowRenderer.RenderTexture(PlayerCharacter->Pikachu, PlayerCharacter->pik_x, PlayerCharacter->pik_y, PlayerCharacter->pik_w, PlayerCharacter->pik_h);

		// render Medkit
		WindowRenderer.RenderTexture(medKit->medKitTexture, medKit->medKit_X, medKit->medKit_Y, medKit->medKit_w, medKit->medKit_h);

		SDL_Delay(0); // can be used to wait for a certain amount of ms
	}

	return 0;
}

void TickGame()
{
	Uint32 const MillisecondsElapsedSinceStart = SDL_GetTicks(); // can be used, to see, how much time in ms has passed since app start
	TimeInSeconds = MillisecondsElapsedSinceStart / 1000; // millisecond to second conversion

	if (PlayerCharacter->GetCurrentHealth() == 0) {
		quit = true;
	}

	if (collisionManager->CheckCollision(PlayerCharacter->GetPlayerCollider(), medKit->GetObjectCollider()))
	{
		int rangeX = (SCREEN_WIDTH - 120) - 60 + 1;
		medKit->medKit_X = rand() % rangeX + medKit->medKit_w / 2;

		int rangeY = (SCREEN_HEIGHT - 120) - 60 + 1;
		medKit->medKit_Y = rand() % rangeY + medKit->medKit_h / 2;

		PlayerCharacter->GainHealth(1);
	}

	if (medKit->teleportationCycle * medKit->delayBetweenTeleport < MillisecondsElapsedSinceStart)
	{
		medKit->teleportationCycle += 1;
		//create medkit coordinates
		int rangeX = (SCREEN_WIDTH - 120) - 60 + 1;
		medKit->medKit_X = rand() % rangeX + medKit->medKit_w / 2;

		int rangeY = (SCREEN_HEIGHT - 120) - 60 + 1;
		medKit->medKit_Y = rand() % rangeY + medKit->medKit_h / 2;

		PlayerCharacter->TakeDamage(1);
	}

	HandleInput();
}

void HandleInput() // Move this to playercontroller
{
	// loop through all pending events from Windows (OS)
	while (SDL_PollEvent(&e))
	{
		// check, if it's an event we want to react to:
		switch (e.type) {
		case SDL_QUIT: {
			quit = true;
		} break;
		}
	}

	// This is an example for how to check, whether keys are currently pressed:
	const Uint8* keystate = SDL_GetKeyboardState(NULL);
	if (keystate[SDL_SCANCODE_UP])
	{
		if (PlayerCharacter->pik_y > 1)
			PlayerCharacter->pik_y--;
	}
	if (keystate[SDL_SCANCODE_DOWN])
	{
		if (PlayerCharacter->pik_y < SCREEN_HEIGHT - PlayerCharacter->pik_w)
			PlayerCharacter->pik_y++;
	}

	if (keystate[SDL_SCANCODE_RIGHT])
	{
		if (PlayerCharacter->pik_x < SCREEN_WIDTH - PlayerCharacter->pik_h)
			PlayerCharacter->pik_x++;
	}
	if (keystate[SDL_SCANCODE_LEFT])
	{
		if (PlayerCharacter->pik_x > 1)
			PlayerCharacter->pik_x--;
	}
}
