/*
  Copyright 2017, Sjors van Gelderen

  TODO:
  - Use dstrect with position vector
*/

#include "sprite.h"

Sprite::Sprite(std::string filename)
{
  texture = Media::GetImage(filename);
}

Sprite::~Sprite()
{
  texture = nullptr;
}

void Sprite::Draw(SDL_Renderer* _renderer)
{
  if(texture != nullptr)
    {
      SDL_RenderCopy(_renderer, texture, NULL, NULL);
    }
}
