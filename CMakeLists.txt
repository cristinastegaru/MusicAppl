# CMake version
cmake_minimum_required(VERSION 3.0)

# Project name
project(MusicApp)

# Specify the required C++ standard
if(CMAKE_VERSION GREATER "3.1.2")
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
else()
    if(CMAKE_COMPILER_IS_GNUCXX)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
    endif()
endif()

# Define the executable
add_executable(${PROJECT_NAME}
               src/Artist_class.cpp
               src/Song_class.cpp
               src/User.cpp
               src/MusicApp.cpp
               src/Artist_class.hpp
               src/Song_class.hpp
               src/User.hpp
               src/MusicApp_class.hpp)
