#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "scoreboard.h"

using namespace testing;
using namespace hangman;

TEST(stats, solved_letters_and_lives_left) {
    auto word_ptr = std::make_shared<word>("dog");
    auto player_ptr = std::make_shared<player>(3);
    auto board = scoreboard(player_ptr, word_ptr);
    EXPECT_THAT(board.stats(), HasSubstr("---")); //letters
    EXPECT_THAT(board.stats(), HasSubstr("III")); //lives
    player_ptr->lose_one_live();
    player_ptr->lose_one_live();
    EXPECT_THAT(board.stats(), HasSubstr("I"));
    word_ptr->guess_letter('d');
    EXPECT_THAT(board.stats(), HasSubstr("d--"));
    word_ptr->guess_letter('g');
    EXPECT_THAT(board.stats(), HasSubstr("d-g"));
    word_ptr->guess_letter('o');
    EXPECT_THAT(board.stats(), HasSubstr("dog"));
    player_ptr->lose_one_live();
}
