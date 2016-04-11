#include <gtest/gtest.h>
#include "player.h"

using namespace hangman;
using namespace ::testing;

TEST(gallows_is_alive, true_iff_player_is_alive) {
  gallows g(2);

  g.loseOneLive();
  EXPECT_TRUE(g.is_alive());

  g.loseOneLive();
  EXPECT_FALSE(g.is_alive());
}
