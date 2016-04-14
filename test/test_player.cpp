#include <gtest/gtest.h>
#include "player.h"

using namespace hangman;
using namespace testing;

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

TEST(player_state_changed, when_number_of_lives_changes) {
  bool state_change_notified = false;
  player p(2);
  p.state_changed.connect(
      [&state_change_notified]() { state_change_notified = true; });
  p.lose_one_live();
  ASSERT_TRUE(state_change_notified);
}
