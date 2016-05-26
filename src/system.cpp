#include "system.h"
#include <cstdlib>
#include <iostream>

void system::print_to_coordinates(int horizontal, int vertical,
                                  const std::string& text) {
  go_to_coordinates(horizontal, vertical);
  std::cout << text << std::endl;
}

void system::go_to_coordinates(int horizontal, int vertical) {
  printf("\033[%d;%dH", horizontal, vertical);
}

void system::clear_screen() { printf("\033[2J"); }
