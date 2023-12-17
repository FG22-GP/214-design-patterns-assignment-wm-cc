#include <SDL.h>
#include <stdio.h>
#include "CollisionManager.h"
#include <random>

CollisionManager::CollisionManager()
{

}

bool CollisionManager::CheckCollision(const SDL_Rect& objectA, const SDL_Rect& objectB)
{
    bool xCollision = (objectA.x < objectB.x + objectB.w) && (objectA.x + objectA.w > objectB.x);
    bool yCollision = (objectA.y < objectB.y + objectB.h) && (objectA.y + objectA.h > objectB.y);

    if (xCollision && yCollision)
    {

    }

    return xCollision && yCollision;
}