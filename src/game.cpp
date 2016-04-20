#include <memory>
#include "system.h"
#include "game.h"
#include "alpha_numeric_filter.h"
#include "single_game.h"
#include "scoreboard.h"

using namespace hangman;

game::game(const std::vector<std::string> &words) : words_(words) {}

void game::play() {
  auto word_ptr = std::make_shared<word>(random_word());
  auto player_ptr = std::make_shared<player>(LIVES);
  alpha_numeric_filter alpha_numeric(std::cin);
  std::istream in(&alpha_numeric);
  single_game played_game(word_ptr, player_ptr, in);
  scoreboard board(word_ptr, player_ptr);
  show_score(board.stats());
  board.stats_changed.connect(boost::bind(&game::show_score, this, _1));
  played_game.play();
}

void game::show_score(const std::string &score) {
  system::clear_screen();
  system::print_to_coordinates(0, 0, score);
}

std::string game::random_word() {
  boost::random::uniform_int_distribution<size_t> distribution(
      0, words_.size() - 1);
  auto wordNumber = distribution(generator_);
  return words_[wordNumber];
}
