/*
  Copyright 2017, Sjors van Gelderen

  TODO:
  - Make singleton
*/

#ifndef WINDOW_H
#define WINDOW_H

#include <memory>
#include <SDL2/SDL.h>
#include "media.h"

#ifdef DEBUG
#include "debug.h"
#endif

class Window
{
public:
static int Init(std::string _title, int _width, int _height);
static int Terminate();
static std::shared_ptr<SDL_Window> GetWindow();

private:
static std::shared_ptr<SDL_Window> window;
};

#endif
