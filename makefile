CC = gcc
SDL_CFLAGS = `sdl2-config --cflags`
SDL_LIBS = `sdl2-config --libs`
DEBUG_FLAGS = -g -Wall -Werror

all: ./bin/snake

./bin/snake: ./bin/main.o
	${CC} ${DEBUG_FLAGS} $^ -o $@ ${SDL_LIBS} 

./bin/main.o: ./src/main.c 
	${CC} ${DEBUG_FLAGS} -c $^ -o $@ ${SDL_CFLAGS} 

clean:
	rm ./bin/*

.PHONY:
	all clean