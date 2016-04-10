#include "gallows.h"

using namespace hangman;

gallows::gallows(const std::int_fast32_t &lives) : lives_(lives) {}

void gallows::loseOneLive() { lives_--; }

bool gallows::is_alive() const { return lives_ > 0; }
