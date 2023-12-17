#pragma once
class CollisionManager {
public:
    CollisionManager();
    bool CheckCollision(const SDL_Rect& objectA, const SDL_Rect& objectB);
};

