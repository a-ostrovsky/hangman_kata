#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "word.h"

using namespace hangman;
using namespace ::testing;

TEST(word_guess_letter, for_single_guess_returns_whether_letter_is_in_word) {
  EXPECT_TRUE(word("abc").guess_letter('a'));
  EXPECT_TRUE(word("abc").guess_letter('A'));
  EXPECT_FALSE(word("abc").guess_letter('z'));
}

TEST(word_guess_letter,
     for_subsequent_guesses_returns_whether_letter_is_still_in_word) {
  word abc("abc");
  EXPECT_TRUE(abc.guess_letter('a'));
  EXPECT_FALSE(abc.guess_letter('A'));
}

TEST(word_is_solved, whether_word_is_solved) {
  word abc("abc");
  abc.guess_letter('a');
  EXPECT_FALSE(abc.is_solved());
  abc.guess_letter('c');
  EXPECT_FALSE(abc.is_solved());
  abc.guess_letter('b');
  EXPECT_TRUE(abc.is_solved());
}

TEST(word_representation, ordered_solved_and_unsolved_letters) {
  word abc("abc");
  EXPECT_THAT(abc.representation(),
              ElementsAre(boost::none, boost::none, boost::none));
  abc.guess_letter('a');
  EXPECT_THAT(abc.representation(), ElementsAre('a', boost::none, boost::none));
  abc.guess_letter('c');
  EXPECT_THAT(abc.representation(), ElementsAre('a', boost::none, 'c'));
  abc.guess_letter('b');
  EXPECT_THAT(abc.representation(), ElementsAre('a', 'b', 'c'));
}

TEST(word_state_changed, when_a_letter_is_guessed) {
  bool state_change_notified = false;
  word abc("abc");
  abc.state_changed.connect(
      [&state_change_notified]() { state_change_notified = true; });
  abc.guess_letter('a');
  ASSERT_TRUE(state_change_notified);
}
