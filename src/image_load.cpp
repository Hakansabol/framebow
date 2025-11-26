#include "image_load.h"

#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_render.h>
#include <string>
#include <SDL3/SDL_surface.h>
#include <SDL3_image/SDL_image.h>

SDL_Surface* LoadAsSurface(std::string path) {
	SDL_Surface* s = IMG_Load(path.c_str());
	return s;
}
SDL_Texture* LoadAsTexture(std::string path, SDL_Renderer* renderer) {
	SDL_Texture* t = IMG_LoadTexture(renderer, path.c_str());
	return t;
}
