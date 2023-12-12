//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "Window.h"
#include "Scripts/Game/GameInstance.h"
#include "Scripts/Player/PlayerCharacter.h"
#include <random>

void TickGame();
void HandleInput();
PlayerCharacter* GetPlayerCharacter();
//Screen dimension constants
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

// Time
float DeltaTime;
float TimeInSeconds;

//Collision
SDL_Rect GetPlayerCollider();
SDL_Rect GetObjectCollider();
bool CheckCollision(SDL_Rect ObjectA, SDL_Rect ObjectB);

// Input Events
SDL_Event e;
bool quit = false;

// Player Character Variables
const char* pikachuImagePath{ "img/pikachu.png" };
SDL_Texture* Pikachu;
SDL_Rect* pikachuCollider;
bool pikachuMoveRight = false;
int pik_x = 0;
int pik_y = 0;
int pik_w = 200;
int pik_h = 200;

//medkit variables
const char* medKitImagePath{ "img/medkit.png" };
SDL_Texture* medKit;
SDL_Rect* medkitCollider;
int medKit_w = 120;
int medKit_h = 120;
int medKit_X;
int medKit_Y;
float delayBetweenTeleport = 3000;
float teleportationCycle = 0;

// Text Variables
const char* lazyFontPath{ "font/lazy.ttf" };
SDL_Texture* Text;
int textWidth = 32;
int textHeight = 32;

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

	// Access the PlayerCharacter instance
	PlayerCharacter = gameInstance->GetPlayerCharacter();

	//Load image at specified path
	Pikachu = WindowRenderer.LoadTexture(pikachuImagePath);
	if (Pikachu == nullptr) return 0;

	//Create a Medkit
	medKit = WindowRenderer.LoadTexture(medKitImagePath);
	if (medKit == nullptr) return 0;
	

	printf("%d\n", medKit_X);
	printf("%d\n", medKit_Y);

	// load font
	Text = WindowRenderer.LoadFont(lazyFontPath, 64, textWidth, textHeight);
	if (Text == nullptr) return 0;
	
	// while the user doesn't want to quit
	while (quit == false) // This is tick
	{
		TickGame();
		GetPlayerCollider();
		GetObjectCollider();
		CheckCollision(GetPlayerCollider(), GetObjectCollider());
		
		// clear the screen
		WindowRenderer.Clear();
		
		// render Pikachu
		WindowRenderer.RenderTexture(Pikachu, pik_x, pik_y, pik_w, pik_h);


		// render Medkit
		WindowRenderer.RenderTexture(medKit, medKit_X, medKit_Y , medKit_w, medKit_h);

		// render the text
		WindowRenderer.RenderTexture(Text, 1, 1, textWidth, textHeight);

		// Render window
		WindowRenderer.Present();

		SDL_Delay(0); // can be used to wait for a certain amount of ms
	}

	return 0;
}

void TickGame()
{
	Uint32 const MillisecondsElapsedSinceStart = SDL_GetTicks(); // can be used, to see, how much time in ms has passed since app start
	TimeInSeconds = MillisecondsElapsedSinceStart / 1000; // millisecond to second conversion
	//printf("Time Elapsed In Seconds %d\n", static_cast<int>(TimeInSeconds));
	
	// CHECK FOR COLLISION WITH HEALTH PACK, IF TRUE, GIVE PLAYER HEALTH
	if (CheckCollision(GetPlayerCollider(), GetObjectCollider()))
	{
		int rangeX = (SCREEN_WIDTH - 120) - 60 + 1;
		medKit_X = rand() % rangeX + medKit_w / 2;

		int rangeY = (SCREEN_HEIGHT - 120) - 60 + 1;
		medKit_Y = rand() % rangeY + medKit_h / 2;


		PlayerCharacter->GainHealth(5);
	}

		 if (teleportationCycle * delayBetweenTeleport < MillisecondsElapsedSinceStart) {
			 teleportationCycle +=1;
			 //create medkit coordinates
			 int rangeX = (SCREEN_WIDTH -120) -60  + 1;
			 medKit_X = rand() % rangeX + medKit_w / 2;

			 int rangeY = (SCREEN_HEIGHT - 120) -60 + 1;
			 medKit_Y = rand() % rangeY + medKit_h / 2;

			 PlayerCharacter->TakeDamage(1);
		 }
	HandleInput();
	PlayerCharacter->Tick();
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

			// 	// This is an example on how to use input events:
			// case SDL_KEYDOWN: {
			// 	// input example: if left, then make pikachu move left
			// 	if (e.key.keysym.sym == SDLK_LEFT) {
			// 		pikachuMoveRight = false;
			// 	}
			// 	// if right, then make pikachu move right
			// 	if (e.key.keysym.sym == SDLK_RIGHT) {
			// 		pikachuMoveRight = true;
			// 	}
			// } break;
		} 
	}
	
	// This is an example for how to check, whether keys are currently pressed:
	const Uint8* keystate = SDL_GetKeyboardState(NULL);
	if (keystate[SDL_SCANCODE_UP])
	{
		if (pik_y > 1)
			pik_y--;
	}
	if (keystate[SDL_SCANCODE_DOWN])
	{
		if (pik_y < SCREEN_HEIGHT -pik_w)
			pik_y++;
	}

	if (keystate[SDL_SCANCODE_RIGHT])
	{
		if (pik_x < SCREEN_WIDTH -pik_h)
			pik_x++;
	}
	if (keystate[SDL_SCANCODE_LEFT])
	{
		if (pik_x > 1)
			pik_x--;
	}
}

// Establish a rectangle based on the variables that pikachu has (x, y, width, height)
SDL_Rect GetPlayerCollider()
{
	SDL_Rect playerBoundingBox = { pik_x, pik_y, pik_w, pik_h };
	return playerBoundingBox;
}

// Establish a rectangle based on the variables that the medkit has (x, y, width, height)
SDL_Rect GetObjectCollider()
{
	SDL_Rect medKitBoundingBox = { medKit_X, medKit_Y, medKit_w, medKit_h };
	return medKitBoundingBox;
}

// Compare two rects and check if they are overlapping with each other (e.g Medkit & Pikachu/Player)
bool CheckCollision(SDL_Rect ObjectA, SDL_Rect ObjectB)
{
	// Checks if the right edge of ObjectA is to the -left- of the right edge of ObjectB.
	bool xCollision = (ObjectA.x < ObjectB.x + ObjectB.w) && (ObjectA.x + ObjectA.w > ObjectB.x);

	// Checks if the left edge of ObjectA is to the -left- of the left edge of ObjectB.
	bool yCollision = (ObjectA.y < ObjectB.y + ObjectB.h) && (ObjectA.y + ObjectA.h > ObjectB.y);

	if (xCollision && yCollision)
	{
		printf("Picked up health kit!\n");
	}

	return xCollision && yCollision;
}
