find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
include_directories (../src
                     ${GTest_LIBRARIES})
add_executable (hangman_test
                test_word.cpp
                main.cpp)
target_link_libraries (hangman_test
                       hangman_lib
                       gtest
                       ${CMAKE_THREAD_LIBS_INIT})
