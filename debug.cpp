/*
  Copyright 2017, Sjors van Gelderen
*/

#include "debug.h"

void Debug::Log(LogLevel _level, std::string _message)
{
    switch(_level)
    {
    case INFO:
	std::cerr << "INFO: ";
	break;

    case WARNING:
	std::cerr << "WARNING: ";
	break;

    case ERROR:
	std::cerr << "ERROR: ";
	break;
    }
  
    std::cerr
	<< _message
	<< std::endl;
}
