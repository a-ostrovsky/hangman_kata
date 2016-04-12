#include <iostream>
#include "game.h"

using namespace std;

int main(int argc, char *argv[])
{
    hangman::game g({"cat", "dog"});
    g.play();
}
