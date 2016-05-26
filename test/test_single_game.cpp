#include <gtest/gtest.h>
#include <sstream>
#include "single_game.h"

using namespace hangman;
using namespace testing;

const std::int_fast32_t LIVES = 3;
const std::string PLAYED_WORD = "dog";

class single_game_fixture : public Test {
 public:
  std::istringstream winning_guess_seqence() {
    return std::istringstream("daog");
  }

  std::istringstream losing_guess_seqence() {
    return std::istringstream("cat");
  }

  single_game new_game(std::istream&& user_input) {
    auto word_ptr = std::make_shared<word>(PLAYED_WORD);
    auto player_ptr = std::make_shared<player>(LIVES);
    return single_game(word_ptr, player_ptr, user_input);
  }
};

TEST_F(single_game_fixture,
       single_game_play__game_result_is_won_for_winning_guess_sequence) {
  auto game = new_game(winning_guess_seqence());
  ASSERT_EQ(game_result::won, game.play());
}

TEST_F(single_game_fixture,
       single_game_play__game_result_is_lost_for_losing_guess_sequence) {
  auto game = new_game(losing_guess_seqence());
  ASSERT_EQ(game_result::lost, game.play());
}
