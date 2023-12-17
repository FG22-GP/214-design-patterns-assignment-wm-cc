#include "Medkit.h"

Medkit::Medkit()
{

}

// Establish a rectangle based on the variables that the medkit has (x, y, width, height)
SDL_Rect Medkit::GetObjectCollider()
{
	SDL_Rect medKitBoundingBox = { medKit_X, medKit_Y, medKit_w, medKit_h };
	return medKitBoundingBox;
}
