project(hangman)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Boost REQUIRED COMPONENTS random signals system iostreams)
cmake_minimum_required(VERSION 2.8)
add_executable(${PROJECT_NAME} ./src/main.cpp)
enable_testing()
add_subdirectory(src)
add_subdirectory(test)
target_link_libraries (hangman
                       hangman_lib
                       ${Boost_LIBRARIES}                       
                       ${CMAKE_THREAD_LIBS_INIT})
