CC = g++
CFLAGS = -Wall
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: window

window: window.cpp
	$(CC) $(CFLAGS) window.cpp $(SFML_LIBS) -o window

clean:
	rm -f window

