/*
  Copyright 2017, Sjors van Gelderen
*/

#include "application.h"

bool Application::exit;
SDL_Event Application::event;
const Window Application::window;
const Media Application::media;
SDL_Renderer* Application::renderer;
std::vector<Sprite*> Application::sprites;

int Application::Init(std::string _title, int _width, int _height)
{
    // Set up SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
	Debug::Log(ERROR, "SDL error: " + std::string(SDL_GetError()));
	return -1;
    }

    // Initialize the window
    if(Window::Init(_title, _width, _height) < 0)
    {
	return -1;
    }

    // Create a renderer
    renderer = SDL_CreateRenderer(Window::GetWindow(), -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr)
    {
	Debug::Log(ERROR, "SDL error: " + std::string(SDL_GetError()));
	return -1;
    }

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    // Initialize media subsystem
    Media::Init(renderer);
    
    // Load an image to draw
    sprites.push_back(new Sprite("image.png"));
    
    return 0;
}

void Application::Terminate()
{
    // Terminate subsystems
    Window::Terminate();
    Media::Terminate();
}

void Application::PollEvents()
{
    // Flush the SDL event queue
    while(SDL_PollEvent(&event))
    {
	switch(event.type)
	{
	case SDL_QUIT:
	    // Set the quit flag
	    exit = true;
	    break;

	default:
	    // Unhandled events are ignored
	    break;
	}
    }
}

int Application::Loop()
{   
    while(!exit)
    {
	// Poll for SDL events
	PollEvents();

	// Clear the screen
	SDL_RenderClear(renderer);
	
	// Render all sprites
	for(const auto &sprite : sprites)
	{
	    sprite->Draw(renderer);
	}

	// Flip the screen
	SDL_RenderPresent(renderer);
    }
    
    return 0;
}

SDL_Renderer* Application::GetRenderer()
{
    return renderer;
}
