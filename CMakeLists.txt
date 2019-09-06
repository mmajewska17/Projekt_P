cmake_minimum_required(VERSION 3.13)
project(Projekt_P)

set(CMAKE_CXX_STANDARD 14)

add_executable(Projekt_P main.cpp CommandLine.cpp CommandLine.h Column.cpp Column.h Table.cpp Table.h DB.cpp DB.h templatesDB.h)