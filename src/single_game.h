#ifndef SINGLE_GAME_H
#define SINGLE_GAME_H

#include <memory>
#include <istream>
#include "word.h"
#include "player.h"

namespace hangman {

enum class game_result { won, lost };

class single_game {
 public:
  single_game(std::shared_ptr<word> word, std::shared_ptr<player> player,
       std::istream &user_input);
  game_result play();

 private:
  void guess_next_letter();
  std::shared_ptr<word> word_;
  std::shared_ptr<player> gallows_;
  std::istream &user_input_;
};
}

#endif  // SINGLE_GAME_H
