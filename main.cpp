#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_timer.h>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>
#include <iterator>
#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_video.h>

#include "config.h"
#include "include/image_load.h"
#include "file_management.h"

vector<string>* imgpaths = nullptr;
int main(int argc, char *argv[])
{
	int i = 1;
	while (i < argc) {
		std::string arg = argv[i];
		if (*arg.c_str() == '-') { // if its an argument like `-a` or `-c`
			cout << "argument seen! " << arg << endl;
		}
		else {
			std::string path = argv[1];
			std::cout << "path " << path << std::endl;

			imgpaths = BuildImageList(path, imgpaths == nullptr);
		}
		i ++;
	}
	if (imgpaths == nullptr) {
		cout << "No folders indicated!" << endl;
		return 0;
	}

	SDL_Window* window;
	SDL_Renderer* renderer;
	bool running = true;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer("framebow", 1920, 1080, 0, &window, &renderer);

	std::string path = "/home/hakan/Downloads/lwalpapers/wallpapers/b-1.jpg";
	SDL_Texture* texture = LoadAsTexture(path, renderer);
	SDL_Texture* texture2;

	Uint64 tick {};
	uint img_num {};
	uint random_pointer {};

	uint lt {};
	uint ticksPerImage = 10;
	while (running) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				running = false;
			}
		}

		tick = SDL_GetTicks();
		if (tick >= static_cast<Uint64>(img_num) * ticksPerImage) {
			// ordered
			if (RANDOM_ORDER) {
				// get the new image
				const auto imgcount = imgpaths->size();
				uint rval = rand() % (imgcount - (img_num % imgcount));
				path = (*imgpaths)[rval];
				
				// swap image with end of list to prevent duplicates
				uint eval = imgcount - (img_num % imgcount) - 1;
				string temp = (*imgpaths)[rval];
				cout << imgcount << ' ' << rval << ' ' << eval << endl;
				(*imgpaths)[rval] = (*imgpaths)[eval];
				(*imgpaths)[eval] = temp;
			}
			else
			{
				path = (*imgpaths)[img_num];
			}
			img_num ++;

			SDL_DestroyTexture(texture);
			texture = LoadAsTexture(path, renderer);

			SDL_RenderClear(renderer);
			SDL_FRect dst_rect;

			dst_rect.x = 0;
			dst_rect.y = 0;
			SDL_GetTextureSize(texture, &dst_rect.w, &dst_rect.h);
			SDL_RenderTexture(renderer, texture, NULL, &dst_rect);
			SDL_RenderPresent(renderer);
			std::cout << tick << ' ' << tick - lt << ' ' << path << std::endl;
			lt = tick;
		}

		SDL_Delay(ticksPerImage);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
