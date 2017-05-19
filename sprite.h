#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <SDL2/SDL.h>
#include "debug.h"
#include "media.h"

class Sprite
{
 public:
  Sprite(std::string filename);
  ~Sprite();
  void Draw(SDL_Renderer* renderer);
  
 private:
  SDL_Texture* texture;
};

#endif
