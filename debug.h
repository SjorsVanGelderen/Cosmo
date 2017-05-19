/*
  Copyright 2017, Sjors van Gelderen
*/

#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <string>

enum LogLevel
  {
    INFO,
    WARNING,
    ERROR
  };

class Debug
{
 public: 
  static void Log(LogLevel _level, std::string _message);
};

#endif
