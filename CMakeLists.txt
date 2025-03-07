cmake_minimum_required(VERSION 3.25)
project(SmartBoolArray)

set(CMAKE_CXX_STANDARD 17)

add_executable(SmartBoolArray main.cpp
	SmartBoolArray.h
	SmartBoolArray.cpp
	smartBoolArrayExceptions.h
)

