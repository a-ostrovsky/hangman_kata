#ifndef GAME_H
#define GAME_H

#include <memory>
#include <istream>
#include "word.h"
#include "player.h"

namespace hangman {

enum class game_result { won, lost };

class game {
 public:
  game(std::shared_ptr<word> word, std::shared_ptr<gallows> gallows,
       std::istream &user_input);
  game_result play();

 private:
  void guess_next_letter();
  std::shared_ptr<word> word_;
  std::shared_ptr<gallows> gallows_;
  std::istream &user_input_;
};
}

#endif  // GAME_H
