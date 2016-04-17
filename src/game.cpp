#include <memory>
#include <boost/iostreams/filtering_stream.hpp>
#include "game.h"
#include "single_game.h"
#include "scoreboard.h"

using namespace hangman;

game::game(const std::vector<std::string> &words) : words_(words) {}

void game::play() {
  auto word_ptr = std::make_shared<word>(random_word());
  auto player_ptr = std::make_shared<player>(LIVES);

  boost::iostreams::filtering_istream input;
  input.push(std::cin);

  single_game played_game(word_ptr, player_ptr, std::cin);
  scoreboard board(word_ptr, player_ptr);
  show_score(board.stats());
  board.stats_changed.connect(boost::bind(&game::show_score, this, _1));
  played_game.play();
}

void game::show_score(const std::string &score) {
  std::cout << score << std::endl;
}

std::string game::random_word() {
  boost::random::uniform_int_distribution<size_t> distribution(
      0, words_.size() - 1);
  auto wordNumber = distribution(generator_);
  return words_[wordNumber];
}
