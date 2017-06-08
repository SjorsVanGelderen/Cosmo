/*
  Copyright 2017, Sjors van Gelderen
*/

#include "media.h"

std::map<std::string, std::shared_ptr<SDL_Texture>> Media::textures;

int Media::Init()
{
    if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
#ifdef DEBUG	
	Debug::Log(ERROR,
		   "Failed to initialize IMG. IMG error: "
		   + std::string(IMG_GetError()));
#endif

	return -1;
    }

    return 0;
}

std::shared_ptr<SDL_Texture> Media::LoadImage(std::string filename)
{
    // Load an image into a surface
    std::shared_ptr<SDL_Surface> surface;
    surface.reset(
	IMG_Load(filename.c_str()),
	SDL_FreeSurface
	);
    
    if(!surface)
    {
#ifdef DEBUG
	Debug::Log(ERROR,
		   "Failed to load image "
		   + filename
		   + ". SDL error: "
		   + std::string(SDL_GetError()));
#endif
	
	return nullptr;
    }

    // Generate a texture from the surface
    std::shared_ptr<SDL_Texture> texture;
    texture.reset(
	SDL_CreateTextureFromSurface(Drawing::GetRenderer().get(), surface.get()),
	SDL_DestroyTexture
	);
    
    if(!texture)
    {
#ifdef DEBUG
	Debug::Log(ERROR,
		   "Failed to create texture "
		   + filename
		   + ". SDL error: "
		   + std::string(SDL_GetError()));
#endif
	
	return nullptr;
    }

    // Free the surface
    //SDL_FreeSurface(surface.get());

    // Store the texture in the map
    textures.insert(std::pair<std::string, std::shared_ptr<SDL_Texture>>(filename, texture));
    
    return texture;
}

std::shared_ptr<SDL_Texture> Media::GetImage(std::string filename)
{
    // Return surface from map
    for(const auto &entry : textures)
    {
	if(entry.first == filename)
	{
	    return entry.second;
	}
    }

    // Load if it doesn't exist
    return LoadImage(filename);
}

void Media::Terminate()
{
    // Destroy all textures and clear the map
    for(const auto &entry : textures)
    {
	SDL_DestroyTexture(entry.second.get());
    }

    textures.clear();
}
