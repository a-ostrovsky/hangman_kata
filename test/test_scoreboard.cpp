#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "scoreboard.h"

using namespace testing;
using namespace hangman;

TEST(stats, solved_letters_and_lives_left) {
  auto word_ptr = std::make_shared<word>("dog");
  auto player_ptr = std::make_shared<player>(3);
  scoreboard board(word_ptr, player_ptr);
  std::string stats = board.stats();
  board.stats_changed.connect([&stats](std::string s) { stats = s; });

  EXPECT_THAT(stats, HasSubstr("---"));  // letters
  EXPECT_THAT(stats, HasSubstr("III"));  // lives
  player_ptr->lose_one_live();
  player_ptr->lose_one_live();
  EXPECT_THAT(stats, HasSubstr("I"));
  word_ptr->guess_letter('d');
  EXPECT_THAT(stats, HasSubstr("d--"));
  word_ptr->guess_letter('g');
  EXPECT_THAT(stats, HasSubstr("d-g"));
  word_ptr->guess_letter('o');
  EXPECT_THAT(stats, HasSubstr("dog"));
  player_ptr->lose_one_live();
}
