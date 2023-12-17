#pragma once
#include <SDL.h>
#include <stdio.h>
#include <random>

class Medkit
{

public:
	Medkit();
	SDL_Rect GetObjectCollider();
	SDL_Texture* medKitTexture;
	SDL_Rect* medkitCollider;
	int medKit_w = 120;
	int medKit_h = 120;
	int medKit_X = 0;
	int medKit_Y = 0;
	float delayBetweenTeleport = 3000;
	float teleportationCycle = 0;
};

