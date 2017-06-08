/*
  Copyright 2017, Sjors van Gelderen
*/

#ifndef DRAWING_H
#define DRAWING_H

#include <functional>
#include <memory>
#include <queue>
#include <string>
#include <SDL2/SDL.h>
#include "media.h"

#ifdef DEBUG
#include "debug.h"
#endif

class Drawing
{
public:
    static int Init(std::shared_ptr<SDL_Window> window);
    static void Terminate();
    static void DrawLine(double x0, double y0, double x1, double y1);
    static void DrawRectangle(double x0, double y0, double width, double height);
    //static void DrawCircle(double x, double y, double r);
    //static void DrawText(std::string text, double x, double y, double size);
    static void DrawImage(std::string filename, double x, double y);
    static void DrawAll();
    static std::shared_ptr<SDL_Renderer> GetRenderer();
    
private:
    static std::shared_ptr<SDL_Renderer> renderer;
    static std::queue<std::function<void ()>> toDraw;
};

#endif
