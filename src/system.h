#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

class system {
 public:
  static void print_to_coordinates(int horizontal, int vertical,
                                   const std::string &text);
  static void clear_screen();
};

#endif  // SYSTEM_H
