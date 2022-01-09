cmake_minimum_required(VERSION 3.17)
project(binrar-topicos)

set(CMAKE_CXX_STANDARD 17)

add_executable(binrar-topicos main.cpp Interface.cpp Interface.hpp Compressor.cpp Compressor.hpp)