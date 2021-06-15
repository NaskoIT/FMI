cmake_minimum_required(VERSION 3.17)
project(YuGiOh)

set(CMAKE_CXX_STANDARD 14)

add_executable(YuGiOh main.cpp deck.cpp deck.hpp duelist.cpp duelist.hpp magicCard.cpp magicCard.hpp cardType.hpp monsterCard.cpp monsterCard.hpp card.hpp card.cpp pendulumCard.hpp pendulumCard.cpp)