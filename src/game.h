#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <boost/random.hpp>

namespace hangman {

class game {
 public:
  const std::int_fast32_t LIVES = 5;
  game(const std::vector<std::string> &words);
  void play();

 private:  
  void show_score(const std::string &score);
  std::string random_word();
  std::vector<std::string> words_;
  boost::random::mt19937 generator_;
};
}

#endif  // GAME_H
