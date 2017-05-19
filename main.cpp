#include "window.h"

int main()
{
  // Set up the application
  Window::Init();
  Media::Init(Window::GetRenderer());
  Window::Loop();
  Window::Terminate();
  
  return 0;
}
