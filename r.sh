#/bin/bash

echo program start

echo compile main.cpp to generate executables
g++ main.cpp -o RUN -std=c++17 

echo run the file
./RUN

echo scripts terminated