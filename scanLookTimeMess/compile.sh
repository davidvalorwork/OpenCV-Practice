clear
echo compiling..
g++ -std=c++11 index.cpp -o exect `pkg-config opencv4 --cflags --libs`
