/*
  Copyright 2017, Sjors van Gelderen
*/

#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <SDL2/SDL.h>
#include "debug.h"
#include "media.h"
#include "math.h"

class Sprite
{
 public:
  Sprite(std::string filename);
  ~Sprite();
  void Draw(SDL_Renderer* renderer);
  
 private:
  SDL_Texture* texture;
  Vector2 position;
};

#endif
