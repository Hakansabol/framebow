cmake_minimum_required(VERSION 3.16)
project(framebow)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# This assumes the SDL source is available in vendored/SDL
add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)
add_subdirectory(vendored/SDL_image EXCLUDE_FROM_ALL)


# Create your game executable target as usual
add_executable(framebow WIN32 
	main.cpp
	src/image_load.cpp
	src/file_management.cpp
)
target_include_directories(framebow PRIVATE "include")

# Link to the actual SDL3 library.
target_link_libraries(framebow PRIVATE SDL3_image::SDL3_image SDL3::SDL3)
