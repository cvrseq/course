cmake_minimum_required(VERSION 3.28)
project(practice)

set(CMAKE_CXX_STANDARD 26)


add_executable(practice
        main.cpp
        studentManage.cpp
        studentManage.h
        student.cpp
        student.h)