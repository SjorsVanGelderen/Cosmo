#include "media.h"

std::map<std::string, SDL_Texture*> Media::textures;
SDL_Renderer* Media::renderer = nullptr;

void Media::Init(SDL_Renderer* _renderer)
{
  renderer = _renderer;

  if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
      Debug::Log(ERROR,
		 "Failed to initialize IMG. IMG error: "
		 + std::string(IMG_GetError()));
    }
}

SDL_Texture* Media::LoadImage(std::string _filename)
{
  // Load an image into a surface
  SDL_Surface* surface = IMG_Load(_filename.c_str());
  if(surface == nullptr)
    {
      Debug::Log(ERROR,
		 "Failed to load image "
		 + _filename
		 + ". SDL error: "
		 + std::string(SDL_GetError()));
      return nullptr;
    }

  // Generate a texture from the surface
  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
  if(texture == nullptr)
    {
      Debug::Log(ERROR,
		 "Failed to create texture "
		 + _filename
		 + ". SDL error: "
		 + std::string(SDL_GetError()));
      return nullptr;
    }

  // Free the surface
  SDL_FreeSurface(surface);

  // Store the texture in the map
  textures.insert(std::pair<std::string, SDL_Texture*>(_filename, texture));

  return texture;
}

SDL_Texture* Media::GetImage(std::string _filename)
{
  // Return surface from map
  for(const auto &entry : textures)
    {
      if(entry.first == _filename)
	{
	  return entry.second;
	}
    }

  // Load if it doesn't exist
  return LoadImage(_filename);
}

void Media::Terminate()
{
  // Destroy all textures and clear the map
  for(const auto &entry : textures)
    {
      SDL_DestroyTexture(entry.second);
    }

  textures.clear();
}
