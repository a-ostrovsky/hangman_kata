include_directories(.)
aux_source_directory(. SRC_LIST)
list(REMOVE_ITEM SRC_LIST "./main.cpp")
add_library(hangman_lib ${SRC_LIST})
target_link_libraries (hangman_lib
                       ${Boost_LIBRARIES}                       
                       ${CMAKE_THREAD_LIBS_INIT})
