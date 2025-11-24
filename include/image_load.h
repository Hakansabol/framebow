#ifndef IMGLOAD
#define IMGLOAD

#include <string>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>


SDL_Surface* LoadAsSurface(std::string path);
SDL_Texture* LoadAsTexture(std::string path, SDL_Renderer* renderer);

#endif
