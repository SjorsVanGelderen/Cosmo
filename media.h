/*
  Copyright 2017, Sjors van Gelderen

  TODO:
  - Make singleton
*/

#ifndef MEDIA_H
#define MEDIA_H

#include <memory>
#include <vector>
#include <map>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "drawing.h"

#ifdef DEBUG
#include "debug.h"
#endif

class Media
{
public:
    static int Init();
    static void Terminate();
    static std::shared_ptr<SDL_Texture> GetImage(std::string filename);

private:
    static std::shared_ptr<SDL_Texture> LoadImage(std::string filename);
  
    static std::map<std::string, std::shared_ptr<SDL_Texture>> textures;
};

#endif
