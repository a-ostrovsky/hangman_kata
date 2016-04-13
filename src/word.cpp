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
  word_representation r = representation();
  auto position_of_unsolved_letter = std::find(r.begin(), r.end(), boost::none);
  return position_of_unsolved_letter == r.end();
}

word_representation word::representation() const {
  word_representation result;
  for (char letter : contents_lower_case_) {
    if (is_letter_already_guessed(letter)) {
      result.push_back(letter);
    } else {
      result.push_back(boost::none);
    }
  }
  return result;
}

bool word::is_letter_in_word(const char &lower_case_letter) const {
  return contents_lower_case_.find(lower_case_letter) != std::string::npos;
}

bool word::is_letter_already_guessed(const char &lower_case_letter) const {
  return guessed_lower_case_letters_.find(lower_case_letter) !=
         guessed_lower_case_letters_.end();
}
