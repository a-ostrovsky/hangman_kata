#ifndef WORD_H
#define WORD_H

#include <string>

namespace hangman {

class word {
 public:
  explicit word(const std::string &contents);
  bool has_letter(const char &letter) const;

 private:
  std::string contents_;
};
}

#endif  // WORD_H
