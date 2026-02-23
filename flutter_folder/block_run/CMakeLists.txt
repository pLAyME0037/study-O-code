cmake_minimum_required(VERSION 3.10)
project(runner LANGUAGES C CXX)

add_library(game_renderer SHARED src/game_renderer.c)

set_target_properties(game_renderer PROPERTIES
    C_STANDARD 11
    C_STANDARD_REQUIRED YES
    POSITION_INDEPENDENT_CODE ON
)

target_compile_options(game_renderer PRIVATE -O3 -ffast-math)

set_target_properties(game_renderer PROPERTIES
    LINKER_LANGUAGE C
    PREFIX "lib"
    SUFFIX ".so"
    OUTPUT_NAME "game_renderer"
)

add_dependencies(${BINARY_NAME} game_renderer)

install(TARGETS game_renderer
    LIBRARY DESTINATION "${INSTALL_BUNDLE_LIB_DIR}"
    COMPONENT Runtime
)
# If compiling on Windows, we don't want the "lib" prefix
if(WIN32)
    set_target_properties(game_renderer PROPERTIES PREFIX "")
endif()

# !rm -rf build/ && cmake -S . -B build && cmake --build build
