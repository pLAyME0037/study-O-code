#!/usr/bin/env bash

CFLAG="-Wall -Wextra -ggdb"
RAYLIB="modules/raylib-6.0/lib/libraylib.a -Imodules/raylib-6.0/include"
CLIB="-lm -lpthread -ldl -lrt -lX11"

mkdir -p bin/

if [[ -e "bin/main" ]]; then
    rm bin/main
fi

gcc main.c $CFLAG $RAYLIB $CLIB -o bin/main

./bin/main
