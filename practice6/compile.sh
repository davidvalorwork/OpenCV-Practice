echo compiling...
g++ --std=c++11 index.cpp -o program `pkg-config opencv4 --cflags --libs`
