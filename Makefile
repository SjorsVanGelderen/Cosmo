CC=g++
CFLAGS=-c -Wall -std=c++14
LDFLAGS=-lsdl2 -lSDL2_image
SOURCES=main.cpp debug.cpp media.cpp application.cpp window.cpp sound.cpp sprite.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=run

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) -v $(CFLAGS) $< -o $@
