/*
  Copyright 2017, Sjors van Gelderen
*/

#include "media.h"

std::map<std::string, std::shared_ptr<SDL_Texture>> Media::textures;

int Media::Init()
{
    /*
    if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
#ifdef DEBUG	
	Debug::Log(ERROR,
		   "Failed to initialize IMG. IMG error: "
		   + std::string(IMG_GetError()));
#endif

	return -1;
    }
    */

    return 0;
}

std::shared_ptr<SDL_Texture> Media::LoadImage(std::string _filename)
{
    /*
    // Load an image into a surface
    std::shared_ptr<SDL_Surface> surface = std::make_shared(IMG_Load(_filename.c_str()));
    if(!surface)
    {
#ifdef DEBUG
	Debug::Log(ERROR,
		   "Failed to load image "
		   + _filename
		   + ". SDL error: "
		   + std::string(SDL_GetError()));
#endif
	
	return nullptr;
    }

    // Generate a texture from the surface
    std::shared_ptr<SDL_Texture> texture = SDL_CreateTextureFromSurface(renderer, surface);
    if(texture == nullptr)
    {
#ifdef DEBUG
	Debug::Log(ERROR,
		   "Failed to create texture "
		   + _filename
		   + ". SDL error: "
		   + std::string(SDL_GetError()));
#endif
	
	return nullptr;
    }

    // Free the surface
    SDL_FreeSurface(surface);

    // Store the texture in the map
    textures.insert(std::pair<std::string, SDL_Texture*>(_filename, texture));

    return texture;
    */

    return nullptr;
}

std::shared_ptr<SDL_Texture> Media::GetImage(std::string _filename)
{
    /*
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
    */

    return nullptr;
}

void Media::Terminate()
{
    /*
    // Destroy all textures and clear the map
    for(const auto &entry : textures)
    {
	SDL_DestroyTexture(entry.second);
    }

    textures.clear();
    */
}
