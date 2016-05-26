#ifndef WORD_H
#define WORD_H

#include <boost/optional.hpp>
#include <string>
#include <unordered_set>
#include <vector>
#include "with_observable_state.h"

namespace hangman {

using word_representation = std::vector<boost::optional<char>>;

class word : public with_observable_state {
 public:
  explicit word(const std::string &contents);
  bool guess_letter(const char &letter);
  bool is_solved() const;
  word_representation representation() const;

 private:
  bool is_letter_in_word(const char &lower_case_letter) const;
  bool is_letter_already_guessed(const char &lower_case_letter) const;
  std::string contents_lower_case_;
  std::unordered_set<char> guessed_lower_case_letters_;
};
}

#endif  // WORD_H
