#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_video.h>

int main(int argc, char* argv[])
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool running = true;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer("framebow", 640, 480, 0, &window, &renderer);

	while (running) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				running = false;
			}
		}

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
