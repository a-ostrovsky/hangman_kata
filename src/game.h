#ifndef GAME_H
#define GAME_H

#include <boost/random.hpp>
#include <string>
#include <vector>

namespace hangman {

class game {
 public:
  const std::int_fast32_t LIVES = 5;
  game(const std::vector<std::string> &words);
  void play();

 private:
  static void show_score(const std::string &score);
  static void go_to_letter_input_position();
  std::string random_word();
  std::vector<std::string> words_;
  boost::random::mt19937 generator_;
};
}

#endif  // GAME_H
