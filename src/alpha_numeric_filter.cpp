#include <istream>
#include "alpha_numeric_filter.h"

using namespace hangman;

alpha_numeric_filter::alpha_numeric_filter(std::istream &input)
    : input_(input) {}

std::streambuf::int_type alpha_numeric_filter::underflow() {
  int read_data = input_.get();
  if (read_data == std::char_traits<char>::eof()) {
    return std::char_traits<char>::eof();
  }
  char read_char = std::char_traits<char>::to_char_type(read_data);
  if (!std::isalnum(read_char)) {
    return underflow();
  }
  this->setg(&read_char, &read_char, &read_char + 1);
  return read_data;
}
