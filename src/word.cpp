#include "word.h"

using namespace hangman;

word::word(const std::string &contents) : contents_(contents) {}

bool word::has_letter(const char &letter) const
{
    return contents_.find(letter) != std::string::npos;
}
