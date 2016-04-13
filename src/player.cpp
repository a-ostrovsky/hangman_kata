#include "player.h"

using namespace hangman;

player::player(const std::int_fast32_t &lives) : lives_(lives) {}

void player::lose_one_live() { lives_--; }

bool player::is_alive() const { return lives_ > 0; }

int_fast32_t player::lives() const { return lives_; }
