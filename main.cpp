/*
  Copyright 2017, Sjors van Gelderen
*/

#include "window.h"

int main()
{
  // Set up the application
  Window::Init();
  Media::Init(Window::GetRenderer());
  Sound::Init();

  // Perform the main application loop
  Window::Loop();

  // Terminate the application
  Sound::Terminate();
  Window::Terminate();
  
  return 0;
}
