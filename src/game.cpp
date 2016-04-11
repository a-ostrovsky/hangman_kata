#include <memory>
#include "game.h"
#include "single_game.h"
#include "word.h"    //TODO??
#include "player.h"  //TODO??

using namespace hangman;

game::game(const std::vector<std::string> &words) : words_(words) {}

void game::play() {
  auto player_ptr = std::make_shared<player>(LIVES);
  auto word_ptr = std::make_shared<word>(random_word());
  single_game played_game(word_ptr, player_ptr, std::cin);
}

std::string game::random_word() {
  boost::random::uniform_int_distribution<size_t> distribution(
      0, words_.size() - 1);
  auto wordNumber = distribution(generator_);
  return words_[wordNumber];
}
