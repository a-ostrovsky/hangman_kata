#ifndef ALPHA_NUMERIC_FILTER_H
#define ALPHA_NUMERIC_FILTER_H

#include <streambuf>

namespace hangman {

class alpha_numeric_filter : public std::streambuf {
 public:
  alpha_numeric_filter(std::istream &input);
  std::streambuf::int_type underflow() override;

 private:
  std::istream &input_;
};
}

#endif  // ALPHA_NUMERIC_FILTER_H
