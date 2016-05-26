#include "scoreboard.h"
#include <boost/optional/optional_io.hpp>
#include <sstream>

using namespace hangman;

scoreboard::scoreboard(std::shared_ptr<hangman::word> word,
                       std::shared_ptr<hangman::player> player)
    : word_(word), player_(player) {
  word->state_changed.connect(
      boost::bind(&scoreboard::notify_stats_changed, this));
  player->state_changed.connect(
      boost::bind(&scoreboard::notify_stats_changed, this));
}

void scoreboard::notify_stats_changed() const { stats_changed(stats()); }

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
