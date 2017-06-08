CC=g++
CFLAGS=-c -Wall -std=c++14 -dynamiclib
LDFLAGS=-lsdl2 -lSDL2_image
SOURCES= \
main.cpp \
debug.cpp \
application.cpp \
window.cpp \
drawing.cpp \
bindings.cpp \
#media.cpp \
#sprite.cpp \
#math.cpp \
#sync.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Cosmo.dylib

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) -v $(CFLAGS) $< -o $@
