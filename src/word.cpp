#include "word.h"
#include <boost/algorithm/string.hpp>

using namespace hangman;

word::word(const std::string &contents)
    : contents_lower_case_(boost::algorithm::to_lower_copy(contents)) {}

bool word::guess_letter(const char &letter) {
  char lower_case_letter = static_cast<char>(std::tolower(letter));
  if (is_letter_already_guessed(lower_case_letter)) {
    return false;
  }
  guessed_lower_case_letters_.insert(lower_case_letter);
  return is_letter_in_word(lower_case_letter);
}

bool word::is_solved() const {
  for (char letter : contents_lower_case_) {
    if (!is_letter_already_guessed(letter)) {
      return false;
    }
  }
  return true;
}

bool word::is_letter_in_word(const char &lower_case_letter) const {
  return contents_lower_case_.find(lower_case_letter) != std::string::npos;
}

bool word::is_letter_already_guessed(const char &lower_case_letter) const {
  return guessed_lower_case_letters_.find(lower_case_letter) !=
         guessed_lower_case_letters_.end();
}
