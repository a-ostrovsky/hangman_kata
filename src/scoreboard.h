#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <memory>
#include <string>
#include "player.h"
#include "word.h"

namespace hangman {

class scoreboard {
 public:
  scoreboard(std::shared_ptr<player> player, std::shared_ptr<word> word);
  std::string stats() const;

 private:
  std::string format_lives() const;
  std::string format_word() const;
  std::shared_ptr<player> player_;
  std::shared_ptr<word> word_;

};
}

#endif  // SCOREBOARD_H
