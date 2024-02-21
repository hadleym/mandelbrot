CC = g++
CFLAGS = -Wall
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: mandelbrot

mandelbrot: mandelbrot_window.cpp
	$(CC) $(CFLAGS) mandelbrot_window.cpp $(SFML_LIBS) -o mandelbrot

clean:
	rm -f mandelbrot

