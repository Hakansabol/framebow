#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_timer.h>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <string>
#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_video.h>

#include "include/image_load.h"

int main(int argc, char* argv[])
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool running = true;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer("framebow", 1920, 1080, 0, &window, &renderer);

	std::string path = "/home/hakan/Downloads/lwalpapers/wallpapers/b-1.jpg";
	SDL_Texture* texture = LoadAsTexture(path, renderer);
	SDL_Texture* texture2;

	int texw = texture->w;
	int texh = texture->h;

	Uint64 tick {};
	uint img_num {};

	while (running) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				running = false;
			}
		}

		tick = SDL_GetTicks();
		if (tick >= static_cast<Uint64>(img_num) * 1000) {
			img_num ++;
			path = "/home/hakan/Downloads/lwalpapers/wallpapers/b-" + std::to_string(img_num) + ".jpg";
			std::cout << tick << ' ' << path << std::endl;
			SDL_DestroyTexture(texture);
			texture = LoadAsTexture(path, renderer);

			SDL_RenderClear(renderer);
			SDL_FRect dst_rect;

			dst_rect.x = 0;
			dst_rect.y = 0;
			dst_rect.w = texw;
			dst_rect.h = texh;
			SDL_RenderTexture(renderer, texture, NULL, &dst_rect);
			SDL_RenderPresent(renderer);
		}

	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
