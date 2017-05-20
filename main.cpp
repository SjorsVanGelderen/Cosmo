/*
  Copyright 2017, Sjors van Gelderen
*/

#include "application.h"

int main()
{
    // Set up the application
    Application::Init();

    // Perform the main application loop
    Application::Loop();

    // Terminate the application
    Application::Terminate();
  
    return 0;
}
