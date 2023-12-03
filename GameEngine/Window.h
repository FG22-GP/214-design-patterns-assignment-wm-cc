#pragma once
// #include "Image.h"
#include <SDL_image.h>

class IImageLoader;

class Window
{
	/////// UNUSED ///////
	//The surface contained by the window
	// SDL_Surface* screenSurface{};
	// dependency to the ImageLoader
	// IImageLoader* imageLoader;
	/////// UNUSED ///////
	
	//The window we'll be rendering to
	SDL_Window* window{};
	//Whether Window Startup was successful
	bool success;
	SDL_Renderer* renderer;
public:
	Window(int width, int height);
	bool WasSuccessful() { return success; }
	void Clear();
	void Present();
	SDL_Texture* LoadTexture(const char* TextureFilePath);
	SDL_Texture* LoadFont(const char* FontPath, int FontSize, int& TextWidth, int& TextHeight);
	void RenderTexture(SDL_Texture* Texture, int x, int y, int w, int h);

	
	/////// UNUSED ///////
	// void render(Image* image);
	// std::unique_ptr<Image> loadImage(const char* path);
	/////// UNUSED ///////
};

