#include <gtest/gtest.h>
#include "player.h"

using namespace hangman;
using namespace ::testing;

TEST(player_is_alive, true_iff_player_is_alive) {
  player p(2);

  p.loseOneLive();
  EXPECT_TRUE(p.is_alive());

  p.loseOneLive();
  EXPECT_FALSE(p.is_alive());
}
