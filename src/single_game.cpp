#include "single_game.h"

using namespace hangman;

game::game(std::shared_ptr<word> word, std::shared_ptr<gallows> gallows,
           std::istream &user_input)
    : word_(word), gallows_(gallows), user_input_(user_input) {}

void game::guess_next_letter() {
  char next_char = static_cast<char>(user_input_.get());
  if (!word_->guess_letter(next_char)) {
    gallows_->loseOneLive();
  }
}

game_result game::play() {
  while (!word_->is_solved()) {
    if (!gallows_->is_alive()) {
      return game_result::lost;
    }
    guess_next_letter();
  }
  return game_result::won;
}
