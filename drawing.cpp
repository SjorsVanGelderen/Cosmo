/*
  Copyright 2017, Sjors van Gelderen
*/

#include "drawing.h"

std::shared_ptr<SDL_Renderer> Drawing::renderer;
std::stack<std::function<void ()>> Drawing::toDraw;

int Drawing::Init(std::shared_ptr<SDL_Window> window)
{
    // Create a renderer
    renderer.reset(
	SDL_CreateRenderer(
	    window.get(),
	    -1,
	    SDL_RENDERER_ACCELERATED
	    ),
	SDL_DestroyRenderer
	);
    
    if(!renderer)
    {
#ifdef DEBUG
	Debug::Log(ERROR, "SDL error: " + std::string(SDL_GetError()));
#endif
	
	return -1;
    }
    
    return 0;
}

void Drawing::Terminate()
{
    // Clear the drawing stack
    while(!toDraw.empty())
    {
	toDraw.pop();
    }
}

void Drawing::DrawLine(double x0, double y0, double x1, double y1)
{
    toDraw.push(
	[=] () {
	    SDL_SetRenderDrawColor(renderer.get(), 0xFF, 0, 0, 0xFF);
	    SDL_RenderDrawLine(renderer.get(), x0, y0, x1, y1);
	});
}

void Drawing::DrawRectangle(double x, double y, double width, double height)
{
    toDraw.push(
	[=] () {
	    SDL_Rect rect;
	    rect.x = x;
	    rect.y = y;
	    rect.w = width;
	    rect.y = height;
	    
	    SDL_SetRenderDrawColor(renderer.get(), 0xFF, 0xFF, 0xFF, 0xFF);
	    SDL_RenderDrawRect(renderer.get(), &rect);
	});
}

/*
void Drawing::DrawCircle(double x, double y, double r)
{
    // TODO
}

void Drawing::DrawText(std::string text, double x, double y, double size)
{
    // TODO
}

void Drawing::DrawImage(std::string filename, double x, double y)
{
    // TODO
}
*/

void Drawing::DrawAll()
{
    // Clear the screen
    SDL_SetRenderDrawColor(renderer.get(), 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(renderer.get());

    // Go through the stack of drawing closures
    while(!toDraw.empty())
    {
	// Run the drawing closure
	toDraw.top()();
	toDraw.pop();
    }
    
    // Flip the screen
    SDL_RenderPresent(renderer.get());
}

std::shared_ptr<SDL_Renderer> Drawing::GetRenderer()
{
    return renderer;
}
