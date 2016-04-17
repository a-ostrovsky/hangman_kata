#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <memory>
#include <string>
#include <boost/signals2.hpp>
#include "player.h"
#include "word.h"

namespace hangman {

class scoreboard {
 public:
  boost::signals2::signal<void(const std::string&)> stats_changed;
  scoreboard(std::shared_ptr<word> word, std::shared_ptr<player> player);
  std::string stats() const;

 private:
  void notify_stats_changed() const;
  std::string format_lives() const;
  std::string format_word() const;
  std::shared_ptr<word> word_;
  std::shared_ptr<player> player_;
};
}

#endif  // SCOREBOARD_H
