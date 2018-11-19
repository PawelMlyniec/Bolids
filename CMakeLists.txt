cmake_minimum_required(VERSION 3.9)
project(Monitors)

set(CMAKE_CXX_STANDARD 11)

add_executable(Monitors main.cpp boildsMonitor.h monitor.h)