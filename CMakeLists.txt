cmake_minimum_required(VERSION 3.13)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled main.cpp Deck.cpp Deck.h Card.cpp Card.h Hand.cpp Hand.h Player.cpp Player.h)