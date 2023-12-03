#include "Window.h" 
#include <cstdio> // for using printf
#include <SDL_ttf.h> // font


Window::Window(int width, int height)
{
    success = true;
    // initialize SDL_Image for image loading
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        success = false;
    }

    // initialize SDL_ttf for font loading
    if (TTF_Init() == -1)
    {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        success = false;
    }

    //Start up SDL and create window
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO))
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }

    // Create Window and Renderer
    SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, &window, &renderer);
    if (!window)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");  // make the scaled rendering look smoother.
    SDL_RenderSetLogicalSize(renderer, 1024, 768);
}

void Window::Clear()
{
    // clear the screen
    SDL_SetRenderDrawColor(renderer, 120, 60, 255, 255);
    SDL_RenderClear(renderer);
}

void Window::RenderTexture(SDL_Texture* Texture, int x, int y, int w, int h)
{
    // Create Rectangle
    SDL_Rect targetRectangle{ x, y, w, h };
    
    SDL_RenderCopy(renderer, Texture, NULL, &targetRectangle);
}

void Window::Present()
{
    SDL_RenderPresent(renderer);
}

SDL_Texture* Window::LoadTexture(const char* TextureFilePath)
{
    SDL_Texture* texture = NULL; // The final optimized image
    
    SDL_Surface* loadedSurface = IMG_Load(TextureFilePath);
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", TextureFilePath, IMG_GetError());
        return nullptr;
    }
    
    //Convert surface to screen format
    texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (texture == NULL)
    {
        printf("Unable to create texture from %s! SDL Error: %s\n", TextureFilePath, SDL_GetError());
        return nullptr;
    }

    //Get rid of old loaded surface
    SDL_FreeSurface(loadedSurface);
    return texture;
}

SDL_Texture* Window::LoadFont(const char* FontPath, int FontSize, int& TextWidth, int& TextHeight)
{
    auto font = TTF_OpenFont(FontPath, FontSize);
    
    if (font == NULL)
    {
        printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
        return nullptr;
    }

    // create text from font
    SDL_Color const textColor = { 0xff, 0xff, 0xff };
    //Render text surface
    SDL_Texture* textTexture; // The final optimized image

    // render the text into an unoptimized CPU surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, "FPS: ", textColor);
    if (textSurface == NULL)
    {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
        return nullptr;
    }
    
    // Create texture GPU-stored texture from surface pixels
    textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (textTexture == NULL)
    {
        printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        return nullptr;
    }
    
    // Get image dimensions
    TextWidth = textSurface->w;
    TextHeight = textSurface->h;
    //Get rid of old loaded surface
    SDL_FreeSurface(textSurface);
    return textTexture;
}
