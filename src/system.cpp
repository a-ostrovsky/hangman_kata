#include "system.h"

void system::print_to_coordinates(int horizontal, int vertical,
                                  const std::string &text) {
  printf("\033[%d;%dH%s\n", horizontal, vertical, text.c_str());
}

void system::clear_screen() { std::system("clear"); }
