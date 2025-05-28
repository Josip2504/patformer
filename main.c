#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <stdio.h>
#include <stdbool.h>

int main(int ac, char *av[]) {
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL init: %s\n", SDL_GetError);
		exit(1);
	}

	SDL_Window *window = SDL_CreateWindow(
		"GAME",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		800,
		600,
		SDL_WINDOW_OPENGL
	);

	if (!window) {
		printf("Failed window: %s\n", SDL_GetError());
		exit(1);
	}

	SDL_GL_CreateContext(window);
	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
		printf("Failed gl: %s\n", SDL_GetError());
		exit(1);
	}

	puts("OpenGL loaded");
	printf("Vendor: %s\n", glGetString(GL_VENDOR));
	printf("Renderer: %s\n", glGetString(GL_RENDERER));
	printf("Verison: %s\n", glGetString(GL_VERSION));

	bool sould_quit = false;
	while (!sould_quit) {
		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT:
					sould_quit = true;
					break;
				default:
					break;
			}
		}
	}
	return 0;
}
