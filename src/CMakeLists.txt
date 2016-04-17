include_directories(.)
add_library(hangman_lib
            with_observable_state.h
            player.cpp
            single_game.cpp
            game.cpp
            word.cpp            
            scoreboard.cpp
            main.cpp)
target_link_libraries (hangman_lib
                       ${Boost_LIBRARIES}
                       ${CMAKE_THREAD_LIBS_INIT})
