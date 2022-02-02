cmake_minimum_required(VERSION 3.20)
project(Cipher)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Cipher
        CaesarCipher.cpp
        CaesarCipher.h
        main.cpp)
