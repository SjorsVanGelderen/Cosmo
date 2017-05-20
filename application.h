/*
  Copyright 2017, Sjors van Gelderen

  TODO:
  - Reconsider responsibility
  - Make singleton
*/

#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>
#include <SDL2/SDL.h>
#include "debug.h"
#include "window.h"
#include "media.h"
#include "sprite.h"

class Application
{
public:
    static int Init(std::string _title = "Cosmo", int _width = 640, int _height = 480);
    static void Terminate();
    static void PollEvents();
    static int Loop();
    static SDL_Renderer* GetRenderer();
    
private:
    static bool exit;
    static SDL_Event event;
    static const Window window;
    static const Media media;
    static SDL_Renderer* renderer;
    static std::vector<Sprite*> sprites;
};

#endif
