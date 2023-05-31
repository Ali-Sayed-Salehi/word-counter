cmake_minimum_required(VERSION 3.25)
project(word_counter)

set(CMAKE_CXX_STANDARD 14)

include_directories(word-counter/inc)

add_executable(word_counter
        word-counter/inc/NumList.h
        word-counter/main.cpp
        word-counter/src/NumList.cpp word-counter/src/Word.cpp word-counter/inc/Word.h word-counter/src/WordList.cpp word-counter/inc/WordList.h)
