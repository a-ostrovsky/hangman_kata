#include "single_game.h"

using namespace hangman;

single_game::single_game(std::shared_ptr<word> word, std::shared_ptr<player> player,
           std::istream &user_input)
    : word_(word), gallows_(player), user_input_(user_input) {}

void single_game::guess_next_letter() {
  char next_char = static_cast<char>(user_input_.get());
  if (!word_->guess_letter(next_char)) {
    gallows_->loseOneLive();
  }
}

game_result single_game::play() {
  while (!word_->is_solved()) {
    if (!gallows_->is_alive()) {
      return game_result::lost;
    }
    guess_next_letter();
  }
  return game_result::won;
}