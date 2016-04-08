#ifndef GALLOWS_H
#define GALLOWS_H

#include <cstdint>

namespace hangman {

class gallows {
 public:
  explicit gallows(const std::int_fast32_t &lives);
  void loseOneLive();
};
}

#endif  // GALLOWS_H
