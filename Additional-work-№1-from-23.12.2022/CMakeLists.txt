cmake_minimum_required(VERSION 3.23)
project(zwork C)

set(CMAKE_C_STANDARD 99)

add_executable(zwork main.c list.c list.h doptask.c)
