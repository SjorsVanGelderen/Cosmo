/*
  Copyright 2017, Sjors van Gelderen
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
    SDL_RenderCopy(_renderer, texture, NULL, NULL);
}
