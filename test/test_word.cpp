#include <gtest/gtest.h>
#include "word.h"

using namespace hangman;
using namespace ::testing;

TEST(has_letter, whether_letter_is_in_word) {
  auto abc = word("abc");
  EXPECT_TRUE(abc.has_letter('a'));
  EXPECT_TRUE(abc.has_letter('A'));
  EXPECT_FALSE(abc.has_letter('z'));
}
