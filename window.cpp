/*
  Copyright 2017, Sjors van Gelderen
*/

#include "window.h"

SDL_Window* Window::window;

int Window::Init(std::string _title, int _width, int _height)
{
    // Create a window
    window = SDL_CreateWindow(_title.c_str(),
			      SDL_WINDOWPOS_UNDEFINED,
			      SDL_WINDOWPOS_UNDEFINED,
			      _width,
			      _height,
			      SDL_WINDOW_SHOWN);
    if(window == nullptr)
    {
	Debug::Log(ERROR, "SDL error: " + std::string(SDL_GetError()));
	return -1;
    }
  
    return 0;
}

int Window::Terminate()
{
    // Destroy the window
    SDL_DestroyWindow(window);
    window = nullptr;

    // Quit SDL
    SDL_Quit();

    return 0;
}

SDL_Window* Window::GetWindow()
{
    return window;
}
