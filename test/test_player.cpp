#include <gtest/gtest.h>
#include "player.h"

using namespace hangman;
using namespace ::testing;

TEST(player_is_alive, true_iff_player_is_alive) {
  player p(2);

  p.lose_one_live();
  EXPECT_TRUE(p.is_alive());

  p.lose_one_live();
  EXPECT_FALSE(p.is_alive());
}

TEST(player_lives, number_of_lives_left) {
  player p(2);
  EXPECT_EQ(2, p.lives());

  p.lose_one_live();
  EXPECT_EQ(1, p.lives());

  p.lose_one_live();
  EXPECT_EQ(0, p.lives());
}
