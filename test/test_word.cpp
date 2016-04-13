#include <gtest/gtest.h>
#include <gmock/gmock.h>
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
  auto abc = word("abc");
  EXPECT_TRUE(abc.guess_letter('a'));
  EXPECT_FALSE(abc.guess_letter('A'));
}

TEST(word_is_solved, whether_word_is_solved) {
  auto abc = word("abc");
  abc.guess_letter('a');
  EXPECT_FALSE(abc.is_solved());
  abc.guess_letter('c');
  EXPECT_FALSE(abc.is_solved());
  abc.guess_letter('b');
  EXPECT_TRUE(abc.is_solved());
}

TEST(word_representation, ordered_solved_and_unsolved_letters) {
  auto abc = word("abc");
  EXPECT_THAT(abc.representation(),
              ElementsAre(boost::none, boost::none, boost::none));
  abc.guess_letter('a');
  EXPECT_THAT(abc.representation(), ElementsAre('a', boost::none, boost::none));
  abc.guess_letter('c');
  EXPECT_THAT(abc.representation(), ElementsAre('a', boost::none, 'c'));
  abc.guess_letter('b');
  EXPECT_THAT(abc.representation(), ElementsAre('a', 'b', 'c'));
}
