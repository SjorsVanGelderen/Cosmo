/*
  Copyright 2017, Sjors van Gelderen
*/

#include "application.h"

bool Application::exit;
SDL_Event Application::event;
const Window Application::window;
//const Media Application::media;

int Application::Init(std::string title, int width, int height)
{
    // Set up SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
#ifdef DEBUG
	Debug::Log(ERROR, "SDL error: " + std::string(SDL_GetError()));
#endif
      
	return -1;
    }
    
    // Initialize the window
    if(Window::Init(title, width, height) < 0)
    {
	return -1;
    }
    
    // Initialize the drawing system
    if(Drawing::Init(Window::GetWindow()) < 0)
    {
	return -1;
    }

    /*
    // Initialize media subsystem
    if(Media::Init(Drawing::GetRenderer()) < 0)
    {
	return -1;
    }
    */
    
    return 0;
}

void Application::Terminate()
{
    // Terminate subsystems
    Window::Terminate();
    Drawing::Terminate();
    //Media::Terminate();
}

int Application::PollEvents()
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

    if(exit)
    {
	return 1;
    }

    return 0;
}

int Application::Loop()
{   
    while(!exit)
    {
	// Poll for SDL events
	PollEvents();

	// Draw everything
	Drawing::DrawAll();
    }
    
    return 0;
}
