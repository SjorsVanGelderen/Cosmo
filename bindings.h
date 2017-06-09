/*
  Copyright 2017, Sjors van Gelderen
*/

#ifndef BINDINGS_H
#define BINDINGS_H

#include <string.h>
#include "application.h"
#include "drawing.h"

extern "C"
{
    int __cdecl Init(char* caption, int width, int height)
    {
	return Application::Init(std::string(caption), width, height);
    }

    void __cdecl Terminate()
    {
	Application::Terminate();
    }
    
    void __cdecl DrawLine(double x0, double y0, double x1, double y1)
    {
	Drawing::DrawLine(x0, y0, x1, y1);
    }

    void __cdecl DrawRectangle(double x, double y, double w, double h)
    {
	Drawing::DrawRectangle(x, y, w, h);
    }
  
    void __cdecl DrawCircle(double x, double y, double r)
    {
	
    }
  
    void __cdecl DrawText(char* text, double x, double y, double size)
    {
      
    }
  
    void __cdecl DrawImage(char* filename, double x, double y)
    {
	Drawing::DrawImage(std::string(filename), x, y);
    }
    
    int __cdecl Update()
    {
	Drawing::DrawAll();
	return Application::PollEvents();
    }
}

#endif
