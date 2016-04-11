#ifndef GALLOWS_H
#define GALLOWS_H

#include <cstdint>

namespace hangman {

class player {
 public:  
  explicit player(const std::int_fast32_t &lives);
  void loseOneLive();
  bool is_alive() const;

 private:
  std::int_fast32_t lives_;
};
}

#endif  // GALLOWS_H
