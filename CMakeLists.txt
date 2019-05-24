cmake_minimum_required(VERSION 3.13)
project(shang_hai2)

set(CMAKE_CXX_STANDARD 11)

add_executable(shang_hai2 game.cpp Deck.cpp Deck.h Card.cpp Card.h Hand.cpp Hand.h Player.cpp Player.h Set.cpp Set.h Run.cpp Run.h)