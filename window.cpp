/*
  Copyright 2017, Sjors van Gelderen
*/

#include "window.h"

std::shared_ptr<SDL_Window> Window::window;

int Window::Init(std::string title, int width, int height)
{
    // Create a window
    window.reset(
	SDL_CreateWindow(
	    title.c_str(),
	    SDL_WINDOWPOS_UNDEFINED,
	    SDL_WINDOWPOS_UNDEFINED,
	    width,
	    height,
	    SDL_WINDOW_SHOWN
	    ),
	SDL_DestroyWindow
	);
    
    if(!window)
    {
#ifdef DEBUG
	Debug::Log(ERROR, "SDL error: " + std::string(SDL_GetError()));
#endif
	
	return -1;
    }
  
    return 0;
}

int Window::Terminate()
{
    // Quit SDL
    SDL_Quit();

    return 0;
}

std::shared_ptr<SDL_Window> Window::GetWindow()
{
    return window;
}
