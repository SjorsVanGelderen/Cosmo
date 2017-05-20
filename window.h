/*
  Copyright 2017, Sjors van Gelderen

  TODO:
  - Make singleton
*/

#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include "debug.h"
#include "media.h"

class Window
{
public:
    static int Init(std::string _title, int _width, int _height);
    static int Terminate();
    static SDL_Window* GetWindow();

private:
    static SDL_Window* window;
};

#endif
