#include <sstream>
#include <boost/optional/optional_io.hpp>
#include "scoreboard.h"

using namespace hangman;

scoreboard::scoreboard(std::shared_ptr<hangman::player> player,
                       std::shared_ptr<hangman::word> word)
    : player_(player), word_(word) {}

std::string scoreboard::format_lives() const {
  return std::string(static_cast<size_t>(player_->lives()), 'I');
}

std::string scoreboard::format_word() const {
  std::stringstream word_stream;
  for (boost::optional<char> letter : word_->representation()) {
    if (letter == boost::none) {
      word_stream << '-';
    } else {
      word_stream << letter.get();
    }
  }
  return word_stream.str();
}

std::string scoreboard::stats() const {
  auto lives = format_lives();
  auto word = format_word();
  std::stringstream result_stream;
  result_stream << "Lives: " << lives << " | Word: " << word;
  return result_stream.str();
}