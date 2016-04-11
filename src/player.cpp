#include "player.h"

using namespace hangman;

player::player(const std::int_fast32_t &lives) : lives_(lives) {}

void player::loseOneLive() { lives_--; }

bool player::is_alive() const { return lives_ > 0; }
