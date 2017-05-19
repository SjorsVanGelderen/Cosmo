#include "window.h"

SDL_Window* Window::window;
SDL_Renderer* Window::renderer;
std::vector<Sprite*> Window::sprites;

int Window::Init()
{
  // Set up SDL
  if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      Debug::Log(ERROR, "SDL error: " + std::string(SDL_GetError()));
      return -1;
    }

  // Create a window
  window = SDL_CreateWindow("Cosmo",
			    SDL_WINDOWPOS_UNDEFINED,
			    SDL_WINDOWPOS_UNDEFINED,
			    1280,
			    720,
			    SDL_WINDOW_SHOWN);
  if(window == nullptr)
    {
      Debug::Log(ERROR, "SDL error: " + std::string(SDL_GetError()));
      return -1;
    }

  // Create a renderer
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if(renderer == nullptr)
    {
      Debug::Log(ERROR, "SDL error: " + std::string(SDL_GetError()));
      return -1;
    }

  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

  sprites.push_back(new Sprite("image.png"));
  
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

int Window::Loop()
{
  SDL_RenderClear(renderer);

  // Render all sprites
  /*
  for(const auto &sprite : sprites)
    {
      sprite->Draw(renderer);
    }
  */
  
  SDL_RenderPresent(renderer);

  return 0;
}

SDL_Renderer* Window::GetRenderer()
{
  return renderer;
}
