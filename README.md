# framebow

## installation
git clone https://github.com/libsdl-org/SDL.git vendored/SDL
git clone https://github.com/libsdl-org/SDL_image.git vendored/SDL_image
cmake -S . -B build
cmake --build build
build/framebow
