cmake_minimum_required(VERSION 3.10)
project(GameRenderer VERSION 1.0)

# We want to compile this as a SHARED library so Dart FFI can load it dynamically
add_library(game_renderer SHARED src/game_renderer.c)

# Require C11 standard (good for modern C features used in olive.c)
set_target_properties(game_renderer PROPERTIES
    C_STANDARD 11
    C_STANDARD_REQUIRED YES
    POSITION_INDEPENDENT_CODE ON
)

target_compile_options(game_renderer PRIVATE -O3 -ffast-math)

# If compiling on Windows, we don't want the "lib" prefix
if(WIN32)
    set_target_properties(game_renderer PROPERTIES PREFIX "")
endif()
