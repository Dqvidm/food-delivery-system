cmake_minimum_required(VERSION 4.1)
project(C_Project C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(C_Project
        include/file_handler.h
        include/menu.h
        include/models.h
        src/file_handler.c
        src/main.c
        src/menu.c)
