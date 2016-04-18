#include <memory>
#include <sstream>
#include <gtest/gtest.h>
#include "alpha_numeric_filter.h"

using namespace hangman;
using namespace testing;

class alpha_numeric_filter_fixture : public Test {
 protected:
  std::stringstream unfiltered_stream_;
  std::unique_ptr<alpha_numeric_filter> filter_;
  std::unique_ptr<std::istream> filtered_stream_;

  std::string filtered_data() {
    std::string read(std::istreambuf_iterator<char>(*filtered_stream_), {});
    return read;
  }

  void SetUp() override {
    filter_ = std::make_unique<alpha_numeric_filter>(unfiltered_stream_);
    filtered_stream_ = std::make_unique<std::istream>(&(*filter_));
  }
};

TEST_F(alpha_numeric_filter_fixture, alpha_numeric_chars_are_forwarded) {
  unfiltered_stream_ << 'a';
  ASSERT_EQ("a", filtered_data());
}

TEST_F(alpha_numeric_filter_fixture, non_alpha_numeric_chars_are_filtered) {
  unfiltered_stream_ << 'a' << '\n' << 'b';
  ASSERT_EQ("ab", filtered_data());
}
