#/bin/bash

echo program start

echo compile main.cpp to generate executables
g++ -o RUN -std=c++17 main.cpp

echo run the file
./RUN

echo scripts terminated