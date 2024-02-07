cmake_minimum_required(VERSION 3.28.0)
    
# here we specify that the project is C language only, so the default
# C compiler on the system will be used
project(screendash C)

add_executable(screendash main.c)
