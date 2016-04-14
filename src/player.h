#ifndef PLAYER_H
#define PLAYER_H

#include <cstdint>
#include "with_observable_state.h"

namespace hangman {

class player : public with_observable_state {
 public:
  explicit player(const std::int_fast32_t &lives);
  void lose_one_live();
  bool is_alive() const;
  std::int_fast32_t lives() const;

 private:
  std::int_fast32_t lives_;
};
}

#endif  // PLAYER_H
