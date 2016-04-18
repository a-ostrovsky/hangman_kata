find_package(GTest REQUIRED)
#TODO: Add gmock??
include_directories (../src
                     ${GTest_LIBRARIES})
add_executable (hangman_test                
                test_word.cpp
                test_player.cpp
                test_single_game.cpp
                test_scoreboard.cpp
                test_alpha_numeric_filter.cpp
                main.cpp)
target_link_libraries (hangman_test
                       hangman_lib
                       gtest
                       ${Boost_LIBRARIES}
                       ${CMAKE_THREAD_LIBS_INIT})
add_test(hangman_test ${CMAKE_CURRENT_BINARY_DIR}/hangman_test)
