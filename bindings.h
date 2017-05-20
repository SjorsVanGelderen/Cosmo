/*
  Copyright 2017, Sjors van Gelderen
*/

#ifndef BINDINGS_H
#define BINDINGS_H

#include <string.h>

extern "C"
{
    int __cdecl MeaningOfLife()
    {
	return 42;
    }
    
    int __cdecl StringLength(char* _message)
    {
	return strlen(_message);
    }
}

#endif
