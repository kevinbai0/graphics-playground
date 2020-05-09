#!/bin/bash
main_file="./src/main.cpp"
link_frameworks="-framework Cocoa -framework OpenGL -framework IOKit -framework CoreFoundation -framework CoreVideo"
link_libs="-L/usr/local/lib -lglfw3 -lGLEW"
out_file="./build/main.o"

g++ -std=c++11 $main_file $link_frameworks $link_libs -o $out_file && $out_file
