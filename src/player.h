#ifndef PLAYER_H
#define PLAYER_H

#include <cstdint>

namespace hangman {

class player {
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
