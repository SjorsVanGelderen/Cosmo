/*
  Copyright 2017, Sjors van Gelderen
*/

#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>
#include <vector>
#include <string>
#include <SDL2/SDL.h>
#include "window.h"
#include "drawing.h"
#include "media.h"

#ifdef DEBUG
#include "debug.h"
#endif

class Application
{
public:
    static int Init(std::string title = "Cosmo", int width = 640, int height = 480);
    static void Terminate();
    static int PollEvents();
    static int Loop();
private:
    static bool exit;
    static SDL_Event event;
    static const Window window;
//static const Media media;
};

#endif
