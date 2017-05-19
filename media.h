#ifndef MEDIA_H
#define MEDIA_H

#include <map>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "debug.h"

class Media
{
 public:
  static void Init(SDL_Renderer* _renderer);
  static void Terminate();
  static SDL_Texture* GetImage(std::string _filename);

 private:
  static SDL_Texture* LoadImage(std::string _filename);
  
  static std::map<std::string, SDL_Texture*> textures;
  static SDL_Renderer* renderer;
};

#endif
