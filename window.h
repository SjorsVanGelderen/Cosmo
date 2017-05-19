#ifndef WINDOW_H
#define WINDOW_H

#include <vector>
#include <SDL2/SDL.h>
#include "debug.h"
#include "media.h"
#include "sprite.h"

class Window
{
 public:
  static int Init();
  static int Terminate();
  static int Loop();
  static SDL_Renderer* GetRenderer();

 private:
  static SDL_Window* window;
  static SDL_Renderer* renderer;
  static std::vector<Sprite*> sprites;
};

#endif
